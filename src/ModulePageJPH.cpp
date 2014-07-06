#include "ModulePageJPH.h"

#include "ModulePage.h"
#include "MainWindow.h"

ModulePageJPH::ModulePageJPH(ModulePage* modulepage, QJoystick* joypad, QObject *parent):JoypadHandler(joypad,parent)
{
    _joypad = joypad;
    _modulepage = modulepage;
}


void ModulePageJPH::handleJoypadEventAxis(int button, short value)
{


}
void ModulePageJPH::handleJoypadEventButton(int button, bool value)
{
    if ( value == 0 ) // release button, so we ignore that
    {
        return;
    }


}

void ModulePageJPH::update()
{

    if ( _joypad->getButton( JoypadHandler::ButtonA ) )
    {
        _modulepage->on_scannerButton_clicked();
    }
    if (_joypad->getButton( JoypadHandler::ButtonB ) )
    {
        _modulepage->on_printerButton_clicked();
    }
    if ( _joypad->getButton( JoypadHandler::ButtonX ) )
    {
        _modulepage->on_cncButton_clicked();
    }
    if ( _joypad->getButton( JoypadHandler::ButtonY ) )
    {
        _modulepage->on_labviewButton_clicked();
    }
    if ( _joypad->getButton( JoypadHandler::ButtonY ) )
    {
        _modulepage->on_labviewButton_clicked();
    }
    if ( _joypad->getButton( JoypadHandler::ButtonHome ) )
    {
        _modulepage->back();
    }
}
