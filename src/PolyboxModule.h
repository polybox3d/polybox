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
    SerialPort* port();
    static void setJoypad( QJoystick* joypad );
    static QJoystick* getJoypad();
    static bool loadJoypad();
    static void unloadJoypad();

signals:
    void updateHardware();

public slots:
    void parseData();
    void hardwareTimerTimeout();


private:
    bool _connected;

    GlobalModule* _global;
    CNCModule* _cnc;
    LabViewModule* _labview;
    ScannerModule* _scanner;
    PrinterModule* _printer;
    SerialPort * _port;
    Polyplexer * _polyplexer;
    static QJoystick* _joypad;
    QTimer _hardwareTimer;

};

#endif // POLYBOXMODULE_H
