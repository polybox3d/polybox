#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QDockWidget>
#include <QLabel>
#include <QMessageBox>
#include <QLibraryInfo>
#include <QThread>
#include <QTcpSocket>

#include "Config.h"

#include "OpenPage.h"
#include "HelpPage.h"
#include "ModulePage.h"
#include "LabViewPage.h"
#include "PrinterPage.h"
#include "CNCPage.h"
#include "ConfigCNCPage.h"
#include "WarningPage.h"
#include "DialogConfigSoft.h"
#include "PolyboxModule.h"
#include "polyplexer.h"
#include "DialogCredits.h"
#include "DialogWidget.h"
#include "Theme.h"
#include "TCPServer.h"
#include "Led.h"
#include "PlateCalibratorWidget.h"
#include "AxisControlDock.h"
#include "ClosedLoopTimer.h"

#if !defined NO_SCAN
 #include "PolyFabScanWindow.h"
#endif

#include "pageState.h"
#include "ATUButton.h"
#include "DialogClient.h"
#include "Led.h"
#include "Logger.h"
#include "DockHost.h"

#include "MaintenanceChecker.h"

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
    static bool instanceExists();

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
    void closeEvent(QCloseEvent *event);
    void startConsoleWindow();
    void displayStatusMessage(QString mess);

signals:
    void joypadOff();
    void joypadOn(QJoystick* jopypad);

public slots:
    void toggleATU();
    void setupLanguage();
    void setupThemes();
    void destroyWindow(QObject *obj);

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

    void on_actionMode_Serveur_toggled(bool arg1);

    void on_actionStart_Client_Mode_toggled(bool arg1);

    void on_actionCalibration_Ecran_triggered();

    void on_actionCalibration_Plateau_triggered();

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
    QMainWindow* _dockHost;
    PolyFabScanWindow* _polyfabscan;
    TCPServer _tcp_server;
    Led _connectedLed;
    QLabel* _statusMessage;
};

#endif // MAINWINDOW_H

