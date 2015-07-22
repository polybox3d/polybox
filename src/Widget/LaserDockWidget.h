#ifndef LASERDOCKWIDGET_H
#define LASERDOCKWIDGET_H

#include <QDockWidget>
#include <QTimer>
#include <QMouseEvent>

#include "ScannerModule.h"

namespace Ui {
class LaserDockWidget;
}

class LaserDockWidget : public QWidget
{
    Q_OBJECT


public:
    explicit LaserDockWidget(QWidget *parent = 0);
    explicit LaserDockWidget(ScannerModule* scanner_module = NULL, QWidget *parent = 0);
    ~LaserDockWidget();
    bool eventFilter(QObject* watched, QEvent* event);
    void setScannerModule(ScannerModule* scanner){ _scannerModule = scanner; }

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

    Ui::LaserDockWidget *ui;
    ScannerModule* _scannerModule;
    bool _update;
};

#endif // LASERDOCKWIDGET_H
