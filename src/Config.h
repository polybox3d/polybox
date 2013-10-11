#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QColor>
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
    /**
     * @brief bypassCheck disable check, so the user can acces to everything, withotu printer/cnc controle (atu, NTC, etc...)
     */
    static bool bypassCheck;

    /**
     * @brief colorLabviewFaceSelected Color used when a face is selected in the labview module.
     */
    static QColor colorLabviewFaceSelected;
    /**
     * @brief ambiancePathFolder Path to the default ambiance directory. Ambiances are XML files for labview profiles.
     */
    static QString ambiancePathFolder;

    static float bedTempPla;
    static float bedTempAbs;
    static float bedTempNylon;


};

#endif // CONFIG_H
