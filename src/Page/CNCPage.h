#ifndef CNCPAGE_H
#define CNCPAGE_H

#include <QWidget>
#include <QProcess>

#include "HomeButton.h"
#include "MainWindow.h"

namespace Ui {
class CNCPage;
}
/**
 * @brief The CNCPage class Contructs a QWidget Page, diplaying all CNCInformation and controle.
 */
class CNCPage : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CNCPage Constructs the CNCPage control with a parent.
     * @param parent
     */
    explicit CNCPage(CNCModule* cncmodule, QWidget *parent = 0);
    /**
     * @brief startLinuxCNC Start LinuxCNC software as a QProcess. The process is stored in _linuxcnc attribute. POath and commadn can be modified through Config class.
     */
    void startLinuxCNC();

    void isRunning();
    ~CNCPage();

private:
    /**
     * @brief ui Graphical layer.
     */
    Ui::CNCPage *ui;
    CNCModule* _cnc;
};

#endif // CNCPAGE_H
