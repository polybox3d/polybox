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

    MainWindow::textWindow( tr("Server started."));

}

bool TCPServer::isListening()
{
    return _server.isListening();
}

void TCPServer::stopListening()
{
    _server.close();
    MainWindow::textWindow( tr("Server stopped."));
}

void TCPServer::addNewConnection()
{
    TCPClient* tcp_client =  new TCPClient( _server.nextPendingConnection() );
    _clients.append( tcp_client );
    tcp_client->startConnection();

    MainWindow::textWindow(tr("New Client connected."));
    connect( tcp_client, SIGNAL(disconnected()), this, SLOT(deleteLater()));
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
