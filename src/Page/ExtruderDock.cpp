#include "ExtruderDock.h"
#include "ui_ExtruderDock.h"

ExtruderDock::ExtruderDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ExtruderDock)
{
    ui->setupUi(this);
    connect(&_updateTimer, SIGNAL(timeout()), this, SLOT(updateComponents()));
    _updateTimer.start( Config::updateModuleTimer() );
}

void ExtruderDock::updateComponents()
{
    PrinterModule* printer = PolyboxModule::getInstance()->printerModule();

    bool extr0_activated = printer->printerE0Plugged();

    ui->extr0_cold_bot->setEnabled( extr0_activated );
    ui->extr0_cold_top->setEnabled( extr0_activated );
    ui->extr0_hotend->setEnabled( extr0_activated );

    ui->extr0_heater->setEnabled( extr0_activated );
    ui->extr0_pel->setEnabled( extr0_activated );
    ui->extr0_fan->setEnabled( extr0_activated );


    bool extr1_activated = printer->printerE1Plugged();

    ui->extr1_cold_bot->setEnabled( extr1_activated );
    ui->extr1_cold_top->setEnabled( extr1_activated );
    ui->extr1_hotend->setEnabled( extr1_activated );

    ui->extr1_heater->setEnabled( extr1_activated );
    ui->extr1_pel->setEnabled( extr1_activated );
    ui->extr1_fan->setEnabled( extr1_activated );

    ui->extr0_cold_top->setText( QString::number(printer->coldTopBuse1().getValue()  ) );
    ui->extr1_cold_top->setText( QString::number(printer->coldTopBuse2().getValue()  ) );

    ui->extr0_cold_bot->setText( QString::number(printer->coldBotBuse1().getValue()  ) );
    ui->extr1_cold_bot->setText( QString::number(printer->coldBotBuse2().getValue() ) );

    ui->extr0_hotend->setText( QString::number(printer->tempHotBuse1().getValue()  ) );
    ui->extr1_hotend->setText( QString::number(printer->tempHotBuse2().getValue()  ) );


}

ExtruderDock::~ExtruderDock()
{
    delete ui;
}
