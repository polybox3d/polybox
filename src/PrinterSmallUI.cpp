#include "PrinterSmallUI.h"
#include "ui_PrinterSmallUI.h"

PrinterSmallUI::PrinterSmallUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterSmallUI)
{
    ui->setupUi(this);
}

PrinterSmallUI::~PrinterSmallUI()
{
    delete ui;
}
