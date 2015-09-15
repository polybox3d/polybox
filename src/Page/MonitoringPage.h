#ifndef MONITORINGPAGE_H
#define MONITORINGPAGE_H

#include <QWidget>

namespace Ui {
class MonitoringPage;
}

class MonitoringPage : public QWidget
{
    Q_OBJECT

public:
    explicit MonitoringPage(QWidget *parent = 0);
    ~MonitoringPage();

private:
    Ui::MonitoringPage *ui;
};

#endif // MONITORINGPAGE_H
