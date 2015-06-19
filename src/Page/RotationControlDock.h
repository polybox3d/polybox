#ifndef ROTATIONCONTROLDOCK_H
#define ROTATIONCONTROLDOCK_H

#include <QDockWidget>

namespace Ui {
class RotationControlDock;
}

class RotationControlDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit RotationControlDock(QWidget *parent = 0);
    ~RotationControlDock();

private:
    Ui::RotationControlDock *ui;
};

#endif // ROTATIONCONTROLDOCK_H
