#include "ComputerMonitoring.h"

ComputerMonitoring* ComputerMonitoring::ComputerMonitoringInstance = NULL;

ComputerMonitoring* ComputerMonitoring::getInstance()
{
    if ( ComputerMonitoringInstance == NULL )
    {
        ComputerMonitoringInstance = new ComputerMonitoring();
    }
    return ComputerMonitoringInstance;
}

ComputerMonitoring::ComputerMonitoring(QObject *parent) :
    QObject(parent),
    _ramCurrent(0),
    _ramMax(4000000),
    _cpu(0),
    _lanSpeed(0)
{
      connect(&_updateTimer, SIGNAL(timeout()), this, SLOT(update()));

      this->start();
}

void ComputerMonitoring::update()
{

}

void ComputerMonitoring::start()
{
    ComputerMonitoring::getInstance()->monitoringFile = new QFile(Config::pathToMonitoring());
    ComputerMonitoring::getInstance()->monitoringFile->open(QIODevice::WriteOnly | QIODevice::Text);
    ComputerMonitoring::getInstance()->monitoringStream.setDevice( ComputerMonitoring::getInstance()->monitoringFile );
    ComputerMonitoring::getInstance()->monitoringStream << "-----------[Start Monitoring for session : "+QSettings().value("LOG/nbrExec").toString()+"]--------------\n";

    ComputerMonitoring::getInstance()->monitoringStream.flush();

    _updateTimer.start( Config::computerMonitoringDelay() );
}

void ComputerMonitoring::stop()
{
    _updateTimer.stop();
}

int ComputerMonitoring::ramCurrent() const
{

    return _ramCurrent;
}

int ComputerMonitoring::ramMax() const
{
    return _ramMax;
}

int ComputerMonitoring::cpu() const
{
    return _cpu;
}

QList<int> ComputerMonitoring::diskCapacity() const
{
    return _diskCapacity;
}

QList<int> ComputerMonitoring::diskUsage() const
{
    return _diskUsage;
}

int ComputerMonitoring::lanSpeed() const
{
    return _lanSpeed;
}
