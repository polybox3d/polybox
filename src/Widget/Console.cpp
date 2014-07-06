#include "Console.h"
#include "SerialPort.h"
#include "ui_Console.h"

Console::Console(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Console)
{
    ui->setupUi(this);
    connect( SerialPort::getSerial(), SIGNAL(dataReady()), this, SLOT(parseData()) );
}

Console::~Console()
{
    delete ui;
}

void Console::parseData()
{
    ui->displaySerial->append(SerialPort::getSerial()->datas());
    //QString str(datas);
}

void Console::on_sendCodeButton_clicked()
{
    SerialPort::getSerial()->sendCode( ui->inputCode->text() );
    ui->inputCode->setText("");
}

void Console::on_inputCode_returnPressed()
{
    SerialPort::getSerial()->sendCode( ui->inputCode->text() );
    ui->inputCode->setText("");
}
