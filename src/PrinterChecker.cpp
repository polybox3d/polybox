#include "PrinterChecker.h"
#include "ui_PrinterChecker.h"

PrinterChecker::PrinterChecker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterChecker)
{
    _printer = NULL;
    ui->setupUi(this);
}

PrinterChecker::PrinterChecker(PrinterModule* printer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterChecker)
{
    _printer = printer;
    ui->setupUi(this);
}

void PrinterChecker::paintEvent(QPaintEvent *)
{
    if ( _printer == NULL )
    {
        return;
    }

}

PrinterChecker::~PrinterChecker()
{
    delete ui;
}
