#include "RotationControlDock.h"
#include "ui_RotationControlDock.h"

RotationControlDock::RotationControlDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::RotationControlDock)
{
    ui->setupUi(this);
}

RotationControlDock::~RotationControlDock()
{
    delete ui;
}
