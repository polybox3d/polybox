#ifndef PRINTERCHECKER_H
#define PRINTERCHECKER_H

#include <QWidget>

namespace Ui {
class PrinterChecker;
}

class PrinterChecker : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterChecker(QWidget *parent = 0);
    ~PrinterChecker();

private:
    Ui::PrinterChecker *ui;
};

#endif // PRINTERCHECKER_H
