#ifndef POLYPLEXER_H
#define POLYPLEXER_H

#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QString>
#include <QProcess>

#include "Config.h"

#include "SerialPort.h"
#include "ClosedLoopTimer.h"


class Polyplexer : public QObject
{
    Q_OBJECT
public:
#define DEAMON_POLY_POLYPLEXER "/dev/ttyDEAMONPOLY"
#define DEAMON_PRINTER_POLYPLEXER "/dev/ttyDEAMONPRINTER"

    enum ConnectorType {
        Noone, Serial, Tcp
    };
    enum ConnectionStatus{ Connected=0, ErrorPolyplexer=2, ErrorConnection=4, Permission=8, NotFound=16, TimeOut=32, NothingToDo=64};

    ~Polyplexer();
    static Polyplexer* getInstance(QObject* parent = NULL);

    /** Connection **/
    static bool isConnected();
    static ConnectorType connectorType ();
    static void send(QString data);
    QIODevice* connector();

    void setConnector(QIODevice* connector);
    void setConnectorType(ConnectorType connector_type);
    Polyplexer::ConnectionStatus start(QIODevice* connector, ConnectorType connector_type);
    Polyplexer::ConnectionStatus start(ConnectorType connector_type);

    /** Data & Parse **/
    QByteArray dataPolybox();
    QByteArray dataBasic();


signals:
    void dataPolyboxReady(QByteArray data);
    void dataBasicReady(QByteArray data);
    void newType(Polyplexer::ConnectorType);

public slots:
    void parseData();
    void sendData(QString data);
    void disconnect();



private:

    explicit Polyplexer(QObject *parent=NULL);
    static Polyplexer* _instance;

    QIODevice* _connector;
    QByteArray _rcp_data;
    QByteArray _dataBasic;
    QByteArray _dataPolybox;
    ConnectorType _connectorType;


};

#endif // POLYPLEXER_H
