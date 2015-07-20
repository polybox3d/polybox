#include "DockHost.h"
#include "ui_DockHost.h"

DockHost::DockHost(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DockHost)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->addDockWidget( Qt::TopDockWidgetArea, new AxisControlDock(this));
    this->addDockWidget( Qt::LeftDockWidgetArea, new RotationControlDock(this));
    this->addDockWidget( Qt::RightDockWidgetArea, new LaserDock( PolyboxModule::getInstance()->scannerModule(), this));
}

DockHost::~DockHost()
{
    delete ui;
}
