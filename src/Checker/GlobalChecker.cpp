#include "GlobalChecker.h"
#include "ui_GlobalChecker.h"


GlobalChecker::GlobalChecker(QWidget *parent) :
    AbstractChecker(parent),
    ui(new Ui::GlobalChecker)
{
    _global = NULL;

    ui->setupUi(this);
}


GlobalChecker::GlobalChecker(GlobalModule *global, QWidget *parent) :
    AbstractChecker(parent),
    ui(new Ui::GlobalChecker)
{
    setModule( global );

    ui->setupUi(this);
}

void GlobalChecker::setModule(GlobalModule *module)
{
    AbstractChecker::setModule( module );
    _global = module;
    connect( _global , SIGNAL(updateUI()), this, SLOT(updateUI()));
}
void GlobalChecker::updateModuleValues()
{
    _global->updateComponents();
}

GlobalChecker::~GlobalChecker()
{
    delete ui;
}

void GlobalChecker::updateUI()
{
    if ( _global == NULL )
    {
        return;
    }
    else
    {
       ui->connectedLed->setActivated( _global->arduinoMaitre() );

       ui->arduino1Led->setActivated( _global->arduino1() );
       ui->arduino2Led->setActivated( _global->arduino2() );
       ui->arduino3Led->setActivated( _global->arduino3() );
       ui->arduino4Led->setActivated( _global->arduino4() );

       //ui->ATULed->setActivated( _global->ATUok() );
       ui->boxOpenLed->setActivated( !_global->boxOpen() );
       //ui->commandLed->setActivated( _global->command() );
       ui->powerLed->setActivated( _global->power() );
       ui->webcamPluggedLed->setActivated( _global->webcamPlugged() );
       ui->tempICLed->setActivated( !_global->tempIC().isDefault() );
       ui->tempIC->setText(QString::number(_global->tempIC().getValue())+"°C");
       ui->icOpenLed->setActivated( !_global->icOpen() );
       ui->toolATULed->setActivated( _global->toolATUok() );
       ui->preasiATULed->setActivated( _global->preasiATUok() );
       ui->ramValue->setText( QString::number(_global->ram()) );
       ui->uptime->setText(QString::number(ComModule::getInstance(this)->_connectionUptime/60)+'\'' );
       ui->errorValue->setText( QString::number(_global->error()) );
       if ( _global->polyMode() == GlobalModule::PrinterMode )
       {
           ui->printerMode->setChecked( true );
           ui->cncMode->setChecked( false );
       }
    }
}

void GlobalChecker::on_cncMode_clicked()
{
    if ( ui->cncMode->isChecked() )
        _global->changePolyMode( GlobalModule::CNCMode);
}

void GlobalChecker::on_printerMode_clicked()
{
    if ( ui->printerMode->isChecked() )
        _global->changePolyMode( GlobalModule::PrinterMode);
}
