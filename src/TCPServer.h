#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QList>

#include "TCPClient.h"

class TCPServer : public QObject
{
    Q_OBJECT
public:
    //static QList<TCPServer getAvalaibleServers( const QHostAddress &address, quint16 port );

    explicit TCPServer(QObject *parent = 0);
    void startListening(const QHostAddress &address, quint16 port);
    bool isListening();
    void stopListening();

signals:

public slots:
    void addNewConnection();
    void processIncomingDatas();
    void broadcastDatagram();

private:
    QTcpServer _server;
    QUdpSocket* _udpSocket;
    QTimer* _timerBroadcast;
    QList<TCPClient*> _clients;

};

#endif // TCPSERVER_H
