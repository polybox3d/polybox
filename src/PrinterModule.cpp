#include "PrinterModule.h"


PrinterModule::PrinterModule(PolyboxModule* polybox,QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}


void PrinterModule::initAll()
{
    _printerPlugged = false;
    _detectPlastic = true;
    _bedPlugged = false;
    _selectedBed = BED_1 & BED_2 & BED_3 & BED_4;
}

void PrinterModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    int size = str.size();
    switch ( value )
    {
    case 631:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_printerPlugged, str[idx] );
    }
        break;
    case 632:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_detectPlastic, str[idx] );
    }
        break;
    case 633:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_bedPlugged, str[idx] );
    }
        break;
    case 634:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'Z')
            {
                if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox1.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='2')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox2.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='3')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox3.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='4')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox4.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
        break;
    case 635:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'B')
            {
                if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBuse1.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='2')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBuse2.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
        break;
    case 636:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'B')
            {
                if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    _tempBedMid.setValue( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='2')
                {
                    SerialPort::nextValue( str, idx);
                    _tempBedExt.setValue( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
        break;
    case 639:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_wireClogged, str[idx] );
    }
        break;
    case 640:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'A')
            {
                    SerialPort::nextValue( str, idx);
                    _tempBoxTop.setValue( SerialPort::embeddedstr2l( str, idx ) );
                    cout<<"#"<<idx<<" "<<str.toStdString()<<endl;
            }
            if ( str[idx] == 'B')
            {
                    SerialPort::nextValue( str, idx);
                    _tempBoxMiddle.setValue( SerialPort::embeddedstr2l( str, idx ) );
            }
            if ( str[idx] == 'C')
            {
                    SerialPort::nextValue( str, idx);
                    _tempBoxBot.setValue( SerialPort::embeddedstr2l( str, idx ) );
            }
        }
    }
        break;
    default:
        break;
    }
}

void PrinterModule::updateComponents()
{
    _polybox->port()->sendMCode( MCode::ASK_PRINTER_UPDATE );
}

void PrinterModule::activateAllBed(bool activated)
{
    _selectedBed = 0;
    if ( activated )
    {
        _selectedBed = BED_1 & BED_2 & BED_3 & BED_4;
    }
}

bool PrinterModule::isReady() const
{
    return (!_tempBedExt.isDefault()) &&
            ( !_tempTopBuse1.isDefault()) &&
            ( !_tempBotBuse1.isDefault()) &&
            ( !_tempTopBuse2.isDefault()) &&
            ( !_tempBotBuse2.isDefault()) &&
            ( !_tempBoxTop.isDefault()) &&
            ( !_tempBoxMiddle.isDefault()) &&
            ( !_tempBoxBot.isDefault()) &&
            ( !_tempBedMid.isDefault()) &&
            ( !_tempBedExt.isDefault()) &&
            ( !_coldBox1.isDefault()) &&
            ( !_coldBox2.isDefault()) &&
            ( !_coldBox3.isDefault()) &&
            ( !_coldBox4.isDefault()) &&
            ( !_coldBuse1.isDefault()) &&
            ( !_coldBuse2.isDefault()) &&
            _printerPlugged && _detectPlastic && _bedPlugged;
}

void PrinterModule::addSupprBed(int bed_mask)
{
    _selectedBed= _selectedBed ^ bed_mask;
}

int PrinterModule::getSelectedBed()
{
    return _selectedBed;
}

void PrinterModule::setTargetBedTemp(const Temperature &temp)
{
    _targetBedTemp = temp;
}
Temperature PrinterModule::getTargetBedTemp()
{
    return _targetBedTemp;
}

void PrinterModule::setTargetChamberTemp(const Temperature &temp)
{
    _targetChamberTemp = temp;
}

Temperature PrinterModule::getTargetChamberTemp()
{
    return _targetChamberTemp;
}

Temperature PrinterModule::tempTopBuse1()
{
    return _tempTopBuse1;
}

Temperature PrinterModule::tempBotBuse1()
{
    return _tempBotBuse1;
}
Temperature PrinterModule::tempTopBuse2()
{
    return _tempTopBuse2;
}
Temperature PrinterModule::tempBotBuse2()
{
    return _tempBotBuse2;
}

Temperature PrinterModule::tempBoxTop()
{
    return _tempBoxTop;
}
Temperature PrinterModule::tempBoxMiddle()
{
    return _tempBoxMiddle;
}
Temperature PrinterModule::tempBoxBot()
{
    return _tempBoxBot;
}

Temperature PrinterModule::tempBedMid()
{
    return _tempBedMid;
}

Temperature PrinterModule::tempBedExt()
{
    return _tempBedExt;
}

Temperature PrinterModule::coldBox1()
{
    return _coldBox1;
}
Temperature PrinterModule::coldBox2()
{
    return _coldBox2;
}
Temperature PrinterModule::coldBox3()
{
    return _coldBox3;
}
Temperature PrinterModule::coldBox4()
{
    return _coldBox4;
}

Temperature PrinterModule::coldBuse1()
{
    return _coldBuse1;
}
Temperature PrinterModule::coldBuse2()
{
    return _coldBuse2;
}

bool PrinterModule::printerPlugged() const
{
    return _printerPlugged;
}
bool PrinterModule::detectPlastic() const
{
    return _detectPlastic;
}
bool PrinterModule::bedPlugged() const
{
    return _bedPlugged;
}
bool PrinterModule::wireClogged() const
{
    return _wireClogged;
}
