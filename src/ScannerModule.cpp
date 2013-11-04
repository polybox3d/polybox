#include "ScannerModule.h"

ScannerModule::ScannerModule(PolyboxModule *polybox, QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}

void ScannerModule::initAll()
{
    _turntablePlugged = false;
    _webcamPlugged = false;
    _primesencePlugged = false;
}

void ScannerModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    switch ( value )
    {
    case 611:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_turntablePlugged, str[idx] );
    }
        break;
    case 614:
    {
        /*SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_, str[idx] );*/
    }
        break;
    default:
        break;
    }
}

void ScannerModule::updateComponents()
{
    updateGlobalStatus();
    updateTurntablePlugged();

}
void ScannerModule::updateGlobalStatus()
{
    _polybox->port()->sendMCode( 610 );
}

void ScannerModule::updateTurntablePlugged()
{
    _polybox->port()->sendMCode( 611 );
}

bool ScannerModule::isReady() const
{
    return ( _turntablePlugged && _primesencePlugged && _webcamPlugged );
}


bool ScannerModule::webcamPlugged() const
{
    return _webcamPlugged;
}
bool ScannerModule::primesensePlugged() const
{
    return _primesencePlugged;
}
bool ScannerModule::turntablePlugged() const
{
    return _turntablePlugged;
}
