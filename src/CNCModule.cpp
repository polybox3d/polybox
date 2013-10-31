#include "CNCModule.h"

CNCModule::CNCModule(PolyboxModule *polybox, QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}

CNCModule::~CNCModule()
{

}

bool CNCModule::isReady() const
{
    return true;
    return (_cncPlugged &&_motorLubPlugged &&
            (_levelLub != DEFAULT_LEVEL_LUB) &&_vacuumPlugged &&
            (_cncType != Unknowed) && (_cncType != Noone ) );
}
void CNCModule::initAll()
{
    _cncPlugged = false;
    _motorLubPlugged = false;
    _levelLub = false;
    _vacuumPlugged = false;
    _cncType = Noone;
}

void CNCModule::updateGlobalStatus()
{
   _polybox->port()->sendMCode( 600 );
}

void CNCModule::updateToolPlugged()
{
   _polybox->port()->sendMCode( 601 );
}

void CNCModule::updateLubricantLevel()
{
    _polybox->port()->sendMCode( 603 );
}

void CNCModule::updateVacummPlugged()
{
    _polybox->port()->sendMCode( 604 );
}


void CNCModule::updateComponents()
{
    updateGlobalStatus();
    updateLubricantLevel();
    updateToolPlugged();
    updateVacummPlugged();
}

bool CNCModule::cncPlugged()
{
    return _cncPlugged;
}
bool CNCModule::motorLubPlugged()
{
    return _motorLubPlugged;
}
float CNCModule::levelLub()
{
    return _levelLub;
}
bool CNCModule::vacuumPlugged()
{
    return _vacuumPlugged;
}
CNCType CNCModule::cncType()
{
    return _cncType;
}
