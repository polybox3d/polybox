#include "Warning.h"
#include "ui_Warning.h"

Warning::Warning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warning)
{
    ui->setupUi(this);
}

Warning::~Warning()
{
    delete ui;
}
