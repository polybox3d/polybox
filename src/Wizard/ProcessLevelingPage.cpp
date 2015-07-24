#include "ProcessLevelingPage.h"
#include "ui_ProcessLevelingPage.h"

ProcessLevelingPage::ProcessLevelingPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ProcessLevelingPage)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

bool ProcessLevelingPage::generateRotationMatrix()
{
    float az = field("Az").toFloat() ;
    float bz = field("Bz").toFloat() ;
    float cz = field("Cz").toFloat() ;
    return true;
}

void ProcessLevelingPage::initializePage()
{
    generateRotationMatrix();

}

ProcessLevelingPage::~ProcessLevelingPage()
{
    delete ui;
}
