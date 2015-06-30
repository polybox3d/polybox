#include "PrinterModule.h"


void PrinterModule::executePrinterWebInterfaceCommand(QProcess &process, QString command)
{
    QString precommand = "kdesudo";
    QStringList parameters;
    QByteArray data;

    parameters << Config::printerWebInterfacePath() << command;

    process.start( precommand, parameters );
}

bool PrinterModule::printerWebInterfaceIsRunning()
{
    QProcess printerWebInterfaceProcess;

    PrinterModule::executePrinterWebInterfaceCommand( printerWebInterfaceProcess, "status");
    QByteArray data;

    while ( printerWebInterfaceProcess.waitForReadyRead() )
    {
        data.append( printerWebInterfaceProcess.readAll() );
    }
    QTextStream list(data);
    QString device;
    while ( !list.atEnd())
    {
        device = list.readLine();
        if ( device.indexOf("is running.") != -1 )
        {
            return true;
        }
    }
}
bool PrinterModule::printerWebInterfaceStart()
{
    QProcess printerWebInterfaceProcess;
    PrinterModule::executePrinterWebInterfaceCommand( printerWebInterfaceProcess, "start");

}
bool PrinterModule::printerWebInterfaceStop()
{
    QProcess printerWebInterfaceProcess;
    PrinterModule::executePrinterWebInterfaceCommand( printerWebInterfaceProcess, "stop");

}
bool PrinterModule::printerWebInterfaceRestart()
{
    QProcess printerWebInterfaceProcess;
    PrinterModule::executePrinterWebInterfaceCommand( printerWebInterfaceProcess, "restart");
}



PrinterModule::PrinterModule(PolyboxModule* polybox,QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}


void PrinterModule::initAll()
{
    _wireClogged = false;
    _printerE0Plugged = false;
    _printerE1Plugged = false;
    _detectPlastic = true;
    _bedPlugged = false;
    _extractorFanSpeed = 0;
    _pulsorFanSpeed = 0;
    _pelletierFanSpeed = 0;
    _selectedBed = BED_1 & BED_2 & BED_3 & BED_4;
}
void PrinterModule::startPrinterSoftware()
{
    QString command = "mono";
    QStringList parameters;
    parameters << Config::pathToPrinterSoftware()<<" -home "<< Config::pathToPrinterWorkingDir();

    _printerSoftware.start( command, parameters );

    _printerSoftware.waitForStarted(1000);
    if ( _printerSoftware.waitForFinished(1000) )
    {
        if ( _printerSoftware.exitCode() == 2 )
        {
            MainWindow::errorWindow( tr("\n\nImpossible de lancer le programme d'impression."
                                        "Veuillez vérifier que le chemin d'accès est correct.\n\n"
                                        "Configuration > Paramètres logiciel \n\n")+_printerSoftware.readAllStandardError()+"\n\n" );

            QString path = QFileDialog::getOpenFileName(MainWindow::getMainWindow(),
                                                        tr("Open Printer Executable"),
                                          Config::pathToHomeDirectory());
            Config::setPathToPrinterSoftware( path );
        }
    }

    cout<<Config::pathToPrinterSoftware().toStdString()<<endl;
}


void PrinterModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    int size = str.size();
    switch ( value )
    {
    case MCODE_PRINTER_TOOL_PLUGGED:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'Z')
            {
                if ( str[idx+1]=='0')
                {
                    SerialPort::nextValue( str, idx);
                    SerialPort::parseTrueFalse( &_printerE0Plugged, str[idx] );
                }
                else if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    SerialPort::parseTrueFalse( &_printerE1Plugged, str[idx] );
                }
            }
        }
    }
        break;
    case MCODE_PRINTER_WIRE_DETECTED:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_detectPlastic, str[idx] );
    }
        break;
    case MCODE_PRINTER_BED_PLUGGED:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_bedPlugged, str[idx] );
    }
        break;
    case MCODE_PRINTER_PEL_PLUGGED:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'Z')
            {
                if ( str[idx+1]=='0')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox1.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox2.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='2')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox3.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='3')
                {
                    SerialPort::nextValue( str, idx);
                    _coldBox4.setState( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
        break;
    case MCODE_PRINTER_GET_COLDEND_STATUS:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'B')
            {
                if ( str[idx+1]=='0')
                {
                    SerialPort::nextValue( str, idx);
                    //_coldBuse1.setValue( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    //_coldBuse2.setValue( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
        break;
    case MCODE_PRINTER_GET_BED_TEMP_C:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'T')
            {
                if ( str[idx+1]=='0')
                {
                    SerialPort::nextValue( str, idx);
                    _tempBedMid.setValue( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
        break;
    case MCODE_PRINTER_GET_BUSE_CLOGGED:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_wireClogged, str[idx] );
    }
        break;
    case MCODE_PRINTER_GET_CHAMBER_TEMP:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'T')
            {
                if ( str[idx+1]=='0')
                {
                    SerialPort::nextValue( str, idx);
                    _tempBoxMiddle.setValue( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
/*        while ( idx < size )
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
        }*/
    }
        break;
    case MCODE_PRINTER_GET_CHAMBER_TEMP_ALL:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'A')
            {
                    SerialPort::nextValue( str, idx);
                    _tempBoxTop.setValue( SerialPort::embeddedstr2l( str, idx ) );
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
    emit updateUI();
}

void PrinterModule::updateComponents()
{
    ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_TOOL_PLUGGED );
    ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_WIRE_DETECTED );
    ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_BED_PLUGGED );
    ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_PEL_PLUGGED );
    /*ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_GET_COOLER_BOX_STATUS );*/
    //ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_GET_COLDEND_STATUS );
    //ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_GET_BED_TEMP_C );
    //ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_GET_CHAMBER_TEMP_ALL );
    //ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_GET_CHAMBER_TEMP );
    //ComModule::getInstance(this)->sendMCode( MCODE_PRINTER_GET_BUSE_CLOGGED );

}
void PrinterModule::toggleInter()
{
    _isOn = !_isOn;
    ComModule::getInstance(this)->sendMCode( QString::number(MCODE_PRINTER_SET_STATUS)+" S"+QString::number(_isOn) );
}

