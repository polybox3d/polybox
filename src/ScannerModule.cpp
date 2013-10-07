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

void ScannerModule::updateComponents()const
{
    return;
    //_polybox->port();

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
