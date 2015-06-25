#include "MovementModule.h"


MovementModule* MovementModule::_instance = NULL;


MovementModule* MovementModule::getInstance()
{
    if ( _instance == NULL )
    {
        _instance = new MovementModule();
    }
    return _instance;
}

MovementModule::MovementModule(QObject *parent) :
    QObject(parent)
{
}

void MovementModule::sendWatchEndstop()
{
    //PolyboxModule::getInstance()->connector()->sendMCode();
}

void MovementModule::startWatchEndstop(int ms)
{
    MovementModule* mm = MovementModule::getInstance();

    mm->_endstopTimer.start( Config::movementWatchTimer() );
    connect( &mm->_endstopTimer, SIGNAL(timeout()), mm, SLOT(sendWatchEndstop()));
}

void MovementModule::stopWatchEndstop(int ms)
{

}




void MovementModule::homing(char axis)
{
    PolyboxModule::getInstance()->connector()->sendCode("G"+QString::number(GCODE_HOMING)+" "+axis);
}

void MovementModule::disableAllMotors()
{
    PolyboxModule::getInstance()->connector()->sendMCode(QString::number(GCODE_DISABLE_MOTOR));
}

void MovementModule::setAbsolutePositioning()
{
    PolyboxModule::getInstance()->connector()->sendCode("G"+QString::number(GCODE_SET_ABSOLUTE_POSITIONING));
}

void MovementModule::setRelativePositioning()
{
    PolyboxModule::getInstance()->connector()->sendCode("G"+QString::number(GCODE_SET_RELATIVE_POSITIONING));
}

void MovementModule::moveAxis(char axis, bool relative, int distance, int speed)
{
    // is axis a Letter ? If no, do nothing.
    if ( !QChar::isLetter(axis) )
        return;
    if (  relative )
        setRelativePositioning();

    PolyboxModule::getInstance()->connector()->sendCode("G"+QString::number(GCODE_MOVE_AXIS_LINEAR)
                                                        +" "+axis+QString::number(distance)
                                                        +" F"+QString::number(speed));
    if (  relative )
        setAbsolutePositioning();
}

void MovementModule::moveAxisByMask(int axis_mask, bool relative, int distance, int speed)
{
    if (  relative )
    {
        setRelativePositioning();
    }
    QString command;
    command = "G"+QString::number(GCODE_MOVE_AXIS_LINEAR);

    if ( axis_mask & XAxis )
        command += " X"+QString::number(distance);
    if ( axis_mask & YAxis )
        command += " Y"+QString::number(distance);
    if ( axis_mask & YAxis )
        command += " Z"+QString::number(distance);


    command += " F"+QString::number(speed);
    PolyboxModule::getInstance()->connector()->sendCode( command );
    if (  relative )
    {
        setAbsolutePositioning();
    }
}
