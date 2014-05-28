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

    connect( SerialPort::getSerial(), SIGNAL(dataReady()), this, SLOT(parseData()) );
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
    ui->IOCombo->addItem("Output");
    ui->IOCombo->addItem("Input");

}

void DebugPin::parseData()
{
    QByteArray data = SerialPort::getSerial()->datas();

}

void DebugPin::updateComponents()
{
    if ( ui->IOCombo->currentIndex() == 0 )
        return;
    bool ok;
    ui->pinNumber->text().toInt(&ok);
    if ( ui->pinNumber->text().isEmpty() || !ok )
    {
        ui->pinValue->setText("Select a pin");

    }
    else
    {
        SerialPort::getSerial()->sendCode( QString("M700")+" P"+QString::number((ui->pinNumber->text().toInt()+(68*ui->boardCombo->currentIndex()))) );
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
        SerialPort::getSerial()->sendCode( QString("M701")+" P"+QString::number((ui->pinNumber->text().toInt()+(68*ui->boardCombo->currentIndex())))+" S"+ui->pinValue->text() );
        ui->pinValue->setText("");
    }
}
