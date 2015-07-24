#include "IntroLevelingPage.h"
#include "ui_IntroLevelingPage.h"

IntroLevelingPage::IntroLevelingPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::IntroLevelingPage)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

IntroLevelingPage::~IntroLevelingPage()
{
    delete ui;
}
