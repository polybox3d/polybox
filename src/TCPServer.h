#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

#include "TCPClient.h"

class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = 0);
    void startListening(const QHostAddress &address, quint16 port);
    bool isListening();
    void stopListening();

signals:

public slots:
    void addNewConnection();
    void processIncomingDatas();

private:
    QTcpServer _server;
    QList<TCPClient*> _clients;

};

#endif // TCPSERVER_H
