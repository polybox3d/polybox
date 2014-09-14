#include "CNCPage.h"
#include "ui_CNCPage.h"

CNCPage::CNCPage(CNCModule *cncmodule, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNCPage)
{
    _cnc = cncmodule;
    ui->setupUi(this);

    startLinuxCNC();
}

CNCPage::~CNCPage()
{
    delete ui;
}

void CNCPage::startLinuxCNC()
{
    _cnc->startLinuxCNC();
    connect(_cnc, SIGNAL(signalLinuxCNCFinished()),this->parentWidget(),SLOT(close()));
}
