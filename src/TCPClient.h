#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QIODevice>
#include <QTcpSocket>

#include "AbstractClient.h"

class TCPClient : public AbstractClient
{
    Q_OBJECT
public:
    explicit TCPClient(QObject *parent = 0);
    TCPClient(QTcpSocket* sock, QObject *parent = 0);

    void setTCPSocket(QTcpSocket* sock);
    QTcpSocket* getConnector();

signals:

public slots:

};

#endif // TCPCLIENT_H
