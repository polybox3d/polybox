#ifndef DOCKHOST_H
#define DOCKHOST_H

#include <QMainWindow>

#include "AxisControlDock.h"
#include "RotationControlDock.h"
#include "LaserDock.h"

namespace Ui {
class DockHost;
}

class DockHost : public QMainWindow
{
    Q_OBJECT

public:
    explicit DockHost(QWidget *parent = 0);
    ~DockHost();

private:
    Ui::DockHost *ui;
};

#endif // DOCKHOST_H
