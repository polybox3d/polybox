#include "PlateCalibratorWidget.h"
#include "ui_PlateCalibratorWidget.h"

PlateCalibratorWidget::PlateCalibratorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlateCalibratorWidget)
{
    _plater = new PlaterCalibrator( this );
    ui->setupUi(this);

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), this, SLOT(goBack()));

    _update_timer.start( 100 ) ;
    connect(&_update_timer, SIGNAL(timeout()),this,SLOT(updateUi()));

}
void PlateCalibratorWidget::goBack()
{
    CHANGE_PAGE( Start );
}

PlateCalibratorWidget::~PlateCalibratorWidget()
{
    delete ui;
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

}

void PlateCalibratorWidget::on_y_plus_clicked()
{
    _plater->setRy( _plater->ry() + (ui->stepIncrementation->currentText().toFloat()) );
    cout<<(ui->stepIncrementation->currentText().toFloat())<<endl;
}

void PlateCalibratorWidget::on_y_minus_clicked()
{
    _plater->setRy( _plater->ry() - (ui->stepIncrementation->currentText().toFloat()) );
}

void PlateCalibratorWidget::on_x_minus_clicked()
{
    _plater->setRx( _plater->rx() - (ui->stepIncrementation->currentText().toFloat()) );
}

void PlateCalibratorWidget::on_x_plus_clicked()
{
    _plater->setRx( _plater->rx() + (ui->stepIncrementation->currentText().toFloat()) );
}
