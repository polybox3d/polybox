#include "MonitoringPage.h"
#include "ui_MonitoringPage.h"

MonitoringPage::MonitoringPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitoringPage)
{
    ui->setupUi(this);
    connect(ComputerMonitoring::getInstance(),SIGNAL(updateUI()),this, SLOT(updateComputer()));
    //connect(SelfMonitoring::getInstance(),SIGNAL(updateUI()),this, SLOT(updateSelf()));

    ui->ramBar->setMaximum(ComputerMonitoring::getInstance()->ramMax());
    ui->cpuBar->setMaximum(100.0);

    ui->cpuInfo->setText(ComputerMonitoring::getInstance()->getCPUInfo());
    /*foreach (QString label, ComputerMonitoring::getInstance()->diskLabel())
    {
        ui->diskBox->addItem(label);
    }*/

}

void MonitoringPage::updateComputer()
{
    ui->ramBar->setValue(ComputerMonitoring::getInstance()->ramCurrent());
    ui->ramDisplay->setText( QString::number(ComputerMonitoring::getInstance()->ramCurrent()/(1000.0*1000.0),'g',2)
                             +" GB / "
                             + QString::number(ComputerMonitoring::getInstance()->ramMax()/(1000.0*1000.0),'g',2)
                             +" GB"
                             );
    ui->cpuBar->setValue(ComputerMonitoring::getInstance()->cpu());
}

void MonitoringPage::updateSelf()
{

}

MonitoringPage::~MonitoringPage()
{
    delete ui;
}
