#ifndef PRINTERCHECKER_H
#define PRINTERCHECKER_H

#include <QWidget>

#include "PrinterModule.h"

namespace Ui {
class PrinterChecker;
}

class PrinterChecker : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterChecker(QWidget *parent = 0);
    PrinterChecker(PrinterModule* printer, QWidget *parent = 0);
    ~PrinterChecker();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::PrinterChecker *ui;

    PrinterModule* _printer;
};

#endif // PRINTERCHECKER_H
