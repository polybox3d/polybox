#ifndef PRINTERSMALLUI_H
#define PRINTERSMALLUI_H

#include <QWidget>
#include "PrinterModule.h"

namespace Ui {
class PrinterSmallUI;
}

class PrinterSmallUI : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterSmallUI(QWidget *parent = 0);
    void addPrinterModule(PrinterModule* printer);
    ~PrinterSmallUI();
    void updateComponents();
private:
    Ui::PrinterSmallUI *ui;
    PrinterModule* _printer;
};

#endif // PRINTERSMALLUI_H
