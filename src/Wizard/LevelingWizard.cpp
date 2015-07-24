#include "LevelingWizard.h"

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
    this->setAttribute(Qt::WA_DeleteOnClose);
}
void LevelingWizard::accept()
{
    Config::set(SETTINGS_GROUP,"contactPointA_z", field("Az") );
    Config::set(SETTINGS_GROUP,"contactPointA_z", field("Bz") );
    Config::set(SETTINGS_GROUP,"contactPointA_z", field("Cz") );
    Config::set(CHECKER_GROUP,"lastLevelingDate", QDate::currentDate().toString("ddMMyyyy") );

    QDialog::accept();
}

LevelingWizard::~LevelingWizard()
{
}
