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
