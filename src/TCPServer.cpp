#include "TCPServer.h"

#include "MainWindow.h"

TCPServer::TCPServer(QObject *parent) :
    QObject(parent)
{
    connect( &_server, SIGNAL(newConnection()), this, SLOT(addNewConnection()));
}

void TCPServer::startListening(const QHostAddress &address, quint16 port)
{
    if (!_server.listen( address, port))
    {
        MainWindow::errorWindow( tr("Unable to start the server: %1.").arg(_server.errorString()));
        _server.close();
        return;
    }

    _udpSocket = new QUdpSocket(this);

    _timerBroadcast = new QTimer(this);
    _timerBroadcast->start( 2000 );
    connect(_timerBroadcast, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
    MainWindow::textWindow( tr("Server started."));
}

void TCPServer::broadcastDatagram()
{
    QByteArray datagram = "PolyBoxServ";
    _udpSocket->writeDatagram(datagram.data(), datagram.size(),
                             QHostAddress::Broadcast, Config::broadcastPort());
}

bool TCPServer::isListening()
{
    return _server.isListening();
}

void TCPServer::stopListening()
{
    _timerBroadcast->stop();
    _server.close();
    MainWindow::textWindow( tr("Server stopped."));
}

void TCPServer::addNewConnection()
{
    QTcpSocket* tcp_client =  new QTcpSocket( _server.nextPendingConnection() );

    MainWindow::textWindow(tr("New Client connected."));

    Connector* client = new Connector( this ) ;
    _clients.append( client );
    client->setConnector( tcp_client );

    connect( Polyplexer::getInstance(), SIGNAL(dataBasicReady(QByteArray)), client, SLOT(sendData(QByteArray)));
    connect( client, SIGNAL(dataReady(QByteArray)), Polyplexer::getInstance(), SLOT(sendDataArray(QByteArray)));
    connect( Polyplexer::getInstance(), SIGNAL(connectorClosing()), client, SLOT(close()));

}

void TCPServer::processIncomingDatas()
{
    QTcpSocket* client = dynamic_cast<QTcpSocket*>(sender());
     if( client != NULL )
     {
         QByteArray tmp;
         int a = client->bytesAvailable();
         tmp.resize(a);
         client->read( tmp.data(), tmp.size() );

     }

}
