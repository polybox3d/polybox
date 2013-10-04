#ifndef SCANNERCHECKER_H
#define SCANNERCHECKER_H

#include <QWidget>
#include <QPaintEvent>

#include "ScannerModule.h"

namespace Ui {
class SCannerChecker;
}

class SCannerChecker : public QWidget
{
    Q_OBJECT

public:
    explicit SCannerChecker(QWidget *parent = 0);
    SCannerChecker(ScannerModule* scanner, QWidget *parent = 0);
    ~SCannerChecker();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::SCannerChecker *ui;

    ScannerModule* _scanner;
};

#endif // SCANNERCHECKER_H
