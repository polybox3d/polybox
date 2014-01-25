#include "JoypadHandler.h"

JoypadHandler::JoypadHandler(QJoystick* joypad, QObject *parent) :
    QObject(parent)
{
    _joypad = joypad;
    connect(&_updateTimer, SIGNAL(timeout()), this, SLOT(update()));

    connect(_joypad, SIGNAL(axisChanged(int,short)), this, SLOT(handleJoypadEventAxis(int,short)) );
    connect(_joypad, SIGNAL(buttonChanged(int,bool)), this, SLOT(handleJoypadEventButton(int,bool)));
    _updateTimer.start(100);
}
