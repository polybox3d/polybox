#include "DialogClient.h"
#include "ui_DialogClient.h"

DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);
    this->setWindowTitle( tr("Remote Connection") );
    ui->port->setText( QString::number(Config::broadcastPort()) );
    ui->address->setText( Config::broadcastIP() );


    _udpSocket = new QUdpSocket(this);
    _udpSocket->bind(Config::broadcastPort(), QUdpSocket::ShareAddress);

    connect(_udpSocket, SIGNAL(readyRead()),
            this, SLOT(processPendingDatagrams()));
}

void DialogClient::processPendingDatagrams()
{
    while (_udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize( _udpSocket->pendingDatagramSize() );
        _udpSocket->readDatagram(datagram.data(), datagram.size());
        ui->listServers->clear();
        ui->listServers->addItem(datagram.data());
        //statusLabel->setText(tr("Received datagram: \"%1\"")
        //                     .arg(datagram.data()));
        ui->connect->setEnabled( true );
    }
}

DialogClient::~DialogClient()
{
    delete ui;
}

void DialogClient::on_close_clicked()
{
    this->reject();
}
