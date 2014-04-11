#include "polyplexer.h"
#include "MainWindow.h"

#include "QLabel"

Polyplexer* Polyplexer::polyplexerInstance = NULL;

Polyplexer::Polyplexer(QObject *parent) :
    QObject(parent)
{
    _polyplexer = NULL;
    _outputWidget = NULL;
    _portMachine="ttyACM0";
    _pathMachine="/dev/";

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
}

void Polyplexer::useWindowOutput(bool use_window )
{
    _useOutputWindow = use_window ;
}
void Polyplexer::manageWindow()
{

}
bool Polyplexer::start(QString path, QString port)
{
    setPortMachine( port );
    setPathMachine( path );
    return this->start();
}

bool Polyplexer::start()
{

    stop();
    /** Create process **/
    QString program = Config::pathToPolyplexerDaemon;
    QStringList arguments;

    arguments << this->_pathMachine+this->_portMachine << DEAMON_POLY_POLYPLEXER << DEAMON_PRINTER_POLYPLEXER;
    _polyplexer = new QProcess( this );
    connect( _polyplexer, SIGNAL(finished(int,QProcess::ExitStatus)), this,SLOT(finished(int,QProcess::ExitStatus)));
    connect( _polyplexer, SIGNAL(readyReadStandardError()), this,SLOT(newOutputText()));
    connect( _polyplexer, SIGNAL(readyReadStandardOutput()), this,SLOT(newOutputText()));
    //connect( _polyplexer, SIGNAL(finished(int)), this,SLOT(stop()));
    _polyplexer->start( program, arguments );

    bool isRunning = _polyplexer->waitForStarted(3000) ;

    if ( isRunning )
    {
        // create or no Window to get output data from process
        if ( _useOutputWindow )
        {
            _outputWidget = new QTextEdit();
            _outputWidget->setFixedSize(400,600);
            _outputWidget->show();
        }
        /** Start VirtualSerial Connexion **/
        isRunning = SerialPort::getSerial()->connectToSerialPort();
    }
    return isRunning;
}
void Polyplexer::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if ( exitStatus == QProcess::NormalExit)
    {
        if  ( exitCode == 1 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+"\n\n. Bad software usage...This should not happen, unless you mess with the software or set bad settings...");
        }
        else if  ( exitCode == 8 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+"\n\n.The software can't connect to the printer. It can't found serial connexion.\n"
                                     "Check if hardware is correcty plugged, powered and if software parameters are correct (device name, path, permission).");
        }
        else if  ( exitCode == 9 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+"\n\n.The software can't connect to the virtual printer serial. It can't found serial connexion.\n"
                                     "Check if software parameters are correct (device name, path, permission).");
        }
        else if  ( exitCode == 10 )
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+"\n\n.The software is not connected to the virtual polysoftware serial. It can't found serial connexion.\n"
                                     "Check if software parameters are correct (device name, path, permission).");
        }
        else
        {
            MainWindow::errorWindow( _polyplexer->readAllStandardError()+"\n\n");
        }

    }
    else
    {
        MainWindow::textWindow( "Connexion closed. ");
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
