#include "PolyboxModule.h"

PolyboxModule::PolyboxModule(QObject *parent) :
    QObject(parent)
{

    _cnc = new CNCModule( this );
    _labview = new LabViewModule( this );
    _printer = new PrinterModule( this );
    _scanner = new ScannerModule( this );
    _connected = false;
}

LabViewModule* PolyboxModule::labView()
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
    return true;
}

bool PolyboxModule::isCncReady()
{
    return ( _cnc->isReady() && this->isConnected() && this->isCommonReady() );
}

bool PolyboxModule::isPrinterReady()
{
    return ( true && this->isConnected() && this->isCommonReady() );
    //return ( ->isReady() && this->isConnected() && this->isCommonReady() );
}

bool PolyboxModule::isScannerReady()
{
    return ( true && this->isConnected() && this->isCommonReady() );
    //return ( _la->isReady() && this->isConnected() && this->isCommonReady() );
}
