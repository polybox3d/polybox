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
    this->start();
}

void SelfMonitoring::start()
{
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
    emit updateUI();
}


int SelfMonitoring::ramUsed()
{

}

int SelfMonitoring::cpuUsed()
{

}

int SelfMonitoring::serialByteTransferred()
{

}
