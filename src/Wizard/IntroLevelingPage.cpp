#include "IntroLevelingPage.h"
#include "ui_IntroLevelingPage.h"

IntroLevelingPage::IntroLevelingPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::IntroLevelingPage)
{
    ui->setupUi(this);
}

IntroLevelingPage::~IntroLevelingPage()
{
    delete ui;
}
