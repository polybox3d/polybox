#include "PolyboxModule.h"

//Breaking circles references
#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"

PolyboxModule::PolyboxModule(QObject *parent) :
    QObject(parent)
{

    _cnc = new CNCModule( this, this );
    _labview = new LabViewModule( this );
    _printer = new PrinterModule( this, this );
    _scanner = new ScannerModule( this, this );

    _port = new SerialPort();
    _connected = _port->connectToSerialPort();
}

SerialPort* PolyboxModule::port()
{
    return _port;
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
