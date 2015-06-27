#ifndef ROTATIONCONTROLDOCK_H
#define ROTATIONCONTROLDOCK_H

#include <QDockWidget>

#include "MovementModule.h"

namespace Ui {
class RotationControlDock;
}

class RotationControlDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit RotationControlDock(QWidget *parent = 0);
    ~RotationControlDock();
    int dial2dist(int current, int prev);

private slots:
    void on_rotX_valueChanged(int value);

    void on_rotZ_valueChanged(int value);

    void on_rotZ_sliderReleased();

private:
    Ui::RotationControlDock *ui;
    int _zPrevPos;
};

#endif // ROTATIONCONTROLDOCK_H
