#include "GlobalModule.h"

GlobalModule::GlobalModule(PolyboxModule *polybox, QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}

void GlobalModule::initAll()
{
    _boxOpen = true;
    _ATUok = false;
    _arduino1 = false;
    _arduino2 = false;
    _arduino3 = false;
    _arduino4 = false;
    _command = false;
    _power = false;
    _webcamPlugged = false;
}

bool GlobalModule::isReady() const
{
    return !boxOpen() && ATUok() && arduino1() && arduino2() && arduino3() && arduino4() && power() && webcamPlugged() && command() && !(_tempIC.isDefault());
}

void GlobalModule::updateComponents()
{
    _arduino1 = _polybox->port()->isOpen();
}


bool GlobalModule::boxOpen() const
{
    return _boxOpen;
}
bool GlobalModule::ATUok() const
{
    return _ATUok;
}
bool GlobalModule::arduino1() const
{
    return _arduino1;
}
bool GlobalModule::arduino2() const
{
    return _arduino2;
}
bool GlobalModule::arduino3() const
{
    return _arduino3;
}
bool GlobalModule::arduino4() const
{
    return _arduino4;
}

bool GlobalModule::command() const
{
    return _command;
}
bool GlobalModule::power() const
{
    return _power;
}
bool GlobalModule::webcamPlugged() const
{
    return _webcamPlugged;
}

Temperature GlobalModule::tempIC()
{
    return _tempIC;
}
