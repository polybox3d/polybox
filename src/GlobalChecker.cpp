#include "GlobalChecker.h"
#include "ui_GlobalChecker.h"


GlobalChecker::GlobalChecker(QWidget *parent) :
    QWidget(parent), AbstractChecker( NULL ),
    ui(new Ui::GlobalChecker)
{
    _global = NULL;

    ui->setupUi(this);
}


GlobalChecker::GlobalChecker(GlobalModule *global, QWidget *parent) :
    QWidget(parent), AbstractChecker( global ),
    ui(new Ui::GlobalChecker)
{
    _global = global;

    ui->setupUi(this);
}

GlobalChecker::~GlobalChecker()
{
    delete ui;
}

void GlobalChecker::paintEvent(QPaintEvent *)
{
    if ( _global == NULL )
    {
        return;
    }
    else
    {
       ui->arduino1Led->setActivated( _global->arduino1() );
       ui->arduino2Led->setActivated( _global->arduino2() );
       ui->arduino3Led->setActivated( _global->arduino3() );
       ui->arduino4Led->setActivated( _global->arduino4() );

       ui->ATULed->setActivated( _global->ATUok() );
       ui->boxOpenLed->setActivated( !_global->boxOpen() );
       ui->commandLed->setActivated( _global->command() );
       ui->powerLed->setActivated( _global->power() );
       ui->webcamPluggedLed->setActivated( _global->webcamPlugged() );
       ui->tempICLed->setActivated( !_global->tempIC().isDefault() );
    }
}
