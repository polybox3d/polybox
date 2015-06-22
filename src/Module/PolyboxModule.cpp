#include "PolyboxModule.h"

//Breaking circles references
#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
#include "GlobalModule.h"
#include <QDebug>


PolyboxModule* PolyboxModule::polyboxModuleInstance = NULL;
QJoystick* PolyboxModule::_joypad=NULL;
//QMap<int, QString> PolyboxModule::connectionStatusMessage;

PolyboxModule* PolyboxModule::getInstance(QObject *parent)
{
    if ( polyboxModuleInstance == NULL )
    {
        polyboxModuleInstance = new PolyboxModule( parent );
    }
    return polyboxModuleInstance;
}

PolyboxModule::PolyboxModule(QObject *parent) :
    QObject(parent)
{

    _cnc = new CNCModule( this, this );
    _labview = new LabViewModule( this );
    _printer = new PrinterModule( this, this);
    _scanner = new ScannerModule( this, this);
    _global = new GlobalModule( this, this );

    _hardwareTimer.start( Config::hardwareTimer() );
    connect( &_hardwareTimer, SIGNAL(timeout()), this, SLOT(hardwareTimerTimeout()));

}
/*
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


PolyboxModule::ConnectionStatus PolyboxModule::connection( bool blocked_thread)
{
    _connected = _polyplexer->start();
    if ( _connected )
    {
        _numberOfMissingPingPong = PINGPONG_NOT_CONNECTED;
        SerialPort* con = dynamic_cast<SerialPort*>( _connector );
        // Start VirtualSerial Connexion
        _connected = con->connectToSerialPort() ;

        if ( _connected && _connector->isConnected()  )
        {
            QTimer* timer_connect = new QTimer(this);
            connect( timer_connect, SIGNAL(timeout()), _labview, SLOT(setConnectedColor()) );
            timer_connect->setSingleShot(true);
            timer_connect->start( 1000 );

            if ( blocked_thread )
            {
                // We need to wait the end of ping/pong process. It's an closed loop, we process QtEvent and check if the connection is active
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

*/
void PolyboxModule::hardwareTimerTimeout()
{
    emit updateHardware();
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
/*
bool PolyboxModule::isConnected()
{
    return PolyboxModule::getInstance()->_connected && PolyboxModule::getInstance()->_connector->isConnected() && PolyboxModule::getInstance()->_numberOfMissingPingPong <= PINGPONG_MAX_TRIES;
}
*/
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
    return ( _printer->isReady() && Polyplexer::isConnected() && this->isCommonReady() );
}

bool PolyboxModule::isScannerReady()
{
    return ( _scanner->isReady() && Polyplexer::isConnected() && this->isCommonReady() );
}
