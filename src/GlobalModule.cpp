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

void GlobalModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    int size = str.size();
    switch ( value )
    {
    case 651:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_boxOpen, str[idx] );  // Cuidao ! True = box is open, so Red light ! False means box is close, so gren light !
    }
        break;
    case 652:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_ATUok, str[idx] );
    }
        break;
    case 653: // Arduino1,2,3,4,... detected
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'A')
            {
                if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    SerialPort::parseTrueFalse( &_arduino1, str[idx] );
                }
                else if ( str[idx+1]=='2')
                {
                    SerialPort::nextValue( str, idx);
                    SerialPort::parseTrueFalse( &_arduino2, str[idx] );
                }
                else if ( str[idx+1]=='3')
                {
                    SerialPort::nextValue( str, idx);
                    SerialPort::parseTrueFalse( &_arduino3, str[idx] );
                }
                else if ( str[idx+1]=='4')
                {
                    SerialPort::nextValue( str, idx);
                    SerialPort::parseTrueFalse( &_arduino4, str[idx] );
                }
            }
        }
    }
        break;
    case 654:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_power, str[idx] );
    }
        break;
    case 655:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_command, str[idx] );
    }
        break;
    case 656:
    {
        SerialPort::nextField( str, idx);
        long temperature1=0;
        long temperature2=0;
        while ( idx < size )
        {
            if ( str[idx] == 'T' )
            {
                if ( str[idx] == '1' )
                {
                    SerialPort::nextValue( str, idx);
                    temperature1 = SerialPort::embeddedstr2l( str, idx );
                    temperature2 = temperature1;
                }
                if ( str[idx] == '2' )
                {
                    SerialPort::nextValue( str, idx);
                    temperature2 = SerialPort::embeddedstr2l( str, idx );
                }
            }
            SerialPort::nextField( str, idx);
        }
        _tempIC.setValue( (temperature1+temperature2) /2);
    }
        break;
    case 657:
    {
        SerialPort::nextField( str, idx);
   /** @todo //    SerialPort::parseTrueFalse( &, str[idx] ); **/
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
    emit updateUI();
}

bool GlobalModule::isReady() const
{
    return !boxOpen() && ATUok() && arduino1() && arduino2() && arduino3() && arduino4() && power() && webcamPlugged() && command() && !(_tempIC.isDefault());
}

void GlobalModule::updateComponents()
{
    cout<<"Ask Update Global All"<<endl;
    _arduino1 = _polybox->port()->connectToSerialPort();
    SerialPort::getSerial()->sendMCode("651");
    SerialPort::getSerial()->sendMCode("652");
    SerialPort::getSerial()->sendMCode("653");
    SerialPort::getSerial()->sendMCode("654");
    SerialPort::getSerial()->sendMCode("655");
    SerialPort::getSerial()->sendMCode("656");
    SerialPort::getSerial()->sendMCode("657");
    SerialPort::getSerial()->sendMCode("658");
    SerialPort::getSerial()->sendMCode("659");
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
