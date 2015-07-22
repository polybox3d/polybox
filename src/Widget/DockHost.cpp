#include "DockHost.h"
#include "ui_DockHost.h"

DockHost::DockHost(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DockHost)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->addDockWidget( Qt::TopDockWidgetArea, new AxisControlDock(this));

    QDockWidget* rotDock = new QDockWidget("RotationDock",this);
    rotDock->setWidget( new RotationControlDock(rotDock) );
    this->addDockWidget( Qt::LeftDockWidgetArea, rotDock );


    QDockWidget* laserDock = new QDockWidget("LaserDock",this);
    laserDock->setWidget(new LaserDockWidget( PolyboxModule::getInstance()->scannerModule(), laserDock));
    laserDock->setFixedHeight( 180 );
    laserDock->setFixedWidth( 350 );

    this->addDockWidget( Qt::RightDockWidgetArea, laserDock);
}

DockHost::~DockHost()
{
    delete ui;
}
