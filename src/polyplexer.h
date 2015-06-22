#ifndef POLYPLEXER_H
#define POLYPLEXER_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QString>
#include <QProcess>

#include "Config.h"

#include "SerialPort.h"


class Polyplexer : public QObject
{
    Q_OBJECT
public:
#define DEAMON_POLY_POLYPLEXER "/dev/ttyDEAMONPOLY"
#define DEAMON_PRINTER_POLYPLEXER "/dev/ttyDEAMONPRINTER"

    enum ConnectorType {
        Noone, Serial, Tcp
    };

    ~Polyplexer();
    static Polyplexer* getInstance(QObject* parent = NULL);

    /** Connection **/
    static bool isConnected();
    static ConnectorType connectorType ();
    static void send(QString data);

    void setConnector(QIODevice* connector);
    void setConnectorType(ConnectorType connector_type);
    bool start(QIODevice* connector, ConnectorType connector_type);

    /** Data & Parse **/
    QByteArray dataPolybox();
    QByteArray dataBasic();


signals:
    QByteArray dataPolyboxReady();
    QByteArray dataBasicReady();

public slots:
    void parseData();
    void sendData(QString data);
    void disconnect();



private:

    explicit Polyplexer(QObject *parent);
    static Polyplexer* _instance;

    QIODevice* _connector;
    QByteArray _rcp_data;
    QByteArray _dataBasic;
    QByteArray _dataPolybox;
    ConnectorType _connectorType;


};

#endif // POLYPLEXER_H