void PrinterModule::activateAllBed(bool activated)
{
    _selectedBed = 0;
    if ( activated )
    {
        _selectedBed = BED_1 & BED_2 & BED_3 & BED_4;
    }
}
Temperature PrinterModule::getCurrentAverageChamberTemp()
{
    float sum = 0;
    int num = 0;
    if ( ! _tempBoxTop.isDefault() )
    {
        sum+=_tempBoxTop.getValue();
        ++num;
    }
    if ( ! _tempBoxBot.isDefault() )
    {
        sum+=_tempBoxBot.getValue();
        ++num;
    }
    if ( ! _tempBoxMiddle.isDefault() )
    {
        sum+=_tempBoxMiddle.getValue();
        ++num;
    }
    if ( num == 0 )
        return _tempBoxMiddle;
    return Temperature(sum/num);
}

Temperature PrinterModule::getCurrentBedTemp()
{
    return _tempBedMid;
}

bool PrinterModule::isReady() const
{
    return (!_tempBedExt.isDefault()) &&
            /*( !_tempTopBuse1.isDefault()) &&
            ( !_tempBotBuse1.isDefault()) &&
            ( !_tempTopBuse2.isDefault()) &&
            ( !_tempBotBuse2.isDefault()) &&*/
            ( !_tempBoxTop.isDefault()) &&
            ( !_tempBoxMiddle.isDefault()) &&
            ( !_tempBoxBot.isDefault()) &&
            ( !_tempBedMid.isDefault()) &&
            ( !_tempBedExt.isDefault()) &&
            ( !_coldBox1.isDefault()) &&
            ( !_coldBox2.isDefault()) &&
            ( !_coldBox3.isDefault()) &&
            ( !_coldBox4.isDefault()) &&
            /*( !_coldBuse1.isDefault()) &&
            ( !_coldBuse2.isDefault()) &&*/
            _printerE0Plugged && _printerE1Plugged && _detectPlastic && _bedPlugged && _wireClogged;
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

Temperature PrinterModule::coldTopBuse1()
{
    return _coldTopBuse1;
}

Temperature PrinterModule::coldTopBuse2()
{
    return _coldTopBuse2;
}
Temperature PrinterModule::coldBotBuse1()
{
    return _coldBotBuse1;
}
Temperature PrinterModule::coldBotBuse2()
{
    return _coldBotBuse2;
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


Temperature PrinterModule::tempHotBuse1()
{
    return _tempHotBuse1;
}

Temperature PrinterModule::tempHotBuse2()
{
    return _tempHotBuse2;
}



bool PrinterModule::printerE0Plugged() const
{
    return _printerE0Plugged;
}
bool PrinterModule::printerE1Plugged() const
{
    return _printerE1Plugged;
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
void PrinterModule::setFanByMask(u_int8_t mask, u_int8_t speed)
{

    ComModule::getInstance(this)->sendMCode(QString::number(MCODE_PRINTER_SET_FAN_SPEED)+" P"+QString::number(mask)+ " S"+QString::number(speed*255/100) );
}

void PrinterModule::setFanPelletierSpeed(int speed)
{
    setFanByMask(0x0F,speed);
    _pelletierFanSpeed = speed;
}

void PrinterModule::setFanPulsorFanSpeed(int speed)
{
    setFanByMask(0x20,speed);
    _pulsorFanSpeed = speed;
}
void PrinterModule::setFanExtractorFanSpeed(int speed)
{
    setFanByMask(0x10,speed);
    _extractorFanSpeed = speed;
}
int PrinterModule::fanPelletierSpeed()
{
    return _pelletierFanSpeed;
}

int PrinterModule::fanPulsorFanSpeed()
{
    return _pulsorFanSpeed;
}

int PrinterModule::fanExtractorFanSpeed()
{
    return _extractorFanSpeed;
}
