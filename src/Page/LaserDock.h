#ifndef LASERDOCK_H
#define LASERDOCK_H

#include <QDockWidget>
#include <QTimer>
#include <QMouseEvent>

#include "ScannerModule.h"

namespace Ui {
class LaserDock;
}

class LaserDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit LaserDock(ScannerModule* scanner_module, QWidget *parent = 0);
    ~LaserDock();
    bool eventFilter(QObject* watched, QEvent* event);

private slots:
    void on_onOffLaser1_clicked();

    void on_onOffLaser2_clicked();

    void repaintComponents();

    void on_laser1Slider_valueChanged(int value);

    void on_laser2Slider_valueChanged(int value);

    void on_laser1Spin_valueChanged(int arg1);

    void on_laser2Spin_valueChanged(int arg1);

private:
    QTimer _updateTimer;

    Ui::LaserDock *ui;
    ScannerModule* _scannerModule;
    bool _update;
};

#endif // LASERDOCK_H
