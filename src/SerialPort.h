#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QProcess>
#include <QDir>
#include <QStringList>

#include "qextserialport.h"
#include "Config.h"
/**
 * @brief The SerialPort class Constructs a classs based of QextSerialPort. Provides an overlay for Serial Communication through USB/COM
 */
class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = 0);

    /**
     * @brief connectToSerialPort Connect the current serial with defautl value and setting (115200baudrate, 8b, no parity, 1 stop)
     * @return
     */
    bool connectToSerialPort();
    /**
     * @brief sendMCode Send code string added by a M letter at the beggining, to the device connected.
     * @param code
     */
    void sendMCode(QString code);
    /**
     * @brief sendMCode Send code value as M Code to the device connected.
     * @param code
     */
    void sendMCode(int code);

    static QStringList getDevicesNames( QString path )
    {
        QDir device_dir( path );
        return device_dir.entryList(QStringList("*"),QDir::System, QDir::Name) ;
    }

signals:

public slots:
    void parseSerialDatas();

private:
    QextSerialPort* _port;
    QProcess* _printerCOM;


};

#endif // SERIALPORT_H
