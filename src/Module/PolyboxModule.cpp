#include "PolyboxModule.h"

//Breaking circles references
#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
#include "GlobalModule.h"
#include <QDebug>

#define PINGPONG_NOT_CONNECTED     42
#define PINGPONG_MAX_TRIES         2
#define PINGPONG_OK                0
#define PINGPONG_DELAY_MS          4000

PolyboxModule* PolyboxModule::polyboxModuleInstance = NULL;
QJoystick* PolyboxModule::_joypad=NULL;
QMap<int, QString> PolyboxModule::connectionStatusMessage;

PolyboxModule* PolyboxModule::getInstance(QObject *parent)
{
    if ( polyboxModuleInstance == NULL )
    {
        polyboxModuleInstance = new PolyboxModule( parent );
    }
    return polyboxModuleInstance;
}

PolyboxModule::ConnectorType PolyboxModule::connectorType() const
{
    return _connectorType;
}
void PolyboxModule::setConnectorType(ConnectorType type)
{
    _connectorType = type;
    if ( type == ServerTCP)
    {

    }
    else if ( type == CLientTCP)
    {

    }
    else //if ( type == Serial)
    {

    }
    emit( newType(type));
}

void PolyboxModule::initConnectionStatusMessage()
{
    connectionStatusMessage.insert( PolyboxModule::Connected, tr("Le logiciel est correctement connecté à la machine. "));
    connectionStatusMessage.insert( PolyboxModule::ErrorPolyplexer, tr("Impossible de se connecter à la machine.\n Erreur au lancement du sous-programme Polyplexer. \n 0xff30'"));
    connectionStatusMessage.insert( PolyboxModule::ErrorConnection, tr("Impossible de se connecter à la machine.\n Error 0xff34'"));
    connectionStatusMessage.insert( PolyboxModule::Permission, tr("Erreur au lancement. Verifiez vos droits"));
    connectionStatusMessage.insert( PolyboxModule::NotFound, tr("Programme non trouvable"));
    connectionStatusMessage.insert( PolyboxModule::TimeOut, tr("La machine ne repond pas...\n Error 0xff34'"));
}

PolyboxModule::PolyboxModule(QObject *parent) :
    QObject(parent)
{
    _connector = NULL ;
    _connected = false;
    _numberOfMissingPingPong = PINGPONG_NOT_CONNECTED;

    initConnectionStatusMessage();
    this->setConnector( SerialPort::getSerial(), Serial );
    _polyplexer = Polyplexer::getInstance();
    connect ( _connector, SIGNAL(dataReady()), this, SLOT(parseData()) );


    _cnc = new CNCModule( this, this );
    _labview = new LabViewModule( this );
    _printer = new PrinterModule( this, this);
    _scanner = new ScannerModule( this, this);
    _global = new GlobalModule( this, this );

    _hardwareTimer.start( Config::hardwareTimer() );
    connect( &_hardwareTimer, SIGNAL(timeout()), this, SLOT(hardwareTimerTimeout()));
    _pingPongTimer.start( PINGPONG_DELAY_MS );
    connect( &_pingPongTimer, SIGNAL(timeout()), this, SLOT(pingPong()));


}

void PolyboxModule::setConnector(AbstractClient *connector, ConnectorType type)
{
    if ( _connector != NULL )
    {
        delete _connector;
    }
    _connectorType =  type;
    _connector = connector;
}

void PolyboxModule::setupConnection(QString path, QString port)
{
    _polyplexer->setPathMachine(path);
    _polyplexer->setPortMachine(port);
}

PolyboxModule::ConnectionStatus PolyboxModule::connectionGUI(bool blocked_thread)
{
 ConnectionStatus connection_status = this->connection( blocked_thread);
 switch (connection_status) {
 case Connected:
     MainWindow::textWindow( this->connectionStatusMessage.value(connection_status) );
     break;
 default:
     MainWindow::errorWindow( this->connectionStatusMessage.value(connection_status) );
     break;
 }
 return connection_status;
}


int PolyboxModule::error()
{
    if ( this->_polyplexer != NULL )
    {
        return this->_polyplexer->error();
    }
    return 99;
}

