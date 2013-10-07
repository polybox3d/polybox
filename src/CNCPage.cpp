#include "CNCPage.h"
#include "ui_CNCPage.h"

CNCPage::CNCPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNCPage)
{
    ui->setupUi(this);

    startLinuxCNC();
}

CNCPage::~CNCPage()
{
    delete ui;
}

void CNCPage::startLinuxCNC()
{
    QString command = Config::linuxCNCCommand;
    _linuxcnc = new QProcess( this );
    _linuxcnc->start( command);
}
