#include "PolyboxModule.h"

//Breaking circles references
#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
#include "GlobalModule.h"
#include <QDebug>

QJoystick* PolyboxModule::_joypad=NULL;

PolyboxModule::PolyboxModule(QObject *parent) :
    QObject(parent)
{
    Config::init();

    _hardwareTimer.start( Config::hardwareTimer );
    connect( &_hardwareTimer, SIGNAL(timeout()), this, SLOT(hardwareTimerTimeout()));

    _polyplexer = Polyplexer::getInstance();
    _polyplexer->useWindowOutput(false);
    if ( _polyplexer->start() )
    {
        _port = SerialPort::getSerial();
        _connected = _port->isConnected();
        if ( _connected )
        {
            MainWindow::textWindow( "Your software is fully connected. ");
            connect ( _port, SIGNAL(dataReady()), this, SLOT(parseData()) );
        }
    }
    _cnc = new CNCModule( this, this );
    _labview = new LabViewModule( this );
    _printer = new PrinterModule( this, this );
    _scanner = new ScannerModule( this, this );
    _global = new GlobalModule( this, this );

}

void PolyboxModule::hardwareTimerTimeout()
{
    emit updateHardware();
}

void PolyboxModule::parseData()
{
    QByteArray datas = _port->datas();
    QString str(datas);
    int idx = str.indexOf('M') ;
    if ( idx != -1 ) // M Code find
    {
         _cnc->parseMCode( &str.toStdString().c_str()[idx+1] );
         _global->parseMCode( &str.toStdString().c_str()[idx+1] );
         _scanner->parseMCode( &str.toStdString().c_str()[idx+1] );
         _printer->parseMCode( &str.toStdString().c_str()[idx+1] );
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

SerialPort* PolyboxModule::port()
{
    return _port;
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
    return _connected;
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
    //return ( ->isReady() && this->isConnected() && this->isCommonReady() );
}

bool PolyboxModule::isScannerReady()
{
    return ( _scanner->isReady() && this->isConnected() && this->isCommonReady() );
    //return ( _la->isReady() && this->isConnected() && this->isCommonReady() );
}
