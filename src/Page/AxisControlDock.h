#ifndef AXISCONTROLDOCK_H
#define AXISCONTROLDOCK_H

#include <QDockWidget>
#include <QMouseEvent>

#include "PolyboxModule.h"
#include "MovementModule.h"

namespace Ui {
class AxisControlDock;
}

class AxisControlDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit AxisControlDock(QWidget *parent = 0);
    ~AxisControlDock();
    bool eventFilter(QObject* watched, QEvent* event);

private slots:
    void on_XEnable_clicked();

    void on_YEnable_clicked();

    void on_ZEnable_clicked();

    void on_homeX_clicked();

    void on_yHome_clicked();

    void on_homeZ_clicked();

    void on_x_slider_valueChanged(int value);

    void on_y_slider_valueChanged(int value);

    void on_z_slider_valueChanged(int value);

private:
    Ui::AxisControlDock *ui;
    bool _update;
};

#endif // AXISCONTROLDOCK_H
