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
    _path = Config::pathToVirtualPolySerialDevice();
    _name = Config::serialVirtualPolySerialPort();
    _port = NULL;
    connectionUptime = 0 ;

    _uptimeTimer.start( Config::connectionUptimeDelay() );
    connect( &_uptimeTimer, SIGNAL(timeout()), this, SLOT(connectionUptimeProcess()));
}
void SerialPort::connectionUptimeProcess()
{
    connectionUptime++;
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

bool SerialPort::isConnected() const
{
    return _port != NULL && _port->isOpen();
}

bool SerialPort::connectToSerialPort()
{
    disconnectPort();
    _port = new QextSerialPort(_path+_name, QextSerialPort::EventDriven);

    _port->setBaudRate( (BaudRateType)(Config::motherboardBaudrate()) );
    _port->setFlowControl(FLOW_OFF);
    _port->setParity(PAR_NONE);
    _port->setDataBits(DATA_8);
    _port->setStopBits(STOP_1);

    if ( _port->open(QIODevice::ReadWrite) == true)
    {
        //connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()) );
        //      connect(this, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)) );
     /*   if (!(lineStatus() & LS_DSR)){
            qDebug() << "warning: device is not turned on"<<lineStatus();
            return false;
        }*/
        connect ( _port, SIGNAL(readyRead()), this, SLOT(parseSerialDatas()) );
        this->connectionUptime = 0 ;
        return true;
    }
    else
    {
        qDebug() << "device failed to open:" << _port->errorString();
        return false;
    }

}
void SerialPort::disconnectPort()
{
    if ( _port != NULL && _port->isOpen() )
    {
        _port->close();
        emit disconnected();
    }
}

void SerialPort::parseSerialDatas()
{
    QByteArray tmp;
    int a = _port->bytesAvailable();
    tmp.resize(a);
    _port->read( tmp.data(), tmp.size() );
/*
    int c_size = _rcp_datas.size();
    _rcp_datas.resize(  c_size + tmp.size() );
    strcat( _rcp_datas.data(), tmp.data() );*/
    _rcp_datas.append( tmp );
    // end of line/command
    if ( QString(_rcp_datas).contains("\r") || QString(_rcp_datas).contains("\n"))
    {
        _datas = _rcp_datas;
        _rcp_datas.clear();
        emit dataReady();
    }
}

void SerialPort::sendCode(QString code)
{
    if ( _port != NULL && _port->isWritable() && _port->isOpen() )
    {
        code = code +"\r\n";
        _port->write( code.toStdString().c_str() );
    }
}


void SerialPort::sendMCode(int code)
{
    sendMCode( QString::number(code) );
}
void SerialPort::sendMCode(QString code)
{
    code = "M"+code;
    this->sendCode( code );
}
