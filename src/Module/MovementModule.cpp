#include "MovementModule.h"

MovementModule::MovementModule(QObject *parent) :
    QObject(parent)
{
}



void MovementModule::homing(char axis)
{
    ComModule::getInstance()->sendCode("G"+QString::number(GCODE_HOMING)+" "+axis);
}

void MovementModule::disableAllMotors()
{
    ComModule::getInstance()->sendMCode(QString::number(GCODE_DISABLE_MOTOR));
}

void MovementModule::setAbsolutePositioning()
{
    ComModule::getInstance()->sendCode("G"+QString::number(GCODE_SET_ABSOLUTE_POSITIONING));
}

void MovementModule::setRelativePositioning()
{
    ComModule::getInstance()->sendCode("G"+QString::number(GCODE_SET_RELATIVE_POSITIONING));
}

void MovementModule::moveAxis(char axis, bool relative, int distance, int speed)
{
    // is axis a Letter ? If no, do nothing.
    if ( !QChar::isLetter(axis) )
        return;
    if (  relative )
        setRelativePositioning();

    ComModule::getInstance()->sendCode("G"+QString::number(GCODE_MOVE_AXIS_LINEAR)
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
    ComModule::getInstance()->sendCode( command );
    if (  relative )
    {
        setAbsolutePositioning();
    }
}
