#ifndef COMPUTERMONITORING_H
#define COMPUTERMONITORING_H

#include <QTimer>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <iostream>
#include <fstream>

using namespace std;

#include "Config.h"

class ComputerMonitoring : public QObject
{
#define COMPUTER_MONITORING_FILE_PREFIX "COMPUTER_MONITORING_"
    Q_OBJECT
public:
    static ComputerMonitoring* getInstance();
    int ramCurrent() const;
    int ramMax() const;
    float cpu() const;
    QList<int> diskCapacity() const;
    QList<int> diskUsage() const;
    QStringList diskLabel() const;
    int lanSpeed() const;
    void start();
    void stop();
    QString getCPUInfo();

    QFile* monitoringFile;
    QTextStream monitoringStream;

    QVector<double> ramHistory;
    QVector<double> cpuHistory;

signals:
    void updateUI();
public slots:
    void update();

private:
    explicit ComputerMonitoring(QObject *parent = 0);
    static ComputerMonitoring* ComputerMonitoringInstance;

    void updateRam();
    void updateCpu();
    void updateDisk();

    int _ramCurrent;
    int _ramMax;
    float _cpu;

    QList<int> _diskCapacity;
    QList<int> _diskUsage;
    int _lanSpeed;

    QTimer _updateTimer;
};

#endif // COMPUTERMONITORING_H
