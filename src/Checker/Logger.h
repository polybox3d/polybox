#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

#include "Config.h"

class Logger : public QObject
{
    Q_OBJECT
public:

    static Logger* getInstance();
    static void stop();

    static void start();
    static void startConnection(bool connected);
    static void writeOutputCommand(QString command);
    static void writeInputCommand(QString command);


    QFile* logFile;
    QTextStream logSteam;
signals:

public slots:
    static void disconnect();

private:
    explicit Logger(QObject *parent = 0);
    static Logger* loggerInstance;


};

#endif // LOGGER_H
