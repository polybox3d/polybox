#ifndef POLYBOXMODULE_H
#define POLYBOXMODULE_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QByteArray>
#include <QTimer>

#include "mcode.h"
#include "SerialPort.h"

/*#include "AbstractModule.h"
#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
#include "GlobalModule.h"
*/
#include "polyplexer.h"
#include "ClosedLoopTimer.h"
#include "Logger.h"

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



    static PolyboxModule* getInstance(QObject *parent=0);

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


signals:
    void updateHardware();


public slots:
    void hardwareTimerTimeout();


private:
    bool _connected;
    PolyboxModule(QObject *parent = 0);
    static PolyboxModule* polyboxModuleInstance;


    GlobalModule* _global;
    CNCModule* _cnc;
    LabViewModule* _labview;
    ScannerModule* _scanner;
    PrinterModule* _printer;
    static QJoystick* _joypad;
    QTimer _hardwareTimer;
    void parseMCode( QByteArray stream );

};

#endif // POLYBOXMODULE_H
