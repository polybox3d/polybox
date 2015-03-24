#include "ContactPointLevelingPage.h"
#include "ui_ContactPointLevelingPage.h"

ContactPointLevelingPage::ContactPointLevelingPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ContactPointLevelingPage)
{
    ui->setupUi(this);
}

ContactPointLevelingPage::~ContactPointLevelingPage()
{
    delete ui;
}
