#ifndef MODULEPAGEJPH_H
#define MODULEPAGEJPH_H

#include "JoypadHandler.h"

#include <iostream>


class ModulePage;

using namespace std;

class ModulePageJPH : public JoypadHandler
{
public:
    ModulePageJPH( ModulePage* modulepage, QJoystick* joypad, QObject *parent = 0);

public slots:
    virtual void handleJoypadEventAxis(int button, short value);
    virtual void handleJoypadEventButton(int button, bool value);
    virtual void update();
private:
    QJoystick* _joypad;
    ModulePage* _modulepage;
};

#endif // MODULEPAGEJPH_H
