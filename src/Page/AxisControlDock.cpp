#include "AxisControlDock.h"
#include "ui_AxisControlDock.h"

AxisControlDock::AxisControlDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::AxisControlDock), _xSpeed(80), _ySpeed(80), _zSpeed(80)
{
    ui->setupUi(this);
    ui->x_slider->setMaximum( TABLE_SIZE_X);
    ui->y_slider->setMaximum( TABLE_SIZE_Y);
    ui->z_slider->setMaximum( TABLE_SIZE_Z);

    ui->x_slider->installEventFilter(this);
    ui->y_slider->installEventFilter(this);
    ui->z_slider->installEventFilter(this);

    ui->x_slider->setTracking( false );
    ui->y_slider->setTracking( false );
    ui->z_slider->setTracking( false );
}

AxisControlDock::~AxisControlDock()
{
    delete ui;
}

bool AxisControlDock::eventFilter(QObject* watched, QEvent* event)
{
    QSlider* m_slider = dynamic_cast<QSlider*>(watched);
    if (event->type() == QEvent::MouseButtonPress )
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        m_slider->setValue(QStyle::sliderValueFromPosition(m_slider->minimum(), m_slider->maximum(), mouseEvent->x(), m_slider->width()));
    }

    return false;
}

void AxisControlDock::on_XEnable_clicked()
{
    MovementModule::disableAllMotors();
    MovementModule::moveAxisByMask(ZAxis|YAxis,true, 0.1, 1000);
}

void AxisControlDock::on_YEnable_clicked()
{
    MovementModule::disableAllMotors();
    MovementModule::moveAxisByMask(XAxis|ZAxis,true, 0.1, 1000);
}

void AxisControlDock::on_ZEnable_clicked()
{
    MovementModule::disableAllMotors();
    MovementModule::moveAxisByMask(XAxis|YAxis,true, 0.1, 1000);
}

void AxisControlDock::on_homeX_clicked()
{
    MovementModule::homing('X');
    ui->x_slider->setEnabled( true );
    ui->x_spin->setEnabled( true );
}

void AxisControlDock::on_yHome_clicked()
{
    MovementModule::homing('Y');
    ui->y_slider->setEnabled( true );
    ui->y_spin->setEnabled( true );
}

void AxisControlDock::on_homeZ_clicked()
{
    MovementModule::homing('Z');
    ui->z_slider->setEnabled( true );
    ui->z_spin->setEnabled( true );
}

void AxisControlDock::on_x_slider_sliderReleased()
{
    MovementModule::moveAxis( XAxis, false, ui->x_slider->value(), _xSpeed  );
}

void AxisControlDock::on_y_slider_sliderReleased()
{
    MovementModule::moveAxis( YAxis, false, ui->y_slider->value(), _ySpeed );
}

void AxisControlDock::on_z_slider_sliderReleased()
{
    MovementModule::moveAxis( ZAxis, false, ui->z_slider->value(), _zSpeed );
}

void AxisControlDock::on_speedX_editingFinished()
{
    _xSpeed = ui->speedX->value();
}

void AxisControlDock::on_speedY_editingFinished()
{
    _ySpeed = ui->speedY->value();
}

void AxisControlDock::on_speedZ_editingFinished()
{
    _zSpeed = ui->speedZ->value();
}
