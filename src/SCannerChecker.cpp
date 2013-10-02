#include "SCannerChecker.h"
#include "ui_SCannerChecker.h"

SCannerChecker::SCannerChecker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SCannerChecker)
{
    ui->setupUi(this);
}

SCannerChecker::~SCannerChecker()
{
    delete ui;
}
