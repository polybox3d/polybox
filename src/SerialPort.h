#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "qextserialport.h"
#include "Config.h"
/**
 * @brief The SerialPort class Constructs a classs based of QextSerialPort. Provides an overlay for Serial Communication through USB/COM
 */
class SerialPort : public QextSerialPort
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = 0);

    /**
     * @brief connectToSerialPort Connect the current serial with defautl value and setting (115200baudrate, 8b, no parity, 1 stop)
     * @return
     */
    bool connectToSerialPort();
    void sendMCode(QString code);
    void sendMCode(int code);

signals:

public slots:

};

#endif // SERIALPORT_H
