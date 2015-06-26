#include "ExtruderDock.h"
#include "ui_ExtruderDock.h"

ExtruderDock::ExtruderDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ExtruderDock)
{
    ui->setupUi(this);
}

ExtruderDock::~ExtruderDock()
{
    delete ui;
}
