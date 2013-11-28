#include "PrinterPage.h"
#include "ui_PrinterPage.h"

PrinterPage::PrinterPage(PrinterModule* printer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterPage)
{
    _printer = printer;
    ui->setupUi(this);
    _printerSoftware = NULL;
    _printerSoftwarePath = DEFAULT_SOFTWARE_PRINTER_PATH;
    _updateModuleTimer.setInterval( Config::updateModuleTimer );
    connect( &_updateModuleTimer, SIGNAL(timeout()), _printer, SLOT(updateComponents()) );

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToModulePage()));

    connect( ui->backToHelp, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToHelpPage()));
}

PrinterPage::~PrinterPage()
{
    delete ui;
}

void PrinterPage::repaintComponents()
{
    ui->boxTempSpin->setValue( _printer->getTargetChamberTemp().getValue() );
    ui->boxTempSlider->setValue( _printer->getTargetChamberTemp().getValue() );
    ui->bedTempSlider->setValue( _printer->getTargetBedTemp().getValue() );
    ui->bedtempSpin->setValue( _printer->getTargetBedTemp().getValue() );
    ui->ledClogged->setActivated( ! _printer->wireClogged() );
}

void PrinterPage::on_selectAllBed_clicked()
{
    _printer->activateAllBed( true );
    ui->bed_bl->setChecked( true );
    ui->bed_br->setChecked( true );
    ui->bed_fl->setChecked( true );
    ui->bed_fr->setChecked( true );
}
void PrinterPage::on_selectNoBed_clicked()
{
    _printer->activateAllBed( false );
    ui->bed_bl->setChecked( false );
    ui->bed_br->setChecked( false );
    ui->bed_fl->setChecked( false );
    ui->bed_fr->setChecked( false );
}

void PrinterPage::on_inactifBed_clicked()
{
    ui->selectNoBed->setChecked( true );
    on_selectNoBed_clicked();
    _printer->setTargetBedTemp( Temperature(DEFAULT_TEMP_VALUE) );

    setBedActivated(false);
    repaintComponents();
}

void PrinterPage::setBedActivated(bool activated)
{
    ui->bedTempSlider->setEnabled( activated );
    ui->bedtempSpin->setEnabled( activated );
    ui->inactifBed->setChecked( !activated );
}
void PrinterPage::setChamberActivated(bool activated)
{
    ui->boxTempSlider->setEnabled( activated );
    ui->boxTempSpin->setEnabled( activated );
    ui->boxInactif->setChecked( !activated );
}
void PrinterPage::on_plaBed_clicked()
{
    _printer->setTargetBedTemp( Temperature(Config::bedTempPla) );
    setBedActivated(true);
    repaintComponents();
}

void PrinterPage::on_absBed_clicked()
{
    _printer->setTargetBedTemp( Temperature(Config::bedTempAbs) );
    setBedActivated(true);
    repaintComponents();
}

void PrinterPage::on_nylonBed_clicked()
{
    _printer->setTargetBedTemp( Temperature(Config::bedTempNylon) );
    setBedActivated(true);
    repaintComponents();
}

void PrinterPage::on_box60_clicked()
{
    _printer->setTargetChamberTemp( Temperature(60) );
    setChamberActivated(true);
    repaintComponents();
}
void PrinterPage::on_box75_clicked()
{
    _printer->setTargetChamberTemp( Temperature(75) );
    setChamberActivated(true);
    repaintComponents();
}
void PrinterPage::on_boxInactif_clicked()
{
    _printer->setTargetChamberTemp( Temperature(DEFAULT_TEMP_VALUE) );
    setChamberActivated(false);
    repaintComponents();

}
void PrinterPage::on_customBed_clicked()
{
    setBedActivated(true);
}

void PrinterPage::on_boxCustom_clicked()
{
    setChamberActivated(true);
}

void PrinterPage::on_pushButton_clicked()
{
    QString command = _printerSoftwarePath;
    QStringList parameters;
    parameters << "" ;
    _printerSoftware = new QProcess( this );
    _printerSoftware->start( command, parameters );

}

void PrinterPage::selectCustomBed()
{
    if ( ui->inactifBed->isChecked() )
    {
        ui->absBed->setChecked( false );
        ui->plaBed->setChecked( false );
        ui->nylonBed->setChecked( false );
        ui->customBed->setChecked( true );
    }
}
void PrinterPage::selectCustomChamber()
{
    ui->box60->setChecked( false );
    ui->box75->setChecked( false );
    ui->boxCustom->setChecked( true );
}

void PrinterPage::on_boxTempSlider_valueChanged(int value)
{
    _printer->setTargetChamberTemp( Temperature(value) );
    repaintComponents();
}
void PrinterPage::on_boxTempSpin_valueChanged(int arg1)
{
    _printer->setTargetChamberTemp( Temperature(arg1) );
    repaintComponents();
}

void PrinterPage::on_bedTempSlider_valueChanged(int value)
{
    _printer->setTargetBedTemp(Temperature(value));
    repaintComponents();
}

void PrinterPage::on_bedtempSpin_valueChanged(int arg1)
{
    _printer->setTargetBedTemp(Temperature(arg1));
    repaintComponents();
}


void PrinterPage::on_bed_bl_clicked()
{
    _printer->addSupprBed( BED_1 );
}

void PrinterPage::on_bed_br_clicked()
{
    _printer->addSupprBed( BED_2 );
}

void PrinterPage::on_bed_fl_clicked()
{
    _printer->addSupprBed( BED_3 );
}

void PrinterPage::on_bed_fr_clicked()
{
    _printer->addSupprBed( BED_4 );
}

