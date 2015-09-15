#ifndef COMPUTERMONITORING_H
#define COMPUTERMONITORING_H

#include <QTimer>
#include <QObject>
#include <QFile>
#include <QTextStream>

#include "Config.h"

class ComputerMonitoring : public QObject
{
#define COMPUTER_MONITORING_FILE_PREFIX "COMPUTER_MONITORING_"
    Q_OBJECT
public:
    static ComputerMonitoring* getInstance();
    int ramCurrent() const;
    int ramMax() const;
    int cpu() const;
    QList<int> diskCapacity() const;
    QList<int> diskUsage() const;
    int lanSpeed() const;
    void start();
    void stop();

    QFile* monitoringFile;
    QTextStream monitoringStream;


signals:

public slots:
    void update();

private:
    explicit ComputerMonitoring(QObject *parent = 0);
    static ComputerMonitoring* ComputerMonitoringInstance;

    int _ramCurrent;
    int _ramMax;
    int _cpu;
    QList<int> _diskCapacity;
    QList<int> _diskUsage;
    int _lanSpeed;

    QTimer _updateTimer;
};

#endif // COMPUTERMONITORING_H
