#include "PrinterChecker.h"
#include "ui_PrinterChecker.h"

PrinterChecker::PrinterChecker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterChecker)
{
    ui->setupUi(this);
}

PrinterChecker::~PrinterChecker()
{
    delete ui;
}
