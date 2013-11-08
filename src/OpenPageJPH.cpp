#include "OpenPageJPH.h"

#include "OpenPage.h"
#include "MainWindow.h"

OpenPageJPH::OpenPageJPH( OpenPage* openpage, QJoystick* joypad, QObject *parent):JoypadHandler(joypad,parent)
{
    _openpage = openpage;
}




void OpenPageJPH::handleJoypadEventAxis(int button, short value)
{
}
void OpenPageJPH::handleJoypadEventButton(int button, bool value)
{
    if ( value == 0 ) // release button, so we ignore that
    {
        return;
    }


}

void OpenPageJPH::update()
{
    if ( _joypad->getButton( JoypadHandler::ButtonHome ) )
    {
        _openpage->on_module_clicked();
    }
    if ( _joypad->getButton( JoypadHandler::ButtonSelect ) )
    {
        _openpage->on_warning_clicked();
    }
    if ( _joypad->getButton( JoypadHandler::ButtonBack ) )
    {
        _openpage->on_help_clicked();
    }
}
