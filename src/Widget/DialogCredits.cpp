#include "DialogCredits.h"
#include "ui_DialogCredits.h"

DialogCredits::DialogCredits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCredits)
{
    ui->setupUi(this);
    ui->versionPolysoftware->setText( QCoreApplication::applicationVersion() );
    ui->versionQt->setText( QT_VERSION_STR );
}

DialogCredits::~DialogCredits()
{
    delete ui;
}
