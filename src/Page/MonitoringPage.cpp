#include "MonitoringPage.h"
#include "ui_MonitoringPage.h"

MonitoringPage::MonitoringPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitoringPage)
{
    ui->setupUi(this);
}

MonitoringPage::~MonitoringPage()
{
    delete ui;
}
