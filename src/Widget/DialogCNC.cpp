#include "DialogCNC.h"
#include "ui_DialogCNC.h"

DialogCNC::DialogCNC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCNC)
{
    ui->setupUi(this);
    setupListConfigs();

}

DialogCNC::~DialogCNC()
{
    delete ui;
}

void DialogCNC::setupListConfigs()
{
    QString default_ini = Config::linuxCNCDefaultConfigFile();
    int i = -1;
    foreach (QString path, CNCModule::getAllCNCConfigs(Config::linuxCNCConfig()) )
    {
        ++i;
        ui->listConfigs->addItem( path.split('/').last().section('.',0,-2), path);
        if ( default_ini.compare(path) == 0 )
        {
            ui->listConfigs->setCurrentIndex( i );
        }
    }
    if ( i < 0 )
    {
        ui->startCnc->setEnabled( false );
    }
}

void DialogCNC::on_startCnc_clicked()
{
    QString file = qvariant_cast<QString>(ui->listConfigs->itemData(ui->listConfigs->currentIndex()));
    if ( QFile::exists( file ) )
    {
        Config::setLinuxCNCDefaultConfigFile( file );
        this->done( CNC );
    }
    else
    {
        ui->listConfigs->removeItem(ui->listConfigs->currentIndex());
    }
}

void DialogCNC::on_configuration_clicked()
{
    this->done( ConfigureCNC );
}

void DialogCNC::on_help_clicked()
{
    this->done( Help );
}

void DialogCNC::on_close_clicked()
{
    this->reject();
}
