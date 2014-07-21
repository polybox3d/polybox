#include "polyplexer.h"
#include "MainWindow.h"

#include "QLabel"

Polyplexer* Polyplexer::polyplexerInstance = NULL;

Polyplexer::Polyplexer(QObject *parent) :
    QObject(parent)
{
    _polyplexer = NULL;
    _outputWidget = NULL;
    _portMachine = Config::serialPortName;
    _pathMachine = Config::pathToSerialDevice;

    useWindowOutput(false);
}

Polyplexer::~Polyplexer()
{
    if ( _outputWidget != NULL )
    {
        _outputWidget->deleteLater();
    }
    if ( _polyplexer != NULL )
    {
        _polyplexer->close();
    }
}

bool Polyplexer::isRunning()
{
    return SerialPort::getSerial()->isConnected();
}

void Polyplexer::useWindowOutput(bool use_window )
{
    _useOutputWindow = use_window ;
}
void Polyplexer::manageWindow()
{

}

QByteArray Polyplexer::printerDatas()
{
    if ( SerialPort::getSerial() == NULL)
        return "";
    return SerialPort::getSerial()->datas();
}

bool Polyplexer::start(QString path, QString port)
{
    setPortMachine( port );
    setPathMachine( path );
    return this->start();
}

bool Polyplexer::start()
{
    bool isRunning = false;
    stop();
    if ( ! Config::disablePolyplexer )
    {
    /** Create process **/
    QString program = Config::pathToPolyplexerDaemon;
    QStringList arguments;

    arguments << QString("--serial=")+this->_pathMachine+this->_portMachine << QString("--polybox_sock=")+DEAMON_POLY_POLYPLEXER << QString("--printer_sock=")+DEAMON_PRINTER_POLYPLEXER;
    _polyplexer = new QProcess( this );
    connect( _polyplexer, SIGNAL(finished(int,QProcess::ExitStatus)), this,SLOT(finished(int,QProcess::ExitStatus)));
    connect( _polyplexer, SIGNAL(readyReadStandardError()), this,SLOT(newOutputText()));
    connect( _polyplexer, SIGNAL(readyReadStandardOutput()), this,SLOT(newOutputText()));
    //connect( _polyplexer, SIGNAL(finished(int)), this,SLOT(stop()));
    _polyplexer->start( program, arguments );

    isRunning = _polyplexer->waitForStarted(3000) ;
    }
    else
    {
        isRunning = true;
    }

    if ( isRunning )
    {
        // create or no Window to get output data from process
        if ( _useOutputWindow && !Config::disablePolyplexer )
        {
            _outputWidget = new QTextEdit();
            _outputWidget->setFixedSize(400,600);
            _outputWidget->show();
        }
        /** Start VirtualSerial Connexion **/
        if ( ! Config::disablePolyplexer )
            isRunning = !(_polyplexer->waitForFinished(1000)) && SerialPort::getSerial()->connectToSerialPort() ;
        else
            isRunning = SerialPort::getSerial()->connectToSerialPort() ;
    }
    return isRunning;
}
void Polyplexer::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if ( exitStatus == QProcess::NormalExit)
    {
        if  ( exitCode == 1 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+tr("\n\nMauvaise configuration du logiciel...Ca n'aurait pas du se passer à part si vous avez modifier tout et n'importequoi dans les configurations ou les sources..."));
        }
        else if  ( exitCode == 8 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+tr("\n\nImpossible de se connecter à la machine. Connexion serie/USB introuvable.\n"
                                     "Verifiez les branchements, l'alimentation electrique et les paramètres (device name, path, permission)."));
        }
        else if  ( exitCode == 9 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+tr("\n\nImpossible de se connecter à la machine. Connexion serie/USB introuvable.\n"
                                     "Verifiez les parametres (device name, path, permission)."));
        }
        else if  ( exitCode == 10 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+tr("\n\nImpossible de se connecter au peripherique virtuel. Connexion introuvable.\n"
                                     "Verifiez les parametres (device name, path, permission)."));
        }
        else
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+"\n\n");
        }

    }
    else
    {
        MainWindow::textWindow( "Connexion fermée. ");
    }
    this->stop();
}

void Polyplexer::newOutputText()
{
    if ( _useOutputWindow && _outputWidget != NULL )
    {
        _outputWidget->append( _polyplexer->readAllStandardError());
        _outputWidget->append( _polyplexer->readAllStandardOutput());
    }
}

bool Polyplexer::restart()
{

}

bool Polyplexer::stop()
{
    if ( _polyplexer != NULL )
    {
        _polyplexer->kill();
    }
    if ( _outputWidget != NULL )
    {
        _outputWidget->close();
    }
    SerialPort::getSerial()->disconnectPort();
}

bool Polyplexer::kill()
{

}
