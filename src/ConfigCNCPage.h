#ifndef CONFIGCNCPAGE_H
#define CONFIGCNCPAGE_H

#include <QWidget>
#include <QString>
#include <QProcess>
#include <QMessageBox>

#include "MainWindow.h"
#include "pageState.h"

#include <iostream>

namespace Ui {
class ConfigCNCPage;
}

class ConfigCNCPage : public QWidget
{
    Q_OBJECT



public:
    explicit ConfigCNCPage(QWidget *parent = 0);
    ~ConfigCNCPage();
public slots:
    void outputReady();

private slots:
    void on_latencyHisto_clicked();

    void on_latencyPlot_clicked();

    void on_latencyTab_clicked();

    void on_configStepper_clicked();

    void on_stressCNC_clicked();

private:
    Ui::ConfigCNCPage *ui;
    QMessageBox* _message;
    QProcess* _script;
};

#endif // CONFIGCNCPAGE_H
