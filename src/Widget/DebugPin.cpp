#include "DebugPin.h"
#include "SerialPort.h"
#include "ui_DebugPin.h"

DebugPin::DebugPin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebugPin)
{
    ui->setupUi(this);
    setupComponents();


    _updtaeTimer.start(500);
    connect(&_updtaeTimer,SIGNAL(timeout()),this,SLOT(updateComponents()));

    connect( ComModule::getInstance(this), SIGNAL(newData(QByteArray)), this, SLOT(parseData(QByteArray)) );
    this->setAttribute(Qt::WA_DeleteOnClose);
}

DebugPin::~DebugPin()
{
    delete ui;
}

void DebugPin::setupComponents()
{
    /**** Combo box For board selecter  ****/
    ui->boardCombo->addItem("Master");
    ui->boardCombo->addItem("Slave 1");
    ui->boardCombo->addItem("Slave 2");
    ui->boardCombo->addItem("Slave 3");
    ui->boardCombo->addItem("Slave 4");
    ui->boardCombo->addItem("Slave 5");

    /**** Input Output combo box  ****/
    /*ui->IOCombo->addItem("Output");
    ui->IOCombo->addItem("Input");*/

}

void DebugPin::parseData(QByteArray data)
{
    QString str(data);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    int size = str.size();
    switch ( value )
    {
    case 700:
    {
        SerialPort::nextField( str, idx);
        while ( idx < size )
        {
            if ( str[idx] == 'P' )
            {
                SerialPort::nextValue( str, idx);
                ui->pinValueInc->setText( QString::number(SerialPort::embeddedstr2l( str, idx )) );
            }
            SerialPort::nextField( str, idx);
        }
    }
        break;
    case 712:
    {
        SerialPort::nextField( str, idx);
        while ( idx < size )
        {
            if ( str[idx] == 'P' )
            {
                SerialPort::nextValue( str, idx);
                if ( SerialPort::embeddedstr2l( str, idx ) == 0 )
                {
                    ui->pinValueInc->setText("Output");
                }
                else
                {
                    ui->pinValueInc->setText("Input");
                }
            }
            SerialPort::nextField( str, idx);
        }
    }
        break;

    default:
        break;
    }

}

void DebugPin::updateComponents()
{
/*    if ( ui->IOCombo->currentIndex() == 0 )
        return;*/
    bool ok;
    ui->pinNumber->text().toInt(&ok);
    if ( ui->pinNumber->text().isEmpty() || !ok )
    {
        ui->pinValue->setText(tr("Select a value"));

    }
    else
    {
        if ( ui->readType->isChecked() )
        {
            ComModule::getInstance(this)->sendCode( QString("M712")+" P"+QString::number((ui->pinNumber->text().toInt()+(70*ui->boardCombo->currentIndex()))) );
        }
        else
        {
            ComModule::getInstance(this)->sendCode( QString("M700")+" P"+QString::number((ui->pinNumber->text().toInt()+(70*ui->boardCombo->currentIndex()))) );
        }
    }

}

void DebugPin::on_boardCombo_currentIndexChanged(int index)
{

}

void DebugPin::on_sendPinValue_clicked()
{
    bool ok;
    ui->pinNumber->text().toInt(&ok);
    if ( ui->pinNumber->text().isEmpty() || !ok )
    {
        ui->pinValue->setText("NaN");

    }
    else
    {
        ComModule::getInstance(this)->sendCode( QString("M701")+" P"+QString::number((ui->pinNumber->text().toInt()+(70*ui->boardCombo->currentIndex())))+" S"+ui->pinValue->text() );
        ui->pinValue->setText("");
    }
}

void DebugPin::on_send0_clicked()
{
    ComModule::getInstance(this)->sendCode( QString("M701")+" P"+QString::number((ui->pinNumber->text().toInt()+(70*ui->boardCombo->currentIndex())))+" S0" );
}

void DebugPin::on_send255_clicked()
{
    ComModule::getInstance(this)->sendCode( QString("M701")+" P"+QString::number((ui->pinNumber->text().toInt()+(70*ui->boardCombo->currentIndex())))+" S255" );
}

void DebugPin::on_in_clicked()
{
    ComModule::getInstance(this)->sendCode( QString("M711")+" S0" );
}

void DebugPin::on_out_clicked()
{
    ComModule::getInstance(this)->sendCode( QString("M711")+" S1" );
}

void DebugPin::on_pinNumber_editingFinished()
{
//    on_out_clicked();
}

void DebugPin::on_pinNumber_textChanged(const QString &arg1)
{
    ui->in->setChecked(false);
    ui->out->setChecked(false);
    ui->readType->setChecked(true);
}
