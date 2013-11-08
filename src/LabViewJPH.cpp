#include "LabViewJPH.h"

#include "LabViewModule.h"
#include "MainWindow.h"


LabViewJPH::LabViewJPH(LabViewModule* labview, QJoystick* joypad, QObject *parent):JoypadHandler(joypad,parent)
{
    _labview = labview;
}



void LabViewJPH::handleJoypadEventAxis(int button, short value)
{
}
void LabViewJPH::handleJoypadEventButton(int button, bool value)
{
    if ( value == 0 ) // release button, so we ignore that
    {
        return;
    }


}

void LabViewJPH::update()
{

    /* GREEN == A */
    if ( _joypad->getAxis(JoypadHandler::LeftZAxis) > 0 )
    {
        if ( _joypad->getButton( JoypadHandler::ButtonA ) )
        {
            QColor* color = _labview->currentColor();
            color->setGreen( color->green()-( _joypad->getAxis(JoypadHandler::LeftZAxis)/(32767/6)  ));
            _labview->updateUI();
        }
        if ( _joypad->getButton( JoypadHandler::ButtonB ) )
        {
            QColor* color = _labview->currentColor();
            color->setRed( color->red()-(_joypad->getAxis(JoypadHandler::LeftZAxis)/(32767/6)));
            _labview->updateUI();
        }
        if ( _joypad->getButton( JoypadHandler::ButtonX ) )
        {
            QColor* color = _labview->currentColor();
            color->setBlue( color->blue()-(_joypad->getAxis(JoypadHandler::LeftZAxis)/(32767/6)));
            _labview->updateUI();
        }
        if ( _joypad->getButton( JoypadHandler::ButtonY ) )
        {
            QColor* color = _labview->currentColor();
            color->setAlpha( color->alpha()-(_joypad->getAxis(JoypadHandler::LeftZAxis)/(32767/6)));
            _labview->updateUI();
        }

    }
    if ( _joypad->getAxis(JoypadHandler::RightZAxis) > 0 )
    {
        if ( _joypad->getButton( JoypadHandler::ButtonA ) )
        {
            QColor* color = _labview->currentColor();
            color->setGreen( color->green()+( _joypad->getAxis(JoypadHandler::RightZAxis)/(32767/6)  ));
            _labview->updateUI();
        }
        if ( _joypad->getButton( JoypadHandler::ButtonB ) )
        {
            QColor* color = _labview->currentColor();
            color->setRed( color->red()+  (_joypad->getAxis(JoypadHandler::RightZAxis)/(32767/6)));
            _labview->updateUI();
        }
        if ( _joypad->getButton( JoypadHandler::ButtonX ) )
        {
            QColor* color = _labview->currentColor();
            color->setBlue( color->blue()+  (_joypad->getAxis(JoypadHandler::RightZAxis)/(32767/6)));
            _labview->updateUI();
        }
        if ( _joypad->getButton( JoypadHandler::ButtonY ) )
        {
            QColor* color = _labview->currentColor();
            color->setAlpha( color->alpha()+(_joypad->getAxis(JoypadHandler::RightZAxis)/(32767/6)));
            _labview->updateUI();
        }

    }

    if ( _joypad->getButton( JoypadHandler::ButtonHome ) )
    {
        CHANGE_PAGE( Module );
    }
}
