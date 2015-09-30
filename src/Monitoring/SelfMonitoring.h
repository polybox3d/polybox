#ifndef SELFMONITORING_H
#define SELFMONITORING_H

#include <QTimer>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QProcess>

#include "Config.h"

class SelfMonitoring : public QObject
{
    Q_OBJECT
public:
    static SelfMonitoring* getInstance();

    double ramUsed();
    double cpuUsed();
    static int serialByteTransferred();

    QFile* selfMonitoringFile;
    QTextStream selfMonitoringStream;

    void start();
    void stop();

    QVector<double> ramHistory;
    QVector<double> cpuHistory;

signals:
    void updateUI();

public slots:

    void update();


private:
    explicit SelfMonitoring(QObject *parent = 0);

    void updateRam();
    void updateCpu();
    QTimer _updateTimer;

    static SelfMonitoring* SelfMonitoringInstance;
    static int _serialByteTransferred;

};

#endif // SELFMONITORING_H
