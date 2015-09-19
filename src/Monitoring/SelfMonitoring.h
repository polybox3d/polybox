#ifndef SELFMONITORING_H
#define SELFMONITORING_H

#include <QTimer>
#include <QObject>
#include <QFile>
#include <QTextStream>

#include "Config.h"

class SelfMonitoring : public QObject
{
    Q_OBJECT
public:
    static SelfMonitoring* getInstance();

    static int ramUsed();
    static int cpuUsed();
    static int serialByteTransferred();

    QFile* selfMonitoringFile;
    QTextStream selfMonitoringStream;

    static void start();
    static void stop();

    QTimer _updateTimer;
signals:
    void updateUI();

public slots:

    void update();


private:
    explicit SelfMonitoring(QObject *parent = 0);
    static SelfMonitoring* SelfMonitoringInstance;

    static int _serialByteTransferred;

};

#endif // SELFMONITORING_H
