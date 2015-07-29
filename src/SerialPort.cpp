#include "SerialPort.h"
#include <QDebug>
#include <string.h>
#include <iostream>

using namespace std;

SerialPort::SerialPort(QObject *parent):QextSerialPort( QextSerialPort::EventDriven, parent)
  //QextSerialPort("/dev/ttyACM0", QextSerialPort::EventDriven, parent)
{
    this->setBaudRate( (BaudRateType)Config::motherboardBaudrate() );
    this->setParity(PAR_NONE);
    this->setStopBits(STOP_1);
    this->setFlowControl( FLOW_OFF );
    this->setTimeout( 10 );

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
    if (!this->isOpen())
    {
        this->setPortName(_path+_name );

        if ( this->open(QIODevice::ReadWrite) == true)
        {
            //cout << _path.toStdString().c_str() << _name.toStdString().c_str() << endl;
            return true;
        }
        else
        {
            cout << _path.toStdString().c_str() << _name.toStdString().c_str() << endl;
            cout << "device failed to open:" << this->errorString().toStdString().c_str();
            return false;
        }
    }
    else
    {
     cout << "Already Open" << endl;
    }

}

void SerialPort::onDsrChanged(bool status)
{
    if (status)
        qDebug() << "device was turned on";
    else
        qDebug() << "device was turned off";
}

void SerialPort::disconnectPort()
{
    if ( this->isOpen() )
    {
        //this->sendMCode( MCODE_END_CONNECTION );
       // this->flush();
        this->close();
        //emit disconnected();
    }
}

