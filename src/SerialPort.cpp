#include "SerialPort.h"

SerialPort::SerialPort(QObject *parent) :
    QextSerialPort("/dev/ttyACM0", QextSerialPort::EventDriven, parent)
{
}


bool SerialPort::connectToSerialPort()
{
    setBaudRate(BAUD9600);
    setFlowControl(FLOW_OFF);
    setParity(PAR_NONE);
    setDataBits(DATA_8);
    setStopBits(STOP_2);

    if ( open(QIODevice::ReadWrite) == true) {
//        connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()) );
  //      connect(this, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)) );
        if (!(lineStatus() & LS_DSR)){
            //qDebug() << "warning: device is not turned on";
            return false;
        }
        //qDebug() << "listening for data on" << serialPort->portName();
        return true;
    }else{
        //qDebug() << "device failed to open:" << serialPort->errorString();
        return true;
    }

}

void SerialPort::sendMCode(int code)
{
    sendMCode( QString::number(code) );
}
void SerialPort::sendMCode(QString code)
{
    code = "M"+code;
    if ( isWritable() && isOpen() )
    {
        this->write( code.toStdString().c_str() );
    }

}
