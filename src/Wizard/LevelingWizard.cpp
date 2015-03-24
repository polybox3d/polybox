#include "LevelingWizard.h"
#include "ui_LevelingWizard.h"

LevelingWizard::LevelingWizard(QWidget *parent) :
    QWizard(parent)
{
    addPage( new IntroLevelingPage( this ) );
    addPage( new ContactPointLevelingPage( this ) );

    setWindowTitle(tr("Leveling Software"));
    this->setFixedSize( 540, 410 );
}
void LevelingWizard::accept()
{
    QDialog::accept();
}

LevelingWizard::~LevelingWizard()
{
}
