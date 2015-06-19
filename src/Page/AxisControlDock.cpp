#include "AxisControlDock.h"
#include "ui_AxisControlDock.h"

AxisControlDock::AxisControlDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::AxisControlDock)
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
}

void AxisControlDock::on_yHome_clicked()
{
    MovementModule::homing('Y');
}

void AxisControlDock::on_homeZ_clicked()
{
    MovementModule::homing('Z');
}

void AxisControlDock::on_x_slider_valueChanged(int value)
{

}

void AxisControlDock::on_y_slider_valueChanged(int value)
{

}

void AxisControlDock::on_z_slider_valueChanged(int value)
{

}
