#include "MovementModule.h"


MovementModule* MovementModule::_instance = NULL;


inline int MovementModule::rotMask2Id( int axis_mask )
{
    if ( axis_mask & RXAxis ) return 0;
    if ( axis_mask & RYAxis ) return 1;
    if ( axis_mask & RZAxis ) return 2;

    return -1;
}


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
    _x_min = _x_max = _x_home = false;
    _y_min = _y_max = _y_home = false;
    _z_min = _z_max = _z_home = false;
}

void MovementModule::sendWatchEndstop()
{
    ComModule::getInstance()->sendCode("M"+QString(MCODE_GET_ENDSTOP_STATUS));
}

void MovementModule::startWatchEndstop(int ms)
{
    MovementModule* mm = MovementModule::getInstance();

    mm->_endstopTimer.start( ms ); //Config::movementWatchTimer()
    connect( &mm->_endstopTimer, SIGNAL(timeout()), mm, SLOT(sendWatchEndstop()));
}

void MovementModule::stopWatchEndstop()
{
    MovementModule* mm = MovementModule::getInstance();
    disconnect( &mm->_endstopTimer, SIGNAL(timeout()), mm, SLOT(sendWatchEndstop()));
}

bool MovementModule::data2endstop( QString section, int start_pos )
{
    int colon = section.indexOf(":", start_pos);
    return (section[colon+1] == 'L');
}

void MovementModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    if ( value == 0L )
    {
        int pos;
        foreach (QString section, str.split(" "))
        {
            /**      MIN      **/
            if ( (pos = section.indexOf("x_min")) != -1 )
            {
                _x_min = data2endstop( section, pos );
            }
            if ( (pos = section.indexOf("y_min")) != -1 )
            {
                _y_min = data2endstop( section, pos );
            }
            if ( (pos = section.indexOf("z_min")) != -1 )
            {
                _z_min = data2endstop( section, pos );
            }
            /**      MAX      **/
            if ( (pos = section.indexOf("x_max")) != -1 )
            {
                _x_max = data2endstop( section, pos );
            }
            if ( (pos = section.indexOf("y_max")) != -1 )
            {
                _y_max = data2endstop( section, pos );
            }
            if ( (pos = section.indexOf("z_max")) != -1 )
            {
                _z_max = data2endstop( section, pos );
            }
            /**      HOME      **/
            if ( (pos = section.indexOf("x_home")) != -1 )
            {
                _x_home = data2endstop( section, pos );
            }
            if ( (pos = section.indexOf("y_home")) != -1 )
            {
                _y_home = data2endstop( section, pos );
            }
            if ( (pos = section.indexOf("z_home")) != -1 )
            {
                _z_home = data2endstop( section, pos );
            }

        }
    }
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

void MovementModule::setCurrentPosRotByMask(int rot_mask, int pos)
{
    QString command;
    command = "G"+QString::number(GCODE_MOTOR_SET_ORIGIN)
            + " P"+QString::number(rotMask2Id(rot_mask))
            + " X"+QString::number(pos);

    ComModule::getInstance()->sendCode( command );
}

void MovementModule::moveRotByMask(int rot_mask, int dist)
{
    //move the motor
    QString command;
    command = "G"+QString::number(GCODE_MOTOR_GOTO)
            + " P"+QString::number(rotMask2Id(rot_mask))
            + " X"+QString::number(dist);

    ComModule::getInstance()->sendCode( command );
}

void MovementModule::setEnableRotByMask(int rot_mask, bool enable)
{
    QString command;
    command = "G"+QString::number(GCODE_MOTOR_SET_ENABLE)
            + " P"+QString::number(rotMask2Id(rot_mask))
            + " S"+QString::number(enable);

    ComModule::getInstance()->sendCode( command );
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
    if ( axis_mask & ZAxis )
        command += " Z"+QString::number(distance);


    command += " F"+QString::number(speed);
    ComModule::getInstance()->sendCode( command );
    if (  relative )
    {
        setAbsolutePositioning();
    }
}
