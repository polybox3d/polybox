#include "TCPServer.h"

TCPServer::TCPServer(QObject *parent) :
    QObject(parent)
{
}

void TCPServer::startListening()
{
    if (!_server.listen()) {
            /*QMessageBox::critical(this, tr("Fortune Server"),
                                  tr("Unable to start the server: %1.")
                                  .arg(_server.errorString()));**/
            _server.close();
            return;
        }

        connect( &_server, SIGNAL(newConnection()), this, SLOT(addNewConnection()));

}

void TCPServer::addNewConnection()
{
    QTcpSocket* client = _server.nextPendingConnection();
    _clients.append( client );

    connect( client, SIGNAL(disconnected()), this, SLOT(deleteLater()));
    connect( client, SIGNAL(readyRead()), this, SLOT(processIncomingDatas()));

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
