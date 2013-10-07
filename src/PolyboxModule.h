#ifndef POLYBOXMODULE_H
#define POLYBOXMODULE_H

#include <QObject>

#include "mcode.h"
#include "SerialPort.h"

/*#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"
*/


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
    LabViewModule* labView();
    ScannerModule* scannerModule();
    PrinterModule* printerModule();
    SerialPort* port();

signals:

public slots:

private:
    bool _connected;

    GlobalModule* _global;
    CNCModule* _cnc;
    LabViewModule* _labview;
    ScannerModule* _scanner;
    PrinterModule* _printer;
    SerialPort * _port;

};

#endif // POLYBOXMODULE_H
