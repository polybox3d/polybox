#include "SerialPort.h"
#include <QDebug>
#include <string.h>
#include <iostream>

using namespace std;

SerialPort* SerialPort::serialPortInstance = NULL;

SerialPort::SerialPort(QObject *parent) :
    QObject(parent)
  //QextSerialPort("/dev/ttyACM0", QextSerialPort::EventDriven, parent)
{
    _port = NULL;
}
QString SerialPort::path()
{
    return _path;
}
QString SerialPort::name()
{
    return _name;
}

bool SerialPort::connectToSerialPort()
{
    if ( _port != NULL && _port->isOpen() )
    {
        cout<<"close"<<endl;
        _port->close();
    }
    cout<<"start"<<endl;
    _port = new QextSerialPort(Config::pathToSerialDevice+Config::serialPortName, QextSerialPort::EventDriven);

    cout<<Config::pathToSerialDevice.toStdString()+Config::serialPortName.toStdString()<<endl;

    _port->setBaudRate( (BaudRateType)(Config::motherboardBaudrate) );
    _port->setFlowControl(FLOW_OFF);
    _port->setParity(PAR_NONE);
    _port->setDataBits(DATA_8);
    _port->setStopBits(STOP_1);

    if ( _port->open(QIODevice::ReadWrite) == true)
    {
        _path = Config::pathToSerialDevice;
        _name = Config::serialPortName;
        cout<<"ok!"<<endl;
        //connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()) );
        //      connect(this, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)) );
     /*   if (!(lineStatus() & LS_DSR)){
            qDebug() << "warning: device is not turned on"<<lineStatus();
            return false;
        }*/
        qDebug() << "listening for data on" << _port->portName();
        qDebug() << "Ok connected";
        connect ( _port, SIGNAL(readyRead()), this, SLOT(parseSerialDatas()) );
        return true;
    }
    else
    {
        qDebug() << "device failed to open:" << _port->errorString();
        return false;
    }

}

void SerialPort::parseSerialDatas()
{
    QByteArray tmp;
    int a = _port->bytesAvailable();
    tmp.resize(a);
    _port->read( tmp.data(), tmp.size() );

    int c_size = _rcp_datas.size();
    _rcp_datas.resize(  c_size + tmp.size() );
    strcat( _rcp_datas.data(), tmp.data() );
    // end of line/command
    if ( QString(tmp).contains("*"))
    {
        _datas = _rcp_datas;
        _rcp_datas.clear();
        emit dataReady();
    }
}


void SerialPort::sendMCode(int code)
{
    sendMCode( QString::number(code) );
}
void SerialPort::sendMCode(QString code)
{
    code = "M"+code;
    if ( _port != NULL && _port->isWritable() && _port->isOpen() )
    {
        _port->write( code.toStdString().c_str() );
    }

}
