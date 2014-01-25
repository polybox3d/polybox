#ifndef LABVIEWJPH_H
#define LABVIEWJPH_H

#include "JoypadHandler.h"

class LabViewModule;

#include <iostream>

using namespace std;

class LabViewJPH : public JoypadHandler
{
public:
    LabViewJPH( LabViewModule* labview, QJoystick* joypad, QObject *parent = 0);

public slots:
    virtual void handleJoypadEventAxis(int button, short value);
    virtual void handleJoypadEventButton(int button, bool value);
    virtual void update();
private:
    LabViewModule* _labview;
};

#endif // LABVIEWJPH_H
