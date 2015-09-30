#include "SelfMonitoring.h"

SelfMonitoring* SelfMonitoring::SelfMonitoringInstance = NULL;

SelfMonitoring* SelfMonitoring::getInstance()
{
    if ( SelfMonitoringInstance == NULL )
    {
        SelfMonitoringInstance = new SelfMonitoring();
    }
    return SelfMonitoringInstance;
}

SelfMonitoring::SelfMonitoring(QObject *parent) :
    QObject(parent)
{
    connect(&_updateTimer, SIGNAL(timeout()), this, SLOT(update()));
}


void SelfMonitoring::updateRam()
{
    QProcess process;
    process.start("/bin/bash -c  \"pidstat -r | grep polybox | awk '{print $8}' | tr -d '\n' | tr ',' '.' \"");
    process.waitForFinished();
    this->ramHistory.append( process.readAllStandardOutput().toFloat() );
}

void SelfMonitoring::updateCpu()
{
    /**  apt-get install sysstat **/

    QProcess process;
    process.start("/bin/bash -c  \"pidstat | grep polybox | awk '{print $7}' | tr -d '\n' | tr ',' '.' \"");
    process.waitForFinished();
    this->cpuHistory.append( process.readAllStandardOutput().toFloat() );
}


void SelfMonitoring::start()
{
    if ( _updateTimer.isActive() )
        return;
    SelfMonitoring::getInstance()->selfMonitoringFile = new QFile(Config::pathToMonitoring());
    SelfMonitoring::getInstance()->selfMonitoringFile->open(QIODevice::WriteOnly | QIODevice::Text);
    SelfMonitoring::getInstance()->selfMonitoringStream.setDevice( SelfMonitoring::getInstance()->selfMonitoringFile );
    SelfMonitoring::getInstance()->selfMonitoringStream << "-----------[Start Monitoring for session : "+QSettings().value("LOG/nbrExec").toString()+"]--------------\n";

    SelfMonitoring::getInstance()->selfMonitoringStream.flush();

    SelfMonitoring::getInstance()->_updateTimer.start( Config::softwareMonitoringDelay() );
}

void SelfMonitoring::stop()
{
    SelfMonitoring::getInstance()->_updateTimer.stop();
}

void SelfMonitoring::update()
{
    updateCpu();
    updateRam();
    emit updateUI();
}


double SelfMonitoring::ramUsed()
{
    return ramHistory.last();
}

double SelfMonitoring::cpuUsed()
{
    return cpuHistory.last();
}

int SelfMonitoring::serialByteTransferred()
{

}
