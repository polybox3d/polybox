#include "Console.h"
#include "SerialPort.h"
#include "ui_Console.h"

Console::Console(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Console)
{
    _displayInput = false;
    _displayOutput = false;
    ui->setupUi(this);
    connect( ComModule::getInstance(), SIGNAL(newData(QByteArray)), this, SLOT(parseData(QByteArray)) );
    connect( ComModule::getInstance(), SIGNAL(disconnected()), this, SLOT(deleteLater()) );
    connect( ComModule::getInstance(), SIGNAL(dataWritten(QString)), this, SLOT(dataWritten(QString)) );
}

Console::~Console()
{
    delete ui;
}

void Console::parseData(QByteArray data)
{
    /** User doesn't want to display input data **/
    if ( ! ui->inputCB->isChecked() )
        return;
    /** Clear buffer sometime **/
    if (ui->displaySerial->toPlainText().size() > 100000000)
    {
        ui->displaySerial->clear();
    }
    /** append data with specific color **/
    ui->displaySerial->setTextColor( QColor( "green" ) );
    ui->displaySerial->append( data );
}

void Console::dataWritten(QString data)
{
    /** User doesn't want to display output data **/
    if ( ! ui->outputCB->isChecked() )
        return;
    /** Clear buffer sometime **/
    if (ui->displaySerial->toPlainText().size() > 100000000)
    {
        ui->displaySerial->clear();
    }
    /** append data with specific color **/
    ui->displaySerial->setTextColor( QColor( "yellow" ) );
    ui->displaySerial->append( data );
}

void Console::on_sendCodeButton_clicked()
{
    ComModule::getInstance()->sendCode( ui->inputCode->text() );
    ui->inputCode->setText("");
}

void Console::on_inputCode_returnPressed()
{
    ComModule::getInstance()->sendCode( ui->inputCode->text() );
    ui->inputCode->setText("");
}

void Console::on_clearLog_clicked()
{
    ui->displaySerial->clear();
}

void Console::on_scrollToTop_clicked()
{
    ui->displaySerial->moveCursor(QTextCursor::Start);
    ui->displaySerial->ensureCursorVisible();

    QScrollBar *vScrollBar = ui->displaySerial->verticalScrollBar();
    vScrollBar->triggerAction(QScrollBar::SliderToMinimum);
}

void Console::on_scrollToBot_clicked()
{

    ui->displaySerial->moveCursor(QTextCursor::End);
    ui->displaySerial->ensureCursorVisible();

    QScrollBar *vScrollBar = ui->displaySerial->verticalScrollBar();
    vScrollBar->triggerAction(QScrollBar::SliderToMaximum);
}

void Console::on_outputCB_toggled(bool checked)
{
    _displayOutput = checked;
}

void Console::on_inputCB_toggled(bool checked)
{
    _displayInput = checked;
}
