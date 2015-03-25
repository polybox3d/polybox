#ifndef MAINTENANCECHECKER_H
#define MAINTENANCECHECKER_H

#include <QObject>
#include "MainWindow.h"
#include "Config.h"

class MaintenanceChecker : public QObject
{
    Q_OBJECT
public:
    explicit MaintenanceChecker(QObject *parent = 0);

    static bool check();

signals:

public slots:

};

#endif // MAINTENANCECHECKER_H
