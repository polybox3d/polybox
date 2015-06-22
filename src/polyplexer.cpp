#include "polyplexer.h"
#include "MainWindow.h"

#include "QLabel"

Polyplexer* Polyplexer::_instance = NULL;

Polyplexer::Polyplexer(QObject *parent) :
    QObject(parent)
{
    _connector = NULL;
    _connectorType = Noone;
}

Polyplexer* Polyplexer::getInstance(QObject* parent)
{
    if ( _instance == NULL )
    {
        _instance = new Polyplexer( parent );
    }
    return _instance;
}

Polyplexer::~Polyplexer()
{
    disconnect();
}

Polyplexer::ConnectorType Polyplexer::connectorType ()
{
    return Polyplexer::getInstance()->_connectorType;
}

bool Polyplexer::isConnected()
{
    if ( Polyplexer::getInstance()->_connector != NULL)
    {
        return Polyplexer::getInstance()->_connector->isReadable();
    }
    else
    {
        return false;
    }
}

void Polyplexer::setConnector(QIODevice* connector)
{

}

void Polyplexer::setConnectorType(ConnectorType connector_type)
{
    this->_connectorType = connector_type;
}

Polyplexer::ConnectionStatus Polyplexer::start(ConnectorType connector_type)
{
    if ( connector_type == Polyplexer::Serial )
    {
        SerialPort* serial_connector = new SerialPort;
        if ( ! serial_connector->connectToSerialPort() )
        {
            return Polyplexer::ErrorConnection;
        }
        return this->start( serial_connector, connector_type );
    }
    return Polyplexer::NothingToDo;
}

Polyplexer::ConnectionStatus Polyplexer::start(QIODevice *connector, ConnectorType connector_type)
{
    if ( connector_type == Noone )
    {
        return Polyplexer::NothingToDo;
    }
    _connectorType = connector_type;
    _connector = connector;

    connect(_connector,SIGNAL(readyRead()),this,SLOT(parseData()));
    connect(_connector,SIGNAL(aboutToClose()),this,SLOT(disconnect()));

    emit newType(_connectorType);
    return Polyplexer::Connected;

}

void Polyplexer::disconnect()
{/*
    if ( _connector != NULL )
    {
        _connector->close();
    }*/
}

void Polyplexer::sendData(QString data)
{
    if ( this->isConnected() )
    {
        _connector->write( data.toStdString().c_str() );
    }
}

QIODevice* Polyplexer::connector()
{
    return _connector;
}

void Polyplexer::send(QString data)
{
    Polyplexer::getInstance()->sendData( data );
}

void Polyplexer::parseData()
{
    QByteArray tmp;
    int a = _connector->bytesAvailable();
    tmp.resize(a);
    _connector->read( tmp.data(), tmp.size() );
/*
    int c_size = _rcp_data.size();
    _rcp_datas.resize(  c_size + tmp.size() );
    strcat( _rcp_data.data(), tmp.data() );*/
    _rcp_data.append( tmp );
    // end of line/command
    QString rcpString = _rcp_data;
    if ( rcpString.contains("\r") || rcpString.contains("\n"))
    {
        if ( rcpString.contains('#') ) // polybox data
        {
            _dataPolybox = _rcp_data;
            _rcp_data.clear();
            emit dataPolyboxReady(  );
        }
        else // basic datas
        {
            _dataBasic = _rcp_data;
            _rcp_data.clear();
            emit dataBasicReady( );
        }
    }
}


QByteArray Polyplexer::dataPolybox()
{
    return _dataPolybox;
}

QByteArray Polyplexer::dataBasic()
{
    return _dataBasic;
}


