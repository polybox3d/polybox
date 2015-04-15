#include "polyplexer.h"
#include "MainWindow.h"

#include "QLabel"

Polyplexer* Polyplexer::polyplexerInstance = NULL;

Polyplexer::Polyplexer(QObject *parent) :
    QObject(parent)
{
    _polyplexer = NULL;
    _portMachine = Config::serialPortName();
    _pathMachine = Config::pathToSerialDevice();

    useWindowOutput(false);
}

Polyplexer::~Polyplexer()
{
    if ( _polyplexer != NULL )
    {
        _polyplexer->close();
    }
}

bool Polyplexer::isRunning()
{
    return PolyboxModule::getInstance()->connector()->isConnected();
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
int Polyplexer::error()
{
    if ( _polyplexer != NULL )
    {
        return _polyplexer->exitCode();
    }
}

bool Polyplexer::start()
{
    bool isRunning = false;
    stop();
    if ( ! Config::disablePolyplexer() )
    {
        /** Create process **/
        QString program = Config::pathToPolyplexerDaemon();
        QStringList arguments;

        arguments << QString("--serial=")+this->_pathMachine+this->_portMachine << QString("--polybox_sock=")+DEAMON_POLY_POLYPLEXER << QString("--printer_sock=")+DEAMON_PRINTER_POLYPLEXER;
        _polyplexer = new QProcess( this );
        connect( _polyplexer, SIGNAL(finished(int,QProcess::ExitStatus)), this,SLOT(finished(int,QProcess::ExitStatus)));

        _polyplexer->start( program, arguments );
        cout << (QString("--serial=")+this->_pathMachine+this->_portMachine).toStdString() << (QString("--polybox_sock=")+DEAMON_POLY_POLYPLEXER).toStdString() << (QString("--printer_sock=")+DEAMON_PRINTER_POLYPLEXER).toStdString() << endl;
        isRunning = _polyplexer->waitForStarted(1000) ;
    }
    else
    {
        cout <<"Polyplexer is DISABLE. Starting software as stand-alone process. "<< (QString("--serial=")+this->_pathMachine+this->_portMachine).toStdString() << (QString("--polybox_sock=")+DEAMON_POLY_POLYPLEXER).toStdString() << (QString("--printer_sock=")+DEAMON_PRINTER_POLYPLEXER).toStdString() << endl;
        isRunning = true;
    }

    if ( isRunning )
    {
        // create or no Window to get output data from process
        if ( _useOutputWindow && !Config::disablePolyplexer() )
        {
            MainWindow::getMainWindow()->startConsoleWindow();
        }
        if ( !Config::disablePolyplexer() )
        {
            isRunning = !(_polyplexer->waitForFinished(1000));
        }
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


bool Polyplexer::restart()
{

}

bool Polyplexer::stop()
{
    dynamic_cast<SerialPort*>(PolyboxModule::getInstance()->connector())->disconnectPort();
    /*if ( _polyplexer != NULL )
    {
        _polyplexer->kill();
    }*/
}

bool Polyplexer::kill()
{

}
