#include "DialogConfigSoft.h"
#include "ui_DialogConfigSoft.h"

DialogConfigSoft::DialogConfigSoft(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfigSoft)
{
    ui->setupUi(this);
}

DialogConfigSoft::~DialogConfigSoft()
{
    delete ui;
}

void DialogConfigSoft::on_close_clicked()
{
    this->reject();
}

void DialogConfigSoft::on_validate_clicked()
{
    this->done( QDialog::Accepted );
}
