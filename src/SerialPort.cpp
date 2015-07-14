#include "SerialPort.h"
#include <QDebug>
#include <string.h>
#include <iostream>

using namespace std;

SerialPort::SerialPort(QObject *parent) :
    QextSerialPort()
  //QextSerialPort("/dev/ttyACM0", QextSerialPort::EventDriven, parent)
{
    _path = Config::pathToSerialDevice();
    _name = Config::serialPortName();
}

QString SerialPort::path()
{
    return _path;
}
QString SerialPort::name()
{
    return _name;
}
void SerialPort::setName( QString name )
{
    _name = name;
}

void SerialPort::setPath(QString path)
{
    _path = path;
}

bool SerialPort::connectToSerialPort()
{
    this->setPortName(_path+_name );
    this->setBaudRate( (BaudRateType)(Config::motherboardBaudrate()) );
    this->setFlowControl(FLOW_OFF);
    this->setParity(PAR_NONE);
    this->setDataBits(DATA_8);
    this->setStopBits(STOP_1);

    if ( this->open(QIODevice::ReadWrite) == true)
    {
        //connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()) );
        //      connect(this, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)) );
     /*   if (!(lineStatus() & LS_DSR)){
            qDebug() << "warning: device is not turned on"<<lineStatus();
            return false;
        }*/
        cout << _path.toStdString().c_str() << _name.toStdString().c_str() << endl;
        return true;
    }
    else
    {
        qDebug() << "device failed to open:" << this->errorString();
        return false;
    }

}

void SerialPort::disconnectPort()
{
    if ( this->isOpen() )
    {
        //this->sendMCode( MCODE_END_CONNECTION );
        this->flush();
        this->close();
        emit disconnected();
    }
}

