#include "DialogConfigSoft.h"
#include "ui_DialogConfigSoft.h"

DialogConfigSoft::DialogConfigSoft(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfigSoft)
{
    ui->setupUi(this);
    updateValues();
}

DialogConfigSoft::~DialogConfigSoft()
{
    delete ui;
}

void DialogConfigSoft::updateValues()
{
    ui->linuxcncBin->setText( Config::linuxCNCCommand);
    ui->linuxcncDirectory->setText( Config::pathToLinuxCNC);
    ui->pathDev->setText( Config::pathToWebcamDevice);
    ui->homeDirectory->setText( Config::pathToHomeDirectory);
    ui->webcamName->setText( Config::webcamName);
    ui->baudrate->setText( QString::number(Config::motherboardBaudrate) );
}

void DialogConfigSoft::on_close_clicked()
{
    this->reject();
}

void DialogConfigSoft::on_validate_clicked()
{
    this->done( QDialog::Accepted );
}

