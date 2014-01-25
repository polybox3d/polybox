#include "PrinterSmallUI.h"
#include "ui_PrinterSmallUI.h"

PrinterSmallUI::PrinterSmallUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterSmallUI)
{
    ui->setupUi(this);
    _printer = NULL;
}

void PrinterSmallUI::addPrinterModule(PrinterModule* printer)
{
    _printer = printer;
}

void PrinterSmallUI::updateComponents()
{
    ui->bedTempBar->setValue( _printer->getCurrentBedTemp().getValue() );
    ui->boxTempBar->setValue( _printer->getCurrentAverageChamberTemp().getValue() );
}

PrinterSmallUI::~PrinterSmallUI()
{
    delete ui;
}
