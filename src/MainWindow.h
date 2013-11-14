#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QDockWidget>

#include "Config.h"

#include "OpenPage.h"
#include "HelpPage.h"
#include "ModulePage.h"
#include "LabViewPage.h"
#include "PrinterPage.h"
#include "CNCPage.h"
#include "ConfigCNCPage.h"
#include "WarningPage.h"
#include "DynamicTestPage.h"
#include "PolyboxModule.h"

#include "fsmainwindow.h"
#include "pageState.h"

namespace Ui {
class MainWindow;
}

#define CHANGE_PAGE MainWindow::getMainWindow()->changeStatePage


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    static MainWindow* getMainWindow();

    ~MainWindow();
public slots:
    void changeStatePage( PageState new_state );
    void backToModulePage();
    void backToHelpPage();
    void startCamera();
    void updateHardware();

signals:
    void joypadOff();
    void joypadOn(QJoystick* jopypad);
private slots:
    void on_actionCNC_triggered();

    void on_actionImprimante_triggered();

    void on_actionScanner_triggered();

    void on_actionLabView_triggered();

    void on_actionActiver_Manette_triggered();

    void on_actionLabView_dock_triggered();

private:
    void updateStatePage();
    void setupWebcamMenu();
    void setupSerialMenu();
    static MainWindow* mainwindow;

    Ui::MainWindow *ui;
    PageState _currentState;
    PageState _previousState;
    PolyboxModule* _polybox;
    bool _joypadActivated;
    QProcess* _webcam;

};

#endif // MAINWINDOW_H

