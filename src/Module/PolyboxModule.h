#ifndef POLYBOXMODULE_H
#define POLYBOXMODULE_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QByteArray>
#include <QTimer>

#include "mcode.h"
#include "SerialPort.h"

/*#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
*/
#include "polyplexer.h"
#include "ClosedLoopTimer.h"

#include "Qjoystick.h"
#include "qjoystickenumerator.h"

class CNCModule;
class LabViewModule;
class PrinterModule;
class ScannerModule;
class GlobalModule;

class PolyboxModule : public QObject
{
    Q_OBJECT
public:

    enum ConnectorType{ Serial, ServerTCP, CLientTCP, Abstract};
    enum ConnectionStatus{ Connected=0, ErrorPolyplexer=2, ErrorConnection=4, Permission=8, NotFound=16, TimeOut=32};
    static QMap<int, QString> connectionStatusMessage;


    static PolyboxModule* getInstance(QObject *parent=0);

    void initConnectionStatusMessage();
    ConnectorType connectorType() const;
    void setConnectorType( ConnectorType type);
    bool isCommonReady();
    static bool isConnected();
    bool isCncReady();
    bool isPrinterReady();
    bool isScannerReady();
    GlobalModule* globalModule();
    CNCModule* cncModule();
    LabViewModule* labViewModule();
    ScannerModule* scannerModule();
    PrinterModule* printerModule();

    static void setJoypad( QJoystick* joypad );
    static QJoystick* getJoypad();
    static bool loadJoypad();
    static void unloadJoypad();
    ConnectionStatus connection( bool blocked_thread=false);
    ConnectionStatus connectionGUI( bool blocked_thread=false);
    void setupConnection(QString path, QString port);

    AbstractClient* connector();
    void setConnector( AbstractClient* connector, ConnectorType type = Abstract );
    int error();

signals:
    void updateHardware();
    void newType(PolyboxModule::ConnectorType type);
    void newData( QByteArray stream );

public slots:
    void parseData();
    void hardwareTimerTimeout();
    void pingPong();


private:
    bool _connected;
    PolyboxModule(QObject *parent = 0);
    static PolyboxModule* polyboxModuleInstance;

    u_int8_t _numberOfMissingPingPong;
    GlobalModule* _global;
    CNCModule* _cnc;
    LabViewModule* _labview;
    ScannerModule* _scanner;
    PrinterModule* _printer;
    AbstractClient * _connector;
    Polyplexer * _polyplexer;
    static QJoystick* _joypad;
    QTimer _hardwareTimer;
    QTimer _pingPongTimer;
    void parseMCode( QByteArray stream );
    ConnectorType _connectorType;

};

#endif // POLYBOXMODULE_H
