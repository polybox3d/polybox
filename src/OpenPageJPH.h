#ifndef OPENPAGEJPH_H
#define OPENPAGEJPH_H

#include "JoypadHandler.h"

class OpenPage;

class OpenPageJPH : public JoypadHandler
{
public:
    OpenPageJPH( OpenPage* openpage, QJoystick* joypad, QObject *parent = 0);

    public slots:
        virtual void handleJoypadEventAxis(int button, short value);
        virtual void handleJoypadEventButton(int button, bool value);
        virtual void update();
    private:
        OpenPage* _openpage;
};

#endif // OPENPAGEJPH_H
