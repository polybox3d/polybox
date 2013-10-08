#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
/**
 * @brief The Config class Store Polybox config and constants, such as program path, command, driver.
 */
class Config
{
public:
    Config();

    /**
     * @brief pathToHomeDirectory Full path to the main user home directory (/home/<user>/)
     */
    static QString pathToHomeDirectory;
    /**
     * @brief pathToLinuxCNC Full path to the top-level linuxCNC folder.
     */
    static QString pathToLinuxCNC;
    /**
     * @brief pathToWebcamDevice Full path to the device directory. Something like /dev/tty for linux
     */
    static QString pathToWebcamDevice;
    /**
     * @brief webcamName id for webcam (video0)
     */
    static QString webcamName;
    /**
     * @brief scannerLaserPath Full path to scanner-laser software.
     */
    static QString scannerLaserPath;
    /**
     * @brief linuxCNCCommand Command to start linuxCNC
     */
    static QString linuxCNCCommand;
    /**
     * @brief motherboardBaudrate Default baudrate between software and Polybox.
     */
    static int motherboardBaudrate;
};

#endif // CONFIG_H
