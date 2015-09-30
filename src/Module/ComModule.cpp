#include "ComModule.h"

//Breaking circles references
#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
#include "GlobalModule.h"
#include "PolyboxModule.h"

ComModule* ComModule::_instance = NULL;
QMap<int, QString> ComModule::connectionStatusMessage;

ComModule* ComModule::getInstance(QObject *parent)
{
    if ( _instance == NULL )
    {
        _instance = new ComModule( parent );
    }
    return _instance;
}

ComModule::ComModule(QObject *parent) :
    QObject(parent)
{
    _numberOfCommandReceived = 0;
    _numberOfCommandSend = 0;
    _connectionUptime = 0;
    _currentLineNumber = 0;
    _connectionFlag = Unconnected;
    _numberOfMissingPingPong = 0;

    connect( &_pingPongTimer, SIGNAL(timeout()), this, SLOT(pingPong()));
    connect( &_sendTimer, SIGNAL(timeout()), this, SLOT(sendBufferedData()));
    connect(Polyplexer::getInstance(), SIGNAL(dataPolyboxReady(QByteArray)), this, SLOT(parseData()));

    initConnectionStatusMessage();

}


void ComModule::parseData()
{
    _numberOfCommandReceived++;
    QByteArray datas = Polyplexer::getInstance()->dataPolybox();
    QString str(datas);
    QStringList datas_listed = str.split("#", QString::SkipEmptyParts );
    QByteArray stream;
    foreach ( QString current_mcode, datas_listed )
    {
        stream = current_mcode.toStdString().c_str();
        this->parseMCode( stream );
        PolyboxModule::getInstance()->cncModule()->parseMCode( stream );
        PolyboxModule::getInstance()->globalModule()->parseMCode( stream );
        PolyboxModule::getInstance()->scannerModule()->parseMCode( stream );
        PolyboxModule::getInstance()->printerModule()->parseMCode( stream );
        emit newData( stream );

    }

}

void ComModule::initConnectionStatusMessage()
{
    connectionStatusMessage.insert( Polyplexer::Connected, tr("Le logiciel est correctement connecté à la machine. "));
    connectionStatusMessage.insert( Polyplexer::ErrorPolyplexer, tr("Impossible de se connecter à la machine.\n Erreur au lancement du sous-programme Polyplexer. \n 0xff30'"));
    connectionStatusMessage.insert( Polyplexer::ErrorConnection, tr("Impossible de se connecter à la machine.\n Error 0xff34'"));
    connectionStatusMessage.insert( Polyplexer::Permission, tr("Erreur au lancement. Verifiez vos droits"));
    connectionStatusMessage.insert( Polyplexer::NotFound, tr("Programme non trouvable"));
    connectionStatusMessage.insert( Polyplexer::TimeOut, tr("La machine ne repond pas...\n Error 0xff34'"));
}


bool ComModule::isConnected()
{
    return Polyplexer::isConnected() && (ComModule::getInstance()->_connectionFlag == Connected);
}

Polyplexer::ConnectionStatus ComModule::connectionGUI(bool blocked_thread)
{
 Polyplexer::ConnectionStatus connection_status = this->connection( blocked_thread);
 switch (connection_status) {
 case Polyplexer::Connected:
     MainWindow::textWindow( this->connectionStatusMessage.value(connection_status) );
     break;
 default:
     MainWindow::errorWindow( this->connectionStatusMessage.value(connection_status) );
     break;
 }
 return connection_status;
}

void ComModule::stopConnection()
{
//    Polyplexer::getInstance()->stop();

    _connectionUptime = 0;
    _currentLineNumber = 0;
    _numberOfMissingPingPong = 0;
    _connectionFlag = Unconnected;
}

