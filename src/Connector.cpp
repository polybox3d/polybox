#include "Connector.h"

Connector::Connector(QObject *parent) :
    QObject(parent)
{
}

void Connector::setConnector(QIODevice *connector)
{
    _connector = connector;
    connect( _connector, SIGNAL(readyRead()), this, SLOT(parseData()));
}

void Connector::close()
{
    if ( _connector != NULL && _connector->isOpen() )
    {
        _connector->close();
    }
    this->deleteLater();
}

void Connector::parseData()
{
    QByteArray tmp;
    int a = _connector->bytesAvailable();
    tmp.resize(a);
    _connector->read( tmp.data(), tmp.size() );

    _rcp_data.append( tmp );
    // end of line/command
    QString rcpString = _rcp_data;

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

    // split command in line
    QStringList lines = rcpString.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    // send each line ended
    foreach (QString line, lines)
    {
        _dataBasic = line.toStdString().c_str();
        emit dataReady( _dataBasic );
    }
}


void Connector::sendDataString(QString data)
{
    if ( _connector != NULL && _connector->isOpen() )
    {
        data+="\n";
        _connector->write( data.toStdString().c_str() );
    }
}

void Connector::sendData(QByteArray data)
{
    if ( _connector != NULL && _connector->isOpen() )
    {
        //cerr<<"Connector: "<<QString(data).toStdString().c_str()<<endl;
        _connector->write( data+"\n" );
    }
}
