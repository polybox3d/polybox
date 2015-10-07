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
    _ramCurrent(50000),
    _ramMax(0),
    _cpu(0),
    _lanSpeed(0)
{
      connect(&_updateTimer, SIGNAL(timeout()), this, SLOT(update()));
}


void ComputerMonitoring::update()
{    
    updateRam();
    updateCpu();
    updateDisk();
    monitoringStream << _ramCurrent<<" "<<_cpu<<endl;
    emit updateUI();
}

void ComputerMonitoring::updateRam()
{
    QProcess process;
    process.start("/bin/bash -c  \"/usr/bin/free | grep -e \"^Mem\" | awk '{print $3\"-\"$7}' | bc -l |tr -d '\n' \"");
    process.waitForFinished();
    _ramCurrent = process.readAllStandardOutput().toInt();
    this->ramHistory.append( _ramCurrent );
}

void ComputerMonitoring::updateCpu()
{
    /**  apt-get install sysstat **/

    QProcess process;
    process.start("/bin/bash -c  \"mpstat | grep all | awk '{print $11}' | tr -d '\n' | tr ',' '.' \"");
    process.waitForFinished();
    _cpu = (100.0-process.readAllStandardOutput().toFloat());
    this->cpuHistory.append( _cpu );
}

void ComputerMonitoring::updateDisk()
{
    /* Retreive disk info.*/
    QProcess process;
    process.start(QString("/bin/bash -c  \"df -B")+QString(DISK_UNIT)+" | grep ^/dev\"");
    process.waitForFinished();
    Disk disk;

    _disk.clear();
    foreach( QString line, process.readAllStandardOutput().split('\n'))
    {
        QStringList values = line.split(" ", QString::SkipEmptyParts);
        if ( !values.isEmpty())
        {
            disk.path = values.at(0);
            disk.mount = values.at(5);
            disk.space_available = values.at(3).left(values.at(3).count()-1).toDouble();
            disk.space_max = values.at(1).left(values.at(1).count()-1).toDouble();
            _disk.append(disk);
        }
    }
    foreach( Disk d, _disk)
    {
        diskHistory[d.path].append(d.space_max - d.space_available);
    }

}

void ComputerMonitoring::start()
{
    if ( _updateTimer.isActive() )
        return;
    monitoringFile = new QFile(Config::pathToMonitoring()+COMPUTER_MONITORING_FILE_PREFIX);
    monitoringFile->open(QIODevice::WriteOnly | QIODevice::Text);
    monitoringStream.setDevice( monitoringFile );
    monitoringStream << "-----------[Start Monitoring for session : "+QSettings().value("LOG/nbrExec").toString()+"]--------------\n";
    monitoringStream <<"RAM_USED %_CPU_USED"<<endl;
    monitoringStream.flush();
    QProcess process;
    process.start("/bin/bash -c \"/usr/bin/free | grep -e \"^Mem\" | awk '{print $2}' |tr -d '\n' \"");
    process.waitForFinished();
    _ramMax = process.readAllStandardOutput().toInt();

    updateDisk();


    _updateTimer.start( Config::computerMonitoringDelay() );
}

QString ComputerMonitoring::getCPUInfo()
{
    QString info;
    QProcess process;
    process.start("/bin/bash -c \"cat /proc/cpuinfo | grep name | cut -d':' -f2 | head -n 1\"");
    process.waitForFinished();
    info="Model Name: " + process.readAllStandardOutput();
    cout<<">>>>"<<info.toStdString()<<endl;
    QProcess process2;
    process2.start("/bin/bash -c \"cat /proc/cpuinfo | grep MHz | cut -d':' -f2 | head -n 1\ |tr -d '\n' \"");
    process2.waitForFinished();
    info+="Frequency: "+ process2.readAllStandardOutput()+" MHz \n" ;

    QProcess process3;
    process3.start("/bin/bash -c \"cat /proc/cpuinfo | grep cores | cut -d':' -f2 | head -n 1\ |tr -d '\n' \"" );
    process3.waitForFinished();
    info+="Number of Core: "+ process3.readAllStandardOutput();


    return info;
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

float ComputerMonitoring::cpu() const
{
    return _cpu;
}
double ComputerMonitoring::diskUsage(QString path)
{
    return diskHistory[path].last();

}

QList<Disk> ComputerMonitoring::disk()
{
    return _disk;
    /*QProcess process;
    process.start("/bin/bash -c  \"df | grep ^/dev\" | awk '{print $6}' \"");
    process.waitForFinished();*/
    //return process.readAllStandardOutput().split('\n');
}

int ComputerMonitoring::lanSpeed() const
{
    return _lanSpeed;
}
