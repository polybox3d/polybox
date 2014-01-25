#ifndef JOYPADHANDLER_H
#define JOYPADHANDLER_H

#include <QObject>
#include <QTimer>

#include "Qjoystick.h"

class JoypadHandler : public QObject
{
    Q_OBJECT
public:
    explicit JoypadHandler(QJoystick* joypad, QObject *parent = 0);
    virtual ~JoypadHandler(){}
enum Button{
    ButtonA, ButtonB, ButtonX, ButtonY,aa,aaaa,ButtonBack, ButtonSelect, ButtonHome
};
enum Axis
{
    LeftRL,LeftTB,LeftZAxis,RightRL,RightTB,RightZAxis
};

signals:
    void updated();
public slots:
    virtual void handleJoypadEventAxis(int button, short value)=0;
    virtual void handleJoypadEventButton(int button, bool value)=0;
    virtual void update()=0;
protected:
    QJoystick* _joypad;
    QTimer _updateTimer;

};

#endif // JOYPADHANDLER_H
