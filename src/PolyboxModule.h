#ifndef POLYBOXMODULE_H
#define POLYBOXMODULE_H

#include <QObject>

#include "LabViewModule.h"
#include "CNCModule.h"
#include "ScannerModule.h"
#include "PrinterModule.h"

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
    CNCModule* cncModule();
    LabViewModule* labView();
    ScannerModule* scannerModule();
    PrinterModule* printerModule();

signals:

public slots:

private:
    bool _connected;

    CNCModule* _cnc;
    LabViewModule* _labview;
    ScannerModule* _scanner;
    PrinterModule* _printer;

};

#endif // POLYBOXMODULE_H
