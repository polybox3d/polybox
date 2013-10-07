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
}

void PrinterModule::updateComponents()
{
    _polybox->port()->sendMCode( MCode::ASK_PRINTER_UPDATE );
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
