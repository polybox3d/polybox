#ifndef EXTRUDERDOCK_H
#define EXTRUDERDOCK_H

#include <QDockWidget>

namespace Ui {
class ExtruderDock;
}

class ExtruderDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit ExtruderDock(QWidget *parent = 0);
    ~ExtruderDock();

private:
    Ui::ExtruderDock *ui;
};

#endif // EXTRUDERDOCK_H
