#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QDockWidget>
#include <QLabel>
#include <QMessageBox>
#include <QLibraryInfo>
#include <QThread>

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
#include "DialogConfigSoft.h"
#include "PolyboxModule.h"
#include "polyplexer.h"
#include "DialogCredits.h"
#include "Theme.h"

#if !defined NO_SCAN
 #include "fsmainwindow.h"
#endif

#include "pageState.h"
#include "ATUButton.h"

namespace Ui {
class MainWindow;
}

#define CHANGE_PAGE MainWindow::getMainWindow()->changeStatePage


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Qt::WindowFlags window_flags = Qt::Widget, QWidget *parent=0);

    static MainWindow* getMainWindow();
    static void errorWindow(QString errorText);
    static void textWindow(QString text);
    static void restartApp();

    ~MainWindow();
public slots:
    void changeStatePage( PageState new_state );
    void backToModulePage();
    void backToHelpPage();
    void startCamera();
    void startConnexion();
    void updateHardware();
    void translateApp();
    void changeTheme();

    void startConsoleWindow();

signals:
    void joypadOff();
    void joypadOn(QJoystick* jopypad);

public slots:
    void toggleATU();
    void setupLanguage();
    void setupThemes();

private slots:
    void on_actionCNC_triggered();

    void on_actionImprimante_triggered();

    void on_actionScanner_triggered();

    void on_actionLabView_triggered();

    void on_actionActiver_Manette_triggered();

    void on_actionLabView_dock_triggered();

    void on_actionConsole_triggered();

    void on_actionParametres_triggered();

    void on_actionCredits_triggered();

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
    bool _atuON;
    ATUButton* _atu;
    QDockWidget* _dockLV;
    QDockWidget* _dockCNC;
};

#endif // MAINWINDOW_H

