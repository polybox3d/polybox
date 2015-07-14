#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QIODevice>
#include <QByteArray>
#include <QRegExp>
#include <QStringList>

#include <iostream>

using namespace std;

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = 0);
    void setConnector( QIODevice* connector );

signals:

public slots:
    void parseData();
    void sendDataString(QString data);
    void sendData(QByteArray data);
    void close();

signals:
    void dataReady(QByteArray data);

private:
    QIODevice* _connector;
    QByteArray _rcp_data;
    QByteArray _dataBasic;

};

#endif // CONNECTOR_H
