#ifndef MONITORINGPAGE_H
#define MONITORINGPAGE_H

#include <QWidget>

#include "Monitoring/ComputerMonitoring.h"
#include "Monitoring/SelfMonitoring.h"
#include "../externals/QCustomPlot/qcustomplot.h"

namespace Ui {
class MonitoringPage;
}

class MonitoringPage : public QWidget
{
    Q_OBJECT

public:
    explicit MonitoringPage(QWidget *parent = 0);
    ~MonitoringPage();

    QVector<double> generateXAxis(int items);

public slots:
    void updateComputer();
    void updateSelf();

private:
    void initializeComputerGraphs();
    void initializeSelfGraphs();
    void initializeSelfInfos();
    Ui::MonitoringPage *ui;

    int _currentComputerTick;
    int _currentSelfTick;
};

#endif // MONITORINGPAGE_H
