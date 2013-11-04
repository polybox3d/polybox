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


void CNCModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;

    switch ( value )
    {
    case 600:
    {

    }
        break;
    case 601:
    {
        SerialPort::nextField( str, idx);
        if (str[idx] == 'H' )
        {
            _cncPlugged = true;
            _cncType = Manual;
        }
        else if( str[idx] =='P' )
        {
            _cncPlugged = true;
            _cncType = Proxxon;
        }
        else if( str[idx] == '0' )
        {
            _cncPlugged = false;
            _cncType = Noone;
        }

    }
        break;
    case 602:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_motorLubPlugged, str[idx] );
    }
        break;
    case 603:
    {
        SerialPort::nextField( str, idx);
        long c_value = SerialPort::embeddedstr2l( str, idx );

        _levelLub = c_value;
        if ( _levelLub < 0)
        {
            _levelLub = 0;
        }

    }
        break;
    case 604:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_vacuumPlugged, str[idx] );
    }
        break;
    default:
        break;
    }
    emit updateUI();

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
