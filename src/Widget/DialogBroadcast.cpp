#include "DialogBroadcast.h"
#include "ui_DialogBroadcast.h"

DialogBroadcast::DialogBroadcast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBroadcast)
{
    ui->setupUi(this);
    ui->IP->setText( Config::broadcastIP() );
    ui->port->setText( QString::number(Config::broadcastPort()) );
}

DialogBroadcast::~DialogBroadcast()
{
    delete ui;
}

void DialogBroadcast::on_closeButton_clicked()
{
    this->reject();
}

void DialogBroadcast::on_broadcastButton_clicked()
{
    bool conv_ok;
    int port = ui->port->text().toInt( &conv_ok );
    if ( conv_ok )
    {
        this->done( START_BROADCAST );
    }
}

void DialogBroadcast::on_port_editingFinished()
{
    bool conv_ok;
    int port = ui->port->text().toInt( &conv_ok );
    if ( conv_ok )
    {
        Config::setBroadcastPort( port );
    }
    else
    {
        MainWindow::errorWindow(tr("You must enter a port number."));
    }
}