void ComModule::beginConnection()
{
    ClosedLoopTimer loop;
    loop.startClosedLoop( 500 );
    _currentLineNumber = 0;
    _sendBuffer.clear();
    _sendTimer.start( Config::sendBufferTimer() );
    ComModule::getInstance(this)->sendMCode( MCODE_RESET_LINE_NUMBER );
    //ComModule::getInstance(this)->sendMCode( MCODE_RESET_SLAVES );

    loop.startClosedLoop( 500 );

    ComModule::getInstance(this)->sendMCode( MCODE_START_CONNECTION );

    loop.startClosedLoop( 1000 );


    _numberOfMissingPingPong = 0;
    _connectionFlag = Unconnected;
    _pingPongTimer.start( PINGPONG_DELAY_MS );
    PolyboxModule::getInstance()->globalModule()->resetError();

}

Polyplexer::ConnectionStatus ComModule::checkPingPongConnection()
{
    // We need to wait the end of ping/pong process. It's an closed loop, we process QtEvent and check if the connection is active
    ClosedLoopTimer closed_loop;
    if ( closed_loop.startClosedLoop( Config::connectionUptimeDelay()*PINGPONG_MAX_TRIES+(Config::connectionUptimeDelay()*2), ComModule::isConnected ))
    {
        Logger::startConnection( true );
        return Polyplexer::Connected;
    }
    else
    {
        Logger::startConnection( false );
        return Polyplexer::TimeOut;
    }
}

Polyplexer::ConnectionStatus ComModule::connection(bool blocked_thread)
{
    Polyplexer::ConnectionStatus code = Polyplexer::getInstance()->start( Polyplexer::Serial );
    if ( code == Polyplexer::Connected )
    {
        beginConnection();

        if ( blocked_thread )
        {
            checkPingPongConnection();
        }
        else
        {
            Logger::startConnection( true );
            return Polyplexer::Connected;
        }
    }
    return code;
}

void ComModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    switch ( value )
    {
    case MCODE_PING_PONG:
    {
        _numberOfMissingPingPong = 0;
        _connectionFlag = Connected;
    }
        break;
    default:
        break;
    }
}


void ComModule::pingPong()
{
    if ( Polyplexer::isConnected() )
    {
        if ( (_numberOfMissingPingPong > PINGPONG_MAX_TRIES) )
        {
            /*if ( _connectionFlag == Connected )
            {*/
                if ( Config::decoWhenPingPongOff() )
                {
                    _connectionUptime = 0;
                    this->_sendBuffer.clear();
                    _connectionFlag = Unconnected;
                    Polyplexer::getInstance()->disconnect();
                    MainWindow::errorWindow( tr("Une erreur est survenue. La machine ne répond plus aux messages depuis un certain temps.\n Deconnection.\n Veuillez vous reconnecter"));
                }
                else
                {
                    //MainWindow::errorWindow( tr("Une erreur est survenue. La machine ne répond plus aux messages depuis un certain temps.\n"));
                }
                _numberOfMissingPingPong = 0;

            /*}
            else
            {

            }*/
        }
        else
        {
            _connectionUptime+= (_pingPongTimer.interval()/1000);
            _numberOfMissingPingPong++;
            sendMCode( MCODE_PING_PONG );
        }
    }
    else
    {

    }
}



void ComModule::sendBufferedData()
{
    /** Is Connected ? **/
    if ( Polyplexer::isConnected() )
    {
        if ( ! _sendBuffer.isEmpty() )
        {
            QString data = _sendBuffer.dequeue();
            // Add checksum
            data = data + "*" + QString::number(ComModule::checksum(data.toStdString().c_str(), data.size()));

            Logger::writeOutputCommand( data );
            Polyplexer::send( data );
            _numberOfCommandSend++;
            emit dataWritten( data );
        }
    }
    else
    {
        _sendBuffer.clear();
    }
}

void ComModule::sendCode(QString code)
{
    if ( Polyplexer::isConnected() )
    {
        if ( _sendBuffer.size() <= Config::sendBufferSize() )
        {
            _currentLineNumber++;
            // Add line number
            code = "#N"+QString::number(_currentLineNumber) + " " + code + " ";
            _sendBuffer.enqueue( code );
        }
        else
        {
            Logger::write("Buffer Full\n");
        }
    }
}


void ComModule::sendMCode(int code)
{
    sendMCode( QString::number(code) );
}
void ComModule::sendMCode(QString code)
{
    code = "M"+code;
    this->sendCode( code );
}

