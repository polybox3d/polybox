#include "CNCChecker.h"
#include "ui_CNCChecker.h"

CNCChecker::CNCChecker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNCChecker)
{
    ui->setupUi(this);
}

CNCChecker::~CNCChecker()
{
    delete ui;
}
