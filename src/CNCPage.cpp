#include "CNCPage.h"
#include "ui_CNCPage.h"

CNCPage::CNCPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CNCPage)
{
    ui->setupUi(this);
}

CNCPage::~CNCPage()
{
    delete ui;
}
