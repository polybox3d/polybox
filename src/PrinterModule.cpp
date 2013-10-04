#include "PrinterModule.h"

PrinterModule::PrinterModule(QObject *parent) :
    QObject(parent)
{
}


void PrinterModule::initAll()
{

}

void PrinterModule::updateValues()
{

}

bool PrinterModule::isReady() const
{
    return 42;
}
