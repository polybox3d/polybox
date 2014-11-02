#include "PrinterPage.h"
#include "ui_PrinterPage.h"

PrinterPage::PrinterPage(PrinterModule* printer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterPage)
{
    _printer = printer;
    _update = false;
    ui->setupUi(this);
    ui->tempWidget->addPrinterModule( _printer );
    /*_printerSoftware.setParent( this );
    _printerSoftwarePath = Config::pathToPrinterSoftware();*/

    _updateModuleTimer.start( Config::updateModuleTimer() );
    connect( &_updateModuleTimer, SIGNAL(timeout()), _printer, SLOT(updateComponents()) );
    connect( &_updateModuleTimer, SIGNAL(timeout()), ui->tempWidget, SLOT(updateComponents()) );

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToModulePage()));

    connect( ui->backToHelp, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToHelpPage()));

    OnOffButton* onoff = new OnOffButton( 60, 30, this );
    onoff->setGeometry( this->width()-onoff->width()-10,
                     50,
                     onoff->width(), onoff->height());

    onoff->setState( _printer->isOn() );
    connect ( onoff, SIGNAL(released()), _printer, SLOT(toggleInter()));
    connect ( onoff, SIGNAL(released()), this, SLOT(repaintComponents()));

    ui->bedTempSlider->installEventFilter(this);
    ui->boxTempSlider->installEventFilter(this);
    ui->fanPulsor->installEventFilter(this);
    ui->fanPelletier->installEventFilter(this);
    ui->fanExtractor->installEventFilter(this);

    ui->fanExtractor->setTracking( false );
    ui->fanPelletier->setTracking( false );
    ui->fanPulsor->setTracking( false );
    ui->boxTempSlider->setTracking( false );
    ui->bedTempSlider->setTracking( false );

    repaintComponents();
}

PrinterPage::~PrinterPage()
{
    delete ui;
}

bool PrinterPage::eventFilter(QObject* watched, QEvent* event)
{
    QSlider* m_slider = dynamic_cast<QSlider*>(watched);
    if (event->type() == QEvent::MouseButtonPress )
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        m_slider->setValue(QStyle::sliderValueFromPosition(m_slider->minimum(), m_slider->maximum(), mouseEvent->x(), m_slider->width()));
    }

    return false;
}

void PrinterPage::repaintComponents()
{

    _update = true;

    ui->boxTempSpin->setValue( _printer->getTargetChamberTemp().getValue() );
    ui->boxTempSlider->setValue( _printer->getTargetChamberTemp().getValue() );
    ui->bedTempSlider->setValue( _printer->getTargetBedTemp().getValue() );
    ui->bedtempSpin->setValue( _printer->getTargetBedTemp().getValue() );

    ui->extractorSpin->setValue( _printer->fanExtractorFanSpeed() );
    ui->pulsorSpin->setValue( _printer->fanPulsorFanSpeed() );
    ui->pelletierSpin->setValue( _printer->fanPelletierSpeed() );

    ui->fanExtractor->setValue( _printer->fanExtractorFanSpeed() );
    ui->fanPulsor->setValue( _printer->fanPulsorFanSpeed() );
    ui->fanPelletier->setValue( _printer->fanPelletierSpeed() );

    ui->ledClogged->setActivated( ! _printer->wireClogged() );
    ui->tempWidget->updateComponents();

    ui->bedBox->setEnabled( _printer->isOn() );
    ui->printerboxBox->setEnabled( _printer->isOn() );
    ui->startPrint->setEnabled( _printer->isOn() );

    _update = false;
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
    _printer->setTargetBedTemp( Temperature(Config::bedTempPla()) );
    setBedActivated(true);
    repaintComponents();
}

void PrinterPage::on_absBed_clicked()
{
    _printer->setTargetBedTemp( Temperature(Config::bedTempAbs()) );
    setBedActivated(true);
    repaintComponents();
}

void PrinterPage::on_nylonBed_clicked()
{
    _printer->setTargetBedTemp( Temperature(Config::bedTempNylon()) );
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

void PrinterPage::on_startPrint_clicked()
{
    /*if ( _printerSoftware != NULL )
    {
        _printerSoftware->kill();
    }*/
    _printer->startPrinterSoftware();
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
    if ( _update ) return;
    _printer->setTargetChamberTemp( Temperature(value) );
    repaintComponents();
}
void PrinterPage::on_boxTempSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    _printer->setTargetChamberTemp( Temperature(arg1) );
    repaintComponents();
}

void PrinterPage::on_bedTempSlider_valueChanged(int value)
{
    if ( _update ) return;
    _printer->setTargetBedTemp(Temperature(value));
    repaintComponents();
}

void PrinterPage::on_bedtempSpin_valueChanged(int arg1)
{
    if ( _update ) return;
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


void PrinterPage::on_fanPelletier_valueChanged(int value)
{
    if ( _update ) return;
    _printer->setFanPelletierSpeed( value );
    repaintComponents();
}
void PrinterPage::on_pelletierSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    _printer->setFanPelletierSpeed( arg1 );
    repaintComponents();
}

void PrinterPage::on_fanPulsor_valueChanged(int value)
{
    if ( _update ) return;
    _printer->setFanPulsorFanSpeed( value );
    repaintComponents();
}

void PrinterPage::on_pulsorSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    _printer->setFanPulsorFanSpeed( arg1 );
    repaintComponents();
}

void PrinterPage::on_fanExtractor_valueChanged(int value)
{
    if ( _update ) return;
    _printer->setFanExtractorFanSpeed( value );
    repaintComponents();
}

void PrinterPage::on_extractorSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    _printer->setFanExtractorFanSpeed( arg1 );
    repaintComponents();
}

