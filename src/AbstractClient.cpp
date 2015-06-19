#include "AbstractClient.h"
#include "Logger.h"

AbstractClient::AbstractClient(QObject *parent) :
    QObject(parent)
{
    _connector = NULL;
    connectionUptime = 0 ;
    _currentLineNumber = 0;

    _uptimeTimer.start( Config::connectionUptimeDelay() );
    connect( &_uptimeTimer, SIGNAL(timeout()), this, SLOT(connectionUptimeProcess()));

    _sendTimer.start( Config::sendBufferTimer() );
    connect( &_sendTimer, SIGNAL(timeout()), this, SLOT(sendBufferedData()));

    connect( this, SIGNAL(disconnected()), Logger::getInstance(), SLOT(disconnect()));

}


QByteArray AbstractClient::datas()
{
    return _datas;
}

void AbstractClient::connectionUptimeProcess()
{
    connectionUptime++;
}

void AbstractClient::sendBufferedData()
{
    /** Is Connected ? **/
    if ( _connector != NULL && _connector->isWritable() && _connector->isOpen() )
    {
        if ( ! _sendBuffer.isEmpty() )
        {
            QString data = _sendBuffer.dequeue();
            // Add checksum
            data = data + "*" + QString::number(AbstractClient::checksum(data.toStdString().c_str(), data.size())) + "\n";

            Logger::writeOutputCommand( data );
            _connector->write( data.toStdString().c_str() );
            emit dataWritten( data );
        }
    }
    else
    {
        _sendBuffer.clear();
    }
}

bool AbstractClient::isConnected() const
{
    return _connector != NULL && _connector->isOpen();
}

QIODevice* AbstractClient::getConnector()
{
    return _connector;
}

void AbstractClient::parseSerialDatas()
{
    QByteArray tmp;
    int a = _connector->bytesAvailable();
    tmp.resize(a);
    _connector->read( tmp.data(), tmp.size() );
/*
    int c_size = _rcp_datas.size();
    _rcp_datas.resize(  c_size + tmp.size() );
    strcat( _rcp_datas.data(), tmp.data() );*/
    _rcp_datas.append( tmp );
    // end of line/command
    if ( QString(_rcp_datas).contains("\r") || QString(_rcp_datas).contains("\n"))
    {
        _datas = _rcp_datas;
        Logger::writeInputCommand( _datas );
        _rcp_datas.clear();
        emit dataReady();
    }
}

void AbstractClient::startConnection()
{
    connect ( _connector, SIGNAL(readyRead()), this, SLOT(parseSerialDatas()) );
    this->connectionUptime = 0 ;  
    this->_currentLineNumber = 0;
    this->sendMCode( MCODE_RESET_SLAVES );
    this->_currentLineNumber = 0;
    this->sendMCode( MCODE_RESET_LINE_NUMBER );
}

void AbstractClient::sendCode(QString code)
{
    if ( _connector != NULL && _connector->isWritable() && _connector->isOpen() )
    {
        if ( _sendBuffer.size() <= Config::sendBufferSize() )
        {
            _currentLineNumber++;
            // Add line number
            code = "#N"+QString::number(_currentLineNumber) + " " + code + " ";
            _sendBuffer.enqueue( code );
        }
        else
        {
            Logger::write("Buffer Full\n");
        }
    }
}


void AbstractClient::sendMCode(int code)
{
    sendMCode( QString::number(code) );
}
void AbstractClient::sendMCode(QString code)
{
    code = "M"+code;
    this->sendCode( code );
}

