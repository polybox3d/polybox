#include "DialogWidget.h"
#include "ui_DialogWidget.h"

DialogWidget::DialogWidget(QString displayedText, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWidget)
{
    ui->setupUi(this);
    ui->text->setText( displayedText );
}

DialogWidget::~DialogWidget()
{
    delete ui;
}

void DialogWidget::on_close_clicked()
{
    this->accept();
}

void DialogWidget::on_cancel_clicked()
{
    this->reject();
}
