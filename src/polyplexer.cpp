#include "polyplexer.h"
#include "MainWindow.h"

#include "QLabel"

Polyplexer* Polyplexer::_instance = NULL;

Polyplexer::Polyplexer(QObject *parent) :
    QObject(parent)
{
    _connector = NULL;
    _connectorType = Noone;
    /*PortSettings settings = {BAUD115200, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort("/dev/ttyACM0", settings, QextSerialPort::EventDriven);
    connect(port, SIGNAL(readyRead()), SLOT(parseData()));
    startStop();
/*
    // external TCP connector
    Connector* printer_software = new Connector( this ) ;
    SerialPort* printer_tcp = new SerialPort( this );
    printer_tcp->setName(DEAMON_PRINTER_POLYPLEXER);

    printer_software->setConnector( printer_tcp );
    if (printer_tcp->connectToSerialPort() )
    {
        cout<<"TCP Socket Started"<<endl;
    }
    else
    {
        cout<<"TCP Socket not Started..."<<endl;
    }
    connect( this, SIGNAL(dataBasicReady(QByteArray)), printer_software, SLOT(sendData(QByteArray)));
    connect( printer_software, SIGNAL(dataReady(QByteArray)), this, SLOT(sendDataArray(QByteArray)));
    connect( this, SIGNAL(connectorClosing()), printer_software, SLOT(close()));

    // external SERIAL connector
    Connector* serial_software = new Connector( this ) ;
    SerialPort* serial_tcp = new SerialPort( this );
    serial_tcp->setName(DEAMON_POLY_POLYPLEXER);

    serial_software->setConnector( serial_tcp );
    if (serial_tcp->connectToSerialPort() )
    {
        cout<<"Serial Socket Started"<<endl;
    }
    else
    {
        cout<<"Serial Socket not Started..."<<endl;
    }
    connect( this, SIGNAL(dataBasicReady(QByteArray)), serial_software, SLOT(sendData(QByteArray)));
    connect( serial_software, SIGNAL(dataReady(QByteArray)), this, SLOT(sendDataArray(QByteArray)));
    connect( this, SIGNAL(connectorClosing()), serial_software, SLOT(close()));
    */
}

void Polyplexer::startStop()
{
    if (!port->isOpen()) {
        //port->setPortName(ui->portBox->currentText());
        port->open(QIODevice::ReadWrite);
    }
    else {
        port->close();
    }
}

void Polyplexer::onReadyRead()
{
    if (port->bytesAvailable()) {
        cout<<QString(port->readAll()).toStdString().c_str()<<"."<<endl ;

    }
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
    disConnect();
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
    // @todo
    cerr<<"Polyplexer::setConnector : Unimplemented Function ! Care !"<<endl;

    // !!
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
        _connector = serial_connector;
        if ( ! serial_connector->connectToSerialPort() )
        {
            return Polyplexer::ErrorConnection;
        }

        _connectorType = connector_type;

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
    //connect(_connector,SIGNAL(aboutToClose()),this,SLOT(disConnect()));

    emit newType(_connectorType);
    return Polyplexer::Connected;

}
void Polyplexer::stop()
{
    if ( dynamic_cast<QIODevice*>(_connector) )
    {
        this->sendData("M"+QString::number(MCODE_END_CONNECTION)+"\n");

        /*qApp->processEvents();
        ClosedLoopTimer loop;
        loop.startClosedLoop( 1000 );
        qApp->processEvents();
        //static_cast<SerialPort*>(_connector)->disconnectPort();
        //disconnect(_connector,SIGNAL(readyRead()),this,SLOT(parseData()));
        //disconnect(_connector,SIGNAL(aboutToClose()),this,SLOT(disConnect()));*/
        if ( _connector->isOpen() )
        {
            _connector->close();
            cout<<"Polyplexer::close()"<<endl;
            qApp->processEvents();
            ClosedLoopTimer loop;
            loop.startClosedLoop( 1000 );
            qApp->processEvents();
        }
        _connector = NULL;
        _connectorType = Noone;
    }
    emit newType(_connectorType);

}

void Polyplexer::disConnect()
{
    this->stop();
    /*
    if ( _connector != NULL )
    {
        _connector->close();
    }*/
}

void Polyplexer::sendData(QString data)
{
    if ( this->isConnected() )
    {
        //cerr<<"PolySend:"<<data.toStdString()<<endl;
        data+="\n";
        _connector->write( data.toStdString().c_str() );

        emit dataWritten(data);
    }
}

void Polyplexer::sendDataArray(QByteArray data)
{
    this->sendData( data );
}

QIODevice* Polyplexer::connector()
{
    return _connector;
}

void Polyplexer::send(QString data)
{
    Polyplexer::getInstance()->sendData( data );
}
/*    if (port->bytesAvailable()) {
        QByteArray tmp = port->readAll();

        QString rcpString(tmp);
        _rcp_data.append( rcpString );*/
void Polyplexer::parseData()
{
    //QByteArray tmp;
    /*int a = _connector->bytesAvailable();
    tmp.resize(a);*/
    if (!_connector->bytesAvailable())
        return;

    QByteArray tmp = _connector->readAll();

    // end of line/command
    _rcp_data.append( QString(tmp) );
    QString rcpString( _rcp_data );

    // do we get full command line, or unended line ?
    int pos = rcpString.lastIndexOf(QRegExp("[\r\n]"));
    if ( pos != -1 )
    {
        QString rest = rcpString;
        rest.remove( 0, pos+1);
        _rcp_data = rest.toStdString().c_str(); // save unended command line
        rcpString.truncate( pos ); // delete unended command line from process buffer
    }
    else // command line not fully get
    {
        return;
    }
    //cerr<<">"<<rcpString.toStdString().c_str()<<"<"<<endl;
    QStringList lines = rcpString.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    foreach (QString line, lines)
    {
        if ( line.contains('#') ) // polybox data
        {
            _dataPolybox = line.toStdString().c_str();
            emit dataPolyboxReady( _dataPolybox );
        }
        else // basic datas
        {
            _dataBasic = line.toStdString().c_str();
            emit dataBasicReady( _dataBasic );
        }
        cout<<line.toStdString().c_str()<<endl;
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


