#include "PolyboxModule.h"

//Breaking circles references
#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
#include "GlobalModule.h"
#include <QDebug>

PolyboxModule::PolyboxModule(QObject *parent) :
    QObject(parent)
{
    Config::init();
    _cnc = new CNCModule( this, this );
    _labview = new LabViewModule( this );
    _printer = new PrinterModule( this, this );
    _scanner = new ScannerModule( this, this );
    _global = new GlobalModule( this, this );

    _port = new SerialPort();

    _connected = _port->connectToSerialPort();
    if ( _connected )
    {
        connect ( _port, SIGNAL(dataReady()), this, SIGNAL(parseData()) );
    }

}

void PolyboxModule::parseData()
{
    QByteArray datas = _port->datas();
    QString d = datas.data();
    int idx = d.indexOf('M') ;
    if ( idx != -1 ) // M Code find
    {
        /*switch (control) {
        case value:

            break;
        default:
            break;
        }*/
    }

}

SerialPort* PolyboxModule::port()
{
    return _port;
}

GlobalModule* PolyboxModule::globalModule()
{
    return _global;
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
