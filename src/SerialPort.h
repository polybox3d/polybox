#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "qextserialport.h"

class SerialPort : public QextSerialPort
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = 0);

    bool connectToSerialPort();
    void sendMCode(QString code);
    void sendMCode(int code);

signals:

public slots:

};

#endif // SERIALPORT_H
