#ifndef PRINTERJPH_H
#define PRINTERJPH_H

#include <JoypadHandler.h>

class PrinterJPH : public JoypadHandler
{
public:
    PrinterJPH(QJoystick *joypad, QObject* parent=0);
};

#endif // PRINTERJPH_H
