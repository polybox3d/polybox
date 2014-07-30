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

    _pingPongTimer.start( 5000 );
    connect( &_pingPongTimer, SIGNAL(timeout()), this, SLOT(pingPong()));

    _polyplexer = Polyplexer::getInstance();
    connectToPrinter();

    _port = SerialPort::getSerial();
    connect ( _port, SIGNAL(dataReady()), this, SLOT(parseData()) );


    _cnc = new CNCModule( this, this );
    _labview = new LabViewModule( this );
    _printer = new PrinterModule( this, this );
    _scanner = new ScannerModule( this, this );
    _global = new GlobalModule( this, this );

}
bool PolyboxModule::connectToPrinter(QString path, QString port)
{
    _polyplexer->setPathMachine(path);
    _polyplexer->setPortMachine(port);
    return connectToPrinter();
}

bool PolyboxModule::connectToPrinter()
{
    _connected = _polyplexer->start();

    if ( _connected )
    {
        if ( SerialPort::getSerial()->isConnected()  )
        {
            MainWindow::textWindow( tr("Le logiciel est correctement connecté à la machine. ") );
            _numberOfMissingPingPong = 0;
        }
        else
        {
            MainWindow::errorWindow( tr("Impossible de se connecter à la machine.\n Error 0xff34' ") );
        }
    }
    else
    {
        MainWindow::errorWindow( tr("Impossible de se connecter à la machine.\n Erreur au lancement du sous-programme Polyplexer. 0xff30' ") );
    }
    return _connected;
}


void PolyboxModule::hardwareTimerTimeout()
{
    emit updateHardware();
}

void PolyboxModule::parseData()
{
    QByteArray datas = _polyplexer->printerDatas();
    QString str(datas);
    /*int start_idx = 0;
    int idx = str.indexOf( start_idx,'#') ;*/
    QStringList datas_listed = str.split("#", QString::SkipEmptyParts );
    foreach ( QString current_mcode, datas_listed )
    {
        this->parseMCode( current_mcode.toStdString().c_str() );
        _cnc->parseMCode( current_mcode.toStdString().c_str() );
        _global->parseMCode( current_mcode.toStdString().c_str() );
        _scanner->parseMCode( current_mcode.toStdString().c_str() );
        _printer->parseMCode( current_mcode.toStdString().c_str() );
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
        _numberOfMissingPingPong = 0;
    }
        break;
    default:
        break;
    }
}

void PolyboxModule::pingPong()
{
    if ( SerialPort::getSerial()->isConnected() )
    {
        _numberOfMissingPingPong++;
        SerialPort::getSerial()->sendMCode( MCODE_PING_PONG );
        if ( _numberOfMissingPingPong > 2 )
        {
            MainWindow::errorWindow( tr("Une erreur est survenue. La machine ne répond plus aux messages depuis un certain temps.\n Veuillez vous reconnecter.\n"));
            _polyplexer->stop();
        }
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
    return SerialPort::getSerial();
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
