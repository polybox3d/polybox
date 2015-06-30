#ifndef EXTRUDERDOCK_H
#define EXTRUDERDOCK_H

#include <QDockWidget>
#include <QTimer>

#include "Config.h"
#include "PrinterModule.h"

namespace Ui {
class ExtruderDock;
}

class ExtruderDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit ExtruderDock(QWidget *parent = 0);
    ~ExtruderDock();

public slots:
    void updateComponents();

private:
    Ui::ExtruderDock *ui;
    QTimer _updateTimer;
};

#endif // EXTRUDERDOCK_H
