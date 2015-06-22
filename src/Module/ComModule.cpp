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
    _connectionUptime = 0;

    _numberOfMissingPingPong = PINGPONG_NOT_CONNECTED;
    _pingPongTimer.start( PINGPONG_DELAY_MS );
    connect( &_pingPongTimer, SIGNAL(timeout()), this, SLOT(pingPong()));

    initConnectionStatusMessage();


    /*
     *     connect ( _connector, SIGNAL(readyRead()), this, SLOT(parseSerialDatas()) );
    this->connectionUptime = 0 ;
    this->_currentLineNumber = 0;
    this->sendMCode( MCODE_RESET_SLAVES );
    this->_currentLineNumber = 0;
    this->sendMCode( MCODE_RESET_LINE_NUMBER );*/
}


void ComModule::parseData()
{
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
    connectionStatusMessage.insert( ComModule::Connected, tr("Le logiciel est correctement connecté à la machine. "));
    connectionStatusMessage.insert( ComModule::ErrorPolyplexer, tr("Impossible de se connecter à la machine.\n Erreur au lancement du sous-programme Polyplexer. \n 0xff30'"));
    connectionStatusMessage.insert( ComModule::ErrorConnection, tr("Impossible de se connecter à la machine.\n Error 0xff34'"));
    connectionStatusMessage.insert( ComModule::Permission, tr("Erreur au lancement. Verifiez vos droits"));
    connectionStatusMessage.insert( ComModule::NotFound, tr("Programme non trouvable"));
    connectionStatusMessage.insert( ComModule::TimeOut, tr("La machine ne repond pas...\n Error 0xff34'"));
}



void ComModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );

    switch ( value )
    {
    case MCODE_PING_PONG:
    {
        _numberOfMissingPingPong = PINGPONG_OK;
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
        _numberOfMissingPingPong++;
        sendMCode( MCODE_PING_PONG );
        // too much missing ping/pong or still not connected status (when just connected and waiting for 1st pong back)
        if ( _numberOfMissingPingPong > PINGPONG_MAX_TRIES && _numberOfMissingPingPong > PINGPONG_NOT_CONNECTED+PINGPONG_MAX_TRIES )
        {
            if ( _numberOfMissingPingPong < PINGPONG_NOT_CONNECTED )
            {
                MainWindow::errorWindow( tr("Une erreur est survenue. La machine ne répond plus aux messages depuis un certain temps.\n Veuillez vous reconnecter.\n"));
            }
            _numberOfMissingPingPong = PINGPONG_NOT_CONNECTED;
            Polyplexer::getInstance()->disconnect();
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
            data = data + "*" + QString::number(ComModule::checksum(data.toStdString().c_str(), data.size())) + "\n";

            Logger::writeOutputCommand( data );
            Polyplexer::send( data );
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

