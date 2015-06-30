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
    _laser0Plugged = false;
    _laser1Plugged = false;
    _laser0Power = 0;
    _laser1Power = 0;
}

void ScannerModule::setLaserPower(u_int8_t laser_id, int power_percent)
{
    if ( laser_id == 0 )
    {
        if ( this->laser0Plugged() )
        {
            _laser0Power = power_percent;
            ComModule::getInstance(this)->sendMCode( QString::number(MCODE_SCANNER_SET_LASER_STATE)+" P0 S" + QString::number(power_percent*255/100));
        }
    }
    if ( laser_id == 1 )
    {
        if ( this->laser1Plugged() )
        {
            _laser1Power = power_percent;
            ComModule::getInstance(this)->sendMCode( QString::number(MCODE_SCANNER_SET_LASER_STATE)+" P1 S" + QString::number(power_percent*255/100) );
        }
    }
}

void ScannerModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    int size = str.size();
    switch ( value )
    {
    case MCODE_SCANNER_TURNTABLE_PLUGGED:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_turntablePlugged, str[idx] );
    }
        break;
    case MCODE_SCANNER_GET_LASER_PLUGGED:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'P')
            {
                if ( str[idx+1]=='0')
                {
                    SerialPort::nextValue( str, idx);
                    _laser0Plugged =  SerialPort::embeddedstr2l( str, idx ) ;
                }
                else if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    _laser1Plugged =  SerialPort::embeddedstr2l( str, idx ) ;
                }
            }
        }
    }
        break;
    default:
        break;
    }
    emit updateUI();
}

void ScannerModule::updateComponents()
{
    updateGlobalStatus();
    updateTurntablePlugged();
    emit updateUI();
}
void ScannerModule::updateGlobalStatus()
{
    ComModule::getInstance(this)->sendMCode( MCODE_SCANNER_GET_LASER_PLUGGED );
}

void ScannerModule::updateTurntablePlugged()
{
    //ComModule::getInstance(this)->sendMCode( MCODE_SCANNER_TURNTABLE_PLUGGED );
}

bool ScannerModule::isReady() const
{
    return ( _turntablePlugged && _primesencePlugged && _webcamPlugged );
}


bool ScannerModule::webcamPlugged() const
{
    return ! (LabViewModule::getAllCamera( Config::pathToWebcamDevice() ).empty()) ;
}
bool ScannerModule::primesensePlugged() const
{
    return _primesencePlugged;
}
bool ScannerModule::turntablePlugged() const
{
    return _turntablePlugged;
}

bool ScannerModule::laser0Plugged() const
{
    return _laser0Plugged;
}
bool ScannerModule::laser1Plugged() const
{
    return _laser1Plugged;
}
int ScannerModule::laser0Power() const
{
    return _laser0Power;
}
int ScannerModule::laser1Power() const
{
    return _laser1Power;
}
