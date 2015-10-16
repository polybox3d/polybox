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

public slots:

    void updateComponents();

private slots:
    void on_XEnable_clicked();

    void on_YEnable_clicked();

    void on_ZEnable_clicked();

    void on_homeX_clicked();

    void on_yHome_clicked();

    void on_homeZ_clicked();

    void on_speedX_editingFinished();

    void on_speedY_editingFinished();

    void on_speedZ_editingFinished();

    void on_x_slider_sliderReleased();

    void on_y_slider_sliderReleased();

    void on_z_slider_sliderReleased();

private:
    Ui::AxisControlDock *ui;
    bool _update;

    float _xSpeed;
    float _ySpeed;
    float _zSpeed;
};

#endif // AXISCONTROLDOCK_H
