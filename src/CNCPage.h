#ifndef CNCPAGE_H
#define CNCPAGE_H

#include <QWidget>
#include <QProcess>

#include "HomeButton.h"
#include "MainWindow.h"

namespace Ui {
class CNCPage;
}

class CNCPage : public QWidget
{
    Q_OBJECT

public:
    explicit CNCPage(QWidget *parent = 0);

    void startLinuxCNC();
    ~CNCPage();

private:
    Ui::CNCPage *ui;
    QProcess* _linuxcnc;
};

#endif // CNCPAGE_H
