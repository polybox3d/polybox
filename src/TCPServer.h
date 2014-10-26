#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

#include "AbstractClient.h"

class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = 0);
    void startListening();

signals:

public slots:
    void addNewConnection();
    void processIncomingDatas();

private:
    QTcpServer _server;
    QList<QTcpSocket*> _clients;

};

#endif // TCPSERVER_H
