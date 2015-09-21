#ifndef MONITORINGPAGE_H
#define MONITORINGPAGE_H

#include <QWidget>

#include "Monitoring/ComputerMonitoring.h"
#include "Monitoring/SelfMonitoring.h"

namespace Ui {
class MonitoringPage;
}

class MonitoringPage : public QWidget
{
    Q_OBJECT

public:
    explicit MonitoringPage(QWidget *parent = 0);
    ~MonitoringPage();

public slots:
    void updateComputer();
    void updateSelf();

private:
    Ui::MonitoringPage *ui;
};

#endif // MONITORINGPAGE_H
