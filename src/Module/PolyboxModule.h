#ifndef POLYBOXMODULE_H
#define POLYBOXMODULE_H

#include <QObject>
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
    explicit PolyboxModule(QObject *parent = 0);
    bool isCommonReady();
    bool isConnected();
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
    bool connectToPrinter();
    bool connectToPrinter(QString path, QString port);

    /** @deprecated **/
    SerialPort* port();

signals:
    void updateHardware();

public slots:
    void parseData();
    void hardwareTimerTimeout();
    void pingPong();


private:
    bool _connected;

    u_int8_t _numberOfMissingPingPong;
    GlobalModule* _global;
    CNCModule* _cnc;
    LabViewModule* _labview;
    ScannerModule* _scanner;
    PrinterModule* _printer;
    SerialPort * _port;
    Polyplexer * _polyplexer;
    static QJoystick* _joypad;
    QTimer _hardwareTimer;
    QTimer _pingPongTimer;
    void parseMCode( QByteArray stream );

};

#endif // POLYBOXMODULE_H
