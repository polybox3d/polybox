#include "LevelingWizard.h"
#include "ui_LevelingWizard.h"

LevelingWizard::LevelingWizard(QWidget *parent) :
    QWizard(parent)
{
    addPage( new IntroLevelingPage( this ) );
    addPage( new ContactPointLevelingPage( this ) );
    addPage( new ContactPointLevelingPage( this ) );
    addPage( new ContactPointLevelingPage( this ) );
    addPage( new ProcessLevelingPage( this ) );

    setWindowTitle(tr("Leveling Software"));
    this->setFixedSize( 540, 410 );
}
void LevelingWizard::accept()
{
    Config::set(SETTINGS_GROUP,"contactPointA_z", field("Az") );
    Config::set(SETTINGS_GROUP,"contactPointA_z", field("Bz") );
    Config::set(SETTINGS_GROUP,"contactPointA_z", field("Cz") );
    Config::set(SETTINGS_GROUP,"lastLevelingDate", QDate::currentDate().toString("ddMMyyyy") );

    QDialog::accept();
}

LevelingWizard::~LevelingWizard()
{
}
