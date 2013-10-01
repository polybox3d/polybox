#include "LabViewModule.h"

LabViewModule::LabViewModule(QObject *parent) :
    QObject(parent)
{
}

QStringList LabViewModule::getConnectedCameraPath()
{
    QString command = "ls";
    QStringList parameters;
    parameters << PATH_TO_DEVICE ;
    QProcess* proc = new QProcess( this );
    proc->start( command, parameters );

}
