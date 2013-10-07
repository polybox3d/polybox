#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

class Config
{
public:
    Config();

    static QString pathToHomeDirectory;
    static QString pathToLinuxCNC;
    static QString pathToWebcamDevice;
    static QString webcamName;

    static QString linuxCNCCommand;
};

#endif // CONFIG_H
