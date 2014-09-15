#include "CNCModule.h"
#include "MainWindow.h"

CNCModule::CNCModule(PolyboxModule *polybox, QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}

CNCModule::~CNCModule()
{

}

bool CNCModule::isReady() const
{
    return (_cncPlugged &&_motorLubPlugged &&
            (_levelLub != DEFAULT_LEVEL_LUB) &&_vacuumPlugged &&
            (_cncType != Unknowed) && (_cncType != Noone ) );
}
void CNCModule::initAll()
{
    _cncPlugged = false;
    _motorLubPlugged = false;
    _levelLub = false;
    _vacuumPlugged = false;
    _cncType = Noone;
    _linuxcnc = NULL;
}


void CNCModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;

    switch ( value )
    {
    case 600:
    {

    }
        break;
    case MCODE_CNC_TOOL_PLUGGED:
    {
        SerialPort::nextField( str, idx);
        if (str[idx] == 'H' )
        {
            _cncPlugged = true;
            _cncType = Manual;
        }
        else if( str[idx] =='P' )
        {
            _cncPlugged = true;
            _cncType = Proxxon;
        }
        else if( str[idx] == '0' )
        {
            _cncPlugged = false;
            _cncType = Noone;
        }

    }
        break;
    case MCODE_CNC_LUBRICANT_PLUGGED:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_motorLubPlugged, str[idx] );
    }
        break;
    case MCODE_CNC_LUBRICANT_LEVEL:
    {
        SerialPort::nextField( str, idx);
        long c_value = SerialPort::embeddedstr2l( str, idx );

        _levelLub = c_value;
        if ( _levelLub < 0)
        {
            _levelLub = 0;
        }

    }
        break;
    case MCODE_CNC_VACUUM_DETECTED:
    {
        SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_vacuumPlugged, str[idx] );
    }
        break;
    default:
        break;
    }
    emit updateUI();

}

void CNCModule::updateGlobalStatus()
{
//    _polybox->port()->sendMCode( 600 );
}

void CNCModule::updateToolPlugged()
{
    _polybox->port()->sendMCode( MCODE_CNC_TOOL_PLUGGED );
}

void CNCModule::updateLubricantLevel()
{
    _polybox->port()->sendMCode( MCODE_CNC_LUBRICANT_LEVEL );
}

void CNCModule::updateVacummPlugged()
{
    _polybox->port()->sendMCode( MCODE_CNC_VACUUM_DETECTED );
}

void CNCModule::linuxCNCFinished(int exitCode, QProcess::ExitStatus exitStatus )
{
    if ( exitCode == 2 )
    {
        MainWindow::errorWindow( tr("\n\nImpossible de lancer LinuxCNC."
                                    "Veuillez vérifier que le chemin d'accès est correct.\n\n"
                                    "Configuration > Paramètres logiciel \n\n")+_linuxcnc->readAllStandardError()+"\n\n" );
    }
    emit signalLinuxCNCFinished();
}

void CNCModule::linuxCNCError(QProcess::ProcessError error)
{
    if ( error == QProcess::FailedToStart)
    {
        MainWindow::errorWindow( tr("\n\nImpossible de lancer LinuxCNC. Le chemin d'accès à LinuxCNC ou les permissions sont incorrectes.\n\n"
                                    "Veuillez vérifier que le chemin d'accèset les permissions.\n\n"
                                    "Configuration > Paramètres logiciel \n\n")+_linuxcnc->readAll()+"\n\n"
                                 "Error Code : "+QString::number(QProcess::FailedToStart));
    }
    else
    {
        MainWindow::errorWindow( tr("\n\nImpossible de lancer LinuxCNC.\n\n")+_linuxcnc->readAll()+"\n\n"
                                 "Error Code : "+QString::number(QProcess::FailedToStart));
    }
    emit signalLinuxCNCFinished();
}

void CNCModule::startLinuxCNC()
{
    QString command = Config::linuxCNCCommand;
    _linuxcnc = new QProcess( this );
    connect( _linuxcnc, SIGNAL(finished(int,QProcess::ExitStatus)), this,SLOT(linuxCNCFinished(int,QProcess::ExitStatus)));
    connect( _linuxcnc, SIGNAL(error(QProcess::ProcessError)), this,SLOT(linuxCNCError(QProcess::ProcessError)));
    _linuxcnc->start( command);
}
bool CNCModule::isRunningLinuxCNC()
{
    if ( _linuxcnc != NULL )
    {
        return ( _linuxcnc->state() == QProcess::Running );
    }
    else
    {
        return false;
    }

}

void CNCModule::updateComponents()
{
    //updateGlobalStatus();
    updateLubricantLevel();
    updateToolPlugged();
    updateVacummPlugged();
    _polybox->port()->sendMCode( MCODE_CNC_LUBRICANT_PLUGGED );
    _polybox->port()->sendMCode( MCODE_CNC_RECYCLE_STATE );
    _polybox->port()->sendMCode( MCODE_CNC_VACUUM_STATE );
    _polybox->port()->sendMCode( MCODE_CNC_LUBRICANT_STATE );
}

bool CNCModule::cncPlugged()
{
    return _cncPlugged;
}
bool CNCModule::motorLubPlugged()
{
    return _motorLubPlugged;
}
float CNCModule::levelLub()
{
    return _levelLub;
}
bool CNCModule::vacuumPlugged()
{
    return _vacuumPlugged;
}
CNCType CNCModule::cncType()
{
    return _cncType;
}
