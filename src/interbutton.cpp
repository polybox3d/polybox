#include "interbutton.h"
#include "ui_interbutton.h"

InterButton::InterButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InterButton)
{
    ui->setupUi(this);
}

InterButton::~InterButton()
{
    delete ui;
}
