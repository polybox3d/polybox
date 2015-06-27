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
    return dist;

}

void RotationControlDock::on_rotZ_valueChanged(int value)
{
    // set midle of circle, so 180°
    MovementModule::setCurrentPosRotByMask( RZAxis, 180 );
    ui->zIncr->setValue( ui->rotZ->sliderPosition() );

    if ( value > 180 )
        value = (360 - value) *-1;
    if ( _zPrevPos > 180 )
        _zPrevPos = (360 - _zPrevPos) *-1 ;

    int dist = (value%180) - (_zPrevPos%180);

    MovementModule::moveRotByMask(RZAxis, 180+dist);
    _zPrevPos = value;
}

void RotationControlDock::on_rotZ_sliderReleased()
{
    ui->zIncr->setValue(dial2dist(ui->rotZ->value(), _zPrevPos));
}
