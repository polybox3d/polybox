#include "PlateCalibratorWidget.h"
#include "ui_PlateCalibratorWidget.h"

PlateCalibratorWidget::PlateCalibratorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlateCalibratorWidget)
{
    _plater = new PlaterCalibrator( PolyboxModule::getInstance(), this );
    ui->setupUi(this);

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), this, SLOT(goBack()));

    /*_update_timer.start( 100 ) ;
   connect(&_update_timer, SIGNAL(timeout()),this,SLOT(updateUi()));
   */
    connect(_plater, SIGNAL(updateUI()),this,SLOT(updateUi()));

}
void PlateCalibratorWidget::goBack()
{
    CHANGE_PAGE( Start );
}

PlateCalibratorWidget::~PlateCalibratorWidget()
{
    delete ui;
}

void PlateCalibratorWidget::moveMotorAngle(int axes_id, float angle)
{
    PolyboxModule::getInstance()->connector()->sendMCode( QString::number(MCODE_GLOBAL_MOVE_MOTOR_ANGLE)+" P"+QString::number(axes_id)+" S"+QString::number(angle) );
}

void PlateCalibratorWidget::updateUi()
{
    if ( !Config::bypassCheck() )
    {
        ui->plate->setEnabled( PolyboxModule::getInstance()->isConnected() );
        ui->x_minus->setEnabled( PolyboxModule::getInstance()->isConnected() );
        ui->x_plus->setEnabled( PolyboxModule::getInstance()->isConnected() );

        ui->y_minus->setEnabled( PolyboxModule::getInstance()->isConnected() );
        ui->y_plus->setEnabled( PolyboxModule::getInstance()->isConnected() );
    }
    ui->xValue->setText( QString::number(_plater->rx()) );
    ui->yValue->setText( QString::number(_plater->ry()) );

    ui->axValue->setText( QString::number(_plater->ax()) );
    ui->ayValue->setText( QString::number(_plater->ay()) );

}

void PlateCalibratorWidget::on_y_plus_clicked()
{
    moveMotorAngle(1, (ui->stepIncrementation->currentText().toFloat()) );
    //_plater->setRy( _plater->ry() + (ui->stepIncrementation->currentText().toFloat()) );
    //updateUi();
}

void PlateCalibratorWidget::on_y_minus_clicked()
{
    moveMotorAngle(1, (ui->stepIncrementation->currentText().toFloat())*-1.0 );
    /*_plater->setRy( _plater->ry() - (ui->stepIncrementation->currentText().toFloat()) );
    updateUi();*/
}

void PlateCalibratorWidget::on_x_minus_clicked()
{
    moveMotorAngle(0, (ui->stepIncrementation->currentText().toFloat())*-1.0 );
    /*_plater->setRx( _plater->rx() - (ui->stepIncrementation->currentText().toFloat()) );
    updateUi();*/
}

void PlateCalibratorWidget::on_x_plus_clicked()
{
    moveMotorAngle(0, (ui->stepIncrementation->currentText().toFloat()) );
    /*_plater->setRx( _plater->rx() + (ui->stepIncrementation->currentText().toFloat()) );
    updateUi();*/
}

void PlateCalibratorWidget::on_setCurrentOrigin_clicked()
{
    _plater->defineOffsetFromCurrentPos();
}

void PlateCalibratorWidget::on_startCalibration_clicked()
{
    LevelingWizard *lw = new LevelingWizard();
    lw->show();
}
