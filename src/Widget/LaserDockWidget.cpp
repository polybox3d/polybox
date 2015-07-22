#include "LaserDockWidget.h"
#include "ui_LaserDockWidget.h"


LaserDockWidget::LaserDockWidget(QWidget *parent) :
    QWidget(parent),
    _scannerModule(NULL),
    ui(new Ui::LaserDockWidget)
{
    ui->setupUi(this);
    _update = false;
    _updateTimer.start( Config::updateModuleTimer() );

    ui->laser1Slider->installEventFilter( this );
    ui->laser2Slider->installEventFilter( this );
    repaintComponents();
    connect( &_updateTimer, SIGNAL(timeout()), this, SLOT(repaintComponents()) );
}

LaserDockWidget::LaserDockWidget(ScannerModule *scanner_module, QWidget *parent) :
    QWidget(parent),
    _scannerModule(scanner_module),
    ui(new Ui::LaserDockWidget)
{
    ui->setupUi(this);
    _update = false;
    _updateTimer.start( Config::updateModuleTimer() );

    ui->laser1Slider->installEventFilter( this );
    ui->laser2Slider->installEventFilter( this );
    repaintComponents();
    connect( &_updateTimer, SIGNAL(timeout()), this, SLOT(repaintComponents()) );
}

LaserDockWidget::~LaserDockWidget()
{
    delete ui;
}

bool LaserDockWidget::eventFilter(QObject* watched, QEvent* event)
{
    QSlider* m_slider = dynamic_cast<QSlider*>(watched);
    if (event->type() == QEvent::MouseButtonPress )
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        m_slider->setValue(QStyle::sliderValueFromPosition(m_slider->minimum(), m_slider->maximum(), mouseEvent->x(), m_slider->width()));
    }

    return false;
}

void LaserDockWidget::repaintComponents()
{
    // do nothing if not visible
    if ( !this->isVisible() )
        return;
    if ( _scannerModule == NULL )
        return;
    _update = true;
    // emit signal to update scanner values
    _scannerModule->updateComponents();

    ui->groupBox->setEnabled( _scannerModule->laser0Plugged() );
    ui->groupBox_2->setEnabled( _scannerModule->laser1Plugged() );

    ui->laser1Led->setActivated( _scannerModule->laser0Power() );
    ui->laser2Led->setActivated( _scannerModule->laser1Power() );

    ui->laser1Slider->setValue( _scannerModule->laser0Power() );
    ui->laser2Slider->setValue( _scannerModule->laser1Power() );

    ui->laser1Spin->setValue( _scannerModule->laser0Power() );
    ui->laser2Spin->setValue( _scannerModule->laser1Power() );

    if ( _scannerModule->laser0Power() )        ui->onOffLaser1->setText("Off");
    else        ui->onOffLaser1->setText("On");

    if ( _scannerModule->laser1Power() )        ui->onOffLaser2->setText("Off");
    else        ui->onOffLaser2->setText("On");

    _update = false;
}
void LaserDockWidget::on_onOffLaser1_clicked()
{
    if ( _scannerModule->laser0Power() != 0 )
    {
        _scannerModule->setLaserPower(0,0);
    }
    else
    {
        _scannerModule->setLaserPower(0,100);
    }
    repaintComponents();
}

void LaserDockWidget::on_onOffLaser2_clicked()
{
    if ( _scannerModule->laser1Power() != 0 )
    {
        _scannerModule->setLaserPower(1,0);
    }
    else
    {
        _scannerModule->setLaserPower(1,100);
    }
    repaintComponents();
}

void LaserDockWidget::on_laser1Slider_valueChanged(int value)
{
    if ( _update ) return;
    _scannerModule->setLaserPower(0, value);
    repaintComponents();

}

void LaserDockWidget::on_laser2Slider_valueChanged(int value)
{
    if ( _update ) return;
    _scannerModule->setLaserPower(1, value);
    repaintComponents();
}

void LaserDockWidget::on_laser1Spin_valueChanged(int arg1)
{
    if ( _update ) return;
    _scannerModule->setLaserPower(0,arg1);
    repaintComponents();
}

void LaserDockWidget::on_laser2Spin_valueChanged(int arg1)
{
    if ( _update ) return;
    _scannerModule->setLaserPower(1,arg1);
    repaintComponents();
}