PolyboxModule::ConnectionStatus PolyboxModule::connection( bool blocked_thread)
{
    _connected = _polyplexer->start();
    if ( _connected )
    {
        _numberOfMissingPingPong = PINGPONG_NOT_CONNECTED;
        SerialPort* con = dynamic_cast<SerialPort*>( _connector );
        /** Start VirtualSerial Connexion **/
        _connected = con->connectToSerialPort() ;

        if ( _connected && _connector->isConnected()  )
        {
            QTimer* timer_connect = new QTimer(this);
            connect( timer_connect, SIGNAL(timeout()), _labview, SLOT(setConnectedColor()) );
            timer_connect->setSingleShot(true);
            timer_connect->start( 1000 );

            if ( blocked_thread )
            {
                /** We need to wait the end of ping/pong process. It's an closed loop, we process QtEvent and check if the connection is active **/
                ClosedLoopTimer closed_loop;
                if ( closed_loop.startClosedLoop( 15000, PolyboxModule::isConnected ))
                {
                    Logger::startConnection( true );
                    return Connected;
                }
                else
                {
                    Logger::startConnection( false );
                    return TimeOut;
                }
            }
            else
            {
                Logger::startConnection( true );
                return Connected;
            }
        }
        else
        {
            return ErrorConnection;
        }
    }
    else
    {
        return ErrorPolyplexer;
    }
    return ErrorPolyplexer;
}


void PolyboxModule::hardwareTimerTimeout()
{
    emit updateHardware();
}

void PolyboxModule::parseData()
{
    QByteArray datas = PolyboxModule::getInstance()->connector()->datas();//_polyplexer->printerDatas();
    QString str(datas);
    /*int start_idx = 0;
    int idx = str.indexOf( start_idx,'#') ;*/
    QStringList datas_listed = str.split("#", QString::SkipEmptyParts );
    QByteArray stream;
    foreach ( QString current_mcode, datas_listed )
    {
        stream = current_mcode.toStdString().c_str();
        this->parseMCode( stream );
        _cnc->parseMCode( stream );
        _global->parseMCode( stream );
        _scanner->parseMCode( stream );
        _printer->parseMCode( stream );
        emit newData( stream );
    }

}

void PolyboxModule::parseMCode(QByteArray stream)
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

void PolyboxModule::pingPong()
{
    if ( _connector->isConnected() )
    {
        _numberOfMissingPingPong++;
        _connector->sendMCode( MCODE_PING_PONG );
        // too much missing ping/pong or still not connected status (when just connected and waiting for 1st pong back)
        if ( _numberOfMissingPingPong > PINGPONG_MAX_TRIES && _numberOfMissingPingPong > PINGPONG_NOT_CONNECTED+PINGPONG_MAX_TRIES )
        {
            if ( _numberOfMissingPingPong < PINGPONG_NOT_CONNECTED )
            {
                MainWindow::errorWindow( tr("Une erreur est survenue. La machine ne répond plus aux messages depuis un certain temps.\n Veuillez vous reconnecter.\n"));
            }
            _numberOfMissingPingPong = PINGPONG_NOT_CONNECTED;
            _polyplexer->stop();
        }
    }
    else
    {

    }

}

bool PolyboxModule::loadJoypad()
{
    if ( _joypad == NULL )
    {
        _joypad = QJoystickEnumerator::enumerate("/dev/input/");
    }
    return   ( _joypad != NULL);
}
void PolyboxModule::unloadJoypad()
{
    if ( _joypad != NULL)
    {
        //_joypad->deleteLater();
        //_joypad = NULL;
    }
}
QJoystick* PolyboxModule::getJoypad()
{
    return _joypad;
}

void PolyboxModule::setJoypad( QJoystick* joypad )
{
    _joypad = joypad;
}

AbstractClient* PolyboxModule::connector()
{
    return _connector;
}

GlobalModule* PolyboxModule::globalModule()
{
    return _global;
}
LabViewModule* PolyboxModule::labViewModule()
{
    return _labview;
}
CNCModule* PolyboxModule::cncModule()
{
    return _cnc;
}
ScannerModule* PolyboxModule::scannerModule()
{
    return _scanner;
}
PrinterModule* PolyboxModule::printerModule()
{
    return _printer;
}

bool PolyboxModule::isConnected()
{
    return PolyboxModule::getInstance()->_connected && PolyboxModule::getInstance()->_connector->isConnected() && PolyboxModule::getInstance()->_numberOfMissingPingPong <= PINGPONG_MAX_TRIES;
}

bool PolyboxModule::isCommonReady()
{
    return _global->isReady();
}

bool PolyboxModule::isCncReady()
{
    return ( false && this->isConnected() && this->isCommonReady() );
}

bool PolyboxModule::isPrinterReady()
{
    return ( _printer->isReady() && this->isConnected() && this->isCommonReady() );
}

bool PolyboxModule::isScannerReady()
{
    return ( _scanner->isReady() && this->isConnected() && this->isCommonReady() );
}
