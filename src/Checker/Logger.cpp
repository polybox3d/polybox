#include "Logger.h"
#include "PolyboxModule.h"
#include "GlobalModule.h"

Logger* Logger::loggerInstance = NULL;
QFile* logFile;

Logger::Logger(QObject *parent) :
    QObject(parent)
{

}

void Logger::stop()
{
    Logger::getInstance()->logSteam << "~~~~~~~~~~~[End log for session : "+QSettings().value("LOG/nbrExec").toString()+"]~~~~~~~~~~~~~~~~~~~~\n";
    Logger::getInstance()->logSteam.flush();
    Logger::getInstance()->logFile->close();
}

Logger* Logger::getInstance()
{
    if ( loggerInstance == NULL )
    {
        loggerInstance = new Logger();
    }
    return loggerInstance;
}

void Logger::writeOutputCommand(QString command)
{
    if ( Config::loggerLevel() >= 4)
    {
        Logger::getInstance()->logSteam << "[OUT]\t"+command;
        Logger::getInstance()->logSteam.flush();
    }
}
void Logger::writeInputCommand(QString command)
{
    if ( Config::loggerLevel() >= 4)
    {
        Logger::getInstance()->logSteam << "[IN]"+command;
        Logger::getInstance()->logSteam.flush();
    }
}
void Logger::write(QString text)
{
    if ( Config::loggerLevel() >= 2)
    {
        Logger::getInstance()->logSteam << "-> "+text;
        Logger::getInstance()->logSteam.flush();
    }
}

void Logger::start()
{
    Logger::getInstance()->logFile = new QFile(Config::pathToLogFile());
    Logger::getInstance()->logFile->open(QIODevice::WriteOnly | QIODevice::Text);
    Logger::getInstance()->logSteam.setDevice( Logger::getInstance()->logFile );
    Logger::getInstance()->logSteam << "-----------[Start new log for session : "+QSettings().value("LOG/nbrExec").toString()+"]--------------\n";

    Logger::getInstance()->logSteam.flush();
}

void Logger::startConnection(bool connected)
{
    Logger::getInstance()->logSteam << "====> Start Connection \n";
    if ( connected )
    {
        //Logger::getInstance()->logSteam << "-->"+SerialPort::getSerial()->path()+"\n";
        //Logger::getInstance()->logSteam << "-->"+SerialPort::getSerial()->name()+"\n";
        Logger::getInstance()->logSteam << "-->"+QString::number(Config::motherboardBaudrate())+"\n";

    }
    else
    {
        Logger::getInstance()->logSteam << "====> Not connected \n";
    }
    Logger::getInstance()->logSteam.flush();
}

void Logger::disconnect()
{

    Logger::getInstance()->logSteam << "[RAM]\t\t-> "+QString::number(PolyboxModule::getInstance()->globalModule()->ram())+" \n";
    Logger::getInstance()->logSteam << "[UPTIME]\t-> "+QString::number(ComModule::getInstance()->_connectionUptime/60)+" \n";
    Logger::getInstance()->logSteam << "====> Disconnected \n";

    Logger::getInstance()->logSteam.flush();
}
