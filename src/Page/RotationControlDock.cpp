#include "RotationControlDock.h"
#include "ui_RotationControlDock.h"

RotationControlDock::RotationControlDock(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::RotationControlDock), _zPrevPos(0)
{
    ui->setupUi(this);
}

RotationControlDock::~RotationControlDock()
{
    delete ui;
}

void RotationControlDock::on_rotX_valueChanged(int value)
{

}

int RotationControlDock::dial2dist(int current, int prev)
{
    int delta = current - prev ;
    int dist = 0;
    if ( delta > 180 )
    {
        dist = ( 360 - delta ) * -1;
    }
    else if ( delta < -180)
    {
        dist = ( delta + 360 );
    }
    else
    {
        dist = delta;
    }
    return dist;

}

void RotationControlDock::on_rotZ_valueChanged(int value)
{

}

void RotationControlDock::changeEnableLabel( QAbstractButton* button, bool enable)
{

}

void RotationControlDock::on_rotZ_sliderReleased()
{
    QString::number(dial2dist(ui->rotZ->value(), _zPrevPos));
    _zPrevPos = ui->rotZ->value();
    MovementModule::moveRotByMask(RZAxis, _zPrevPos );

}
void RotationControlDock::on_enableX_clicked()
{
    MovementModule::setEnableRotByMask(RXAxis, ui->enableX->isChecked() );
    changeEnableLabel( ui->enableX, ui->enableX->isChecked() );
}


void RotationControlDock::on_enableY_clicked()
{
    MovementModule::setEnableRotByMask(RYAxis, ui->enableY->isChecked() );
        changeEnableLabel( ui->enableY, ui->enableY->isChecked() );
}


void RotationControlDock::on_enableZ_clicked()
{
    MovementModule::setEnableRotByMask(RZAxis, ui->enableZ->isChecked() );
    changeEnableLabel( ui->enableZ, ui->enableZ->isChecked() );
}

void RotationControlDock::on_setOriginX_clicked()
{
    ui->rotX->setSliderPosition(0);
}

void RotationControlDock::on_setOriginY_clicked()
{
    ui->rotY->setSliderPosition(0);
}

void RotationControlDock::on_rotY_sliderReleased()
{
    MovementModule::moveRotByMask( RYAxis, ui->rotY->value() );
}

void RotationControlDock::on_rotX_sliderReleased()
{
    MovementModule::moveRotByMask( RXAxis, ui->rotX->value() );
}
