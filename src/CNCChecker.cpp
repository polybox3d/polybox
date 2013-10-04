#include "CNCChecker.h"
#include "ui_CNCChecker.h"

CNCChecker::CNCChecker( QWidget *parent):
    QWidget(parent),
    ui(new Ui::CNCChecker)
{
    _cnc = NULL;
    ui->setupUi(this);
}

CNCChecker::CNCChecker(CNCModule* cnc, QWidget *parent):
    QWidget(parent),
    ui(new Ui::CNCChecker)
{
    _cnc = cnc;
    ui->setupUi(this);
}

CNCChecker::~CNCChecker()
{
    delete ui;
}

void CNCChecker::paintEvent(QPaintEvent *)
{
    if ( _cnc == NULL)
    {
        return;
    }
    else
    {
        ui->cncPlugLed->setActivated( _cnc->isReady() );
        ui->motorLubLed->setActivated( _cnc->motorLubPlugged() );
        ui->levelLubLed->setActivated( _cnc->levelLub() );
        ui->vacuumLed->setActivated( _cnc->vacuumPlugged() );
    }
}
