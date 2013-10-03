#include "GlobalChecker.h"
#include "ui_GlobalChecker.h"

GlobalChecker::GlobalChecker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GlobalChecker)
{
    ui->setupUi(this);
}

GlobalChecker::~GlobalChecker()
{
    delete ui;
}
