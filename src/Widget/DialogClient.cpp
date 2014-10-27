#include "DialogClient.h"
#include "ui_DialogClient.h"

DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);
    this->setWindowTitle( tr("Remote Connection") );
}

DialogClient::~DialogClient()
{
    delete ui;
}

void DialogClient::on_close_clicked()
{
    this->reject();
}
