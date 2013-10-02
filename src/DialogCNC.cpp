#include "DialogCNC.h"
#include "ui_DialogCNC.h"

DialogCNC::DialogCNC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCNC)
{
    ui->setupUi(this);
}

DialogCNC::~DialogCNC()
{
    delete ui;
}

void DialogCNC::on_startCnc_clicked()
{
    this->done( CNC );
}

void DialogCNC::on_configuration_clicked()
{
    this->done( ConfigurCNC );
}

void DialogCNC::on_help_clicked()
{
    this->done( Help );
}

void DialogCNC::on_close_clicked()
{
    this->reject();
}
