#include "CheckerModele.h"
#include "ui_CheckerModele.h"

CheckerModele::CheckerModele( QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckerModele)
{
    ui->setupUi(this);
}
void CheckerModele::setContentWidget(QWidget *content)
{
    this->ui->contentWidget = content;
    ((AbstractChecker*)(ui->contentWidget))->updateModuleValues();
    update();

}

CheckerModele::~CheckerModele()
{
    delete ui;
}

void CheckerModele::on_close_clicked()
{
    this->reject();
}

void CheckerModele::on_help_clicked()
{
    this->done( Help );
}

void CheckerModele::on_pushButton_clicked()
{

    ((AbstractChecker*)(ui->contentWidget))->updateModuleValues();
}
