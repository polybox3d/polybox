#ifndef CONFIGCNCPAGE_H
#define CONFIGCNCPAGE_H

#include <QWidget>
#include <QString>
#include <QProcess>
#include <QMessageBox>

#include "MainWindow.h"
#include "pageState.h"

#include <iostream>

using namespace std;

namespace Ui {
class ConfigCNCPage;
}
/**
 * @brief The ConfigCNCPage class Provides a Page to display CNCConfiguration. Allow the user to start latency test, run stepper configuration or stress the machine.
 */
class ConfigCNCPage : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief ConfigCNCPage Constructs a page based on QWidget with a parent.
     * @param parent
     */
    explicit ConfigCNCPage(QWidget *parent = 0);
    ~ConfigCNCPage();
public slots:
    /**
     * @brief outputReady USELESS
     */
    void outputReady();

private slots:
    /**
     * @brief on_latencyHisto_clicked When the user click on start histogram latency test. Open the test as QProcess. The test check latency for real-time control CNC. Value between 5µs and 60 is quite good.
     */
    void on_latencyHisto_clicked();
    /**
     * @brief on_latencyPlot_clicked When the user click on start plot latency test. Open the test as QProcess.
     */
    void on_latencyPlot_clicked();
    /**
     * @brief on_latencyTab_clicked When the user click on start latency test. Open the test as QProcess.
     */
    void on_latencyTab_clicked();
    /**
     * @brief on_configStepper_clicked Calles when the user click on start stepper configuraton. Open th eLinuxCNC stepper configuration wizard as QProcess
     */
    void on_configStepper_clicked();
    /**
     * @brief on_stressCNC_clicked Start a stress test. No output, only sending soem GCode to the target.
     */
    void on_stressCNC_clicked();

    void on_startJoypadOverlay_clicked();

private:
    Ui::ConfigCNCPage *ui;
    QMessageBox* _message;
    /**
     * @brief _script Hold the pending script as QProcess
     */
    QProcess* _script;
};

#endif // CONFIGCNCPAGE_H
