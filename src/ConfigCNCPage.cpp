#include "ConfigCNCPage.h"
#include "ui_ConfigCNCPage.h"

ConfigCNCPage::ConfigCNCPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigCNCPage)
{
    ui->setupUi(this);
}

ConfigCNCPage::~ConfigCNCPage()
{
    delete ui;
}
