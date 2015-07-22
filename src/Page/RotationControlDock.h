#ifndef ROTATIONCONTROLDOCK_H
#define ROTATIONCONTROLDOCK_H

#include <QDockWidget>

#include "MovementModule.h"

namespace Ui {
class RotationControlDock;
}

class RotationControlDock : public QWidget
{
    Q_OBJECT

public:
    explicit RotationControlDock(QWidget *parent = 0);
    ~RotationControlDock();
    int dial2dist(int current, int prev);

private slots:

    void on_rotZ_sliderReleased();

    void on_enableY_clicked();

    void on_enableX_clicked();

    void on_enableZ_clicked();

    void on_setOriginX_clicked();

    void on_setOriginY_clicked();

    void on_rotY_sliderReleased();

    void on_rotX_sliderReleased();

private:
    Ui::RotationControlDock *ui;
    int _zPrevPos;

    void changeEnableLabel(QAbstractButton* button, bool enable);
};

#endif // ROTATIONCONTROLDOCK_H
