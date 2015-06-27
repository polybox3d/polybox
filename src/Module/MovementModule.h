#ifndef MOVEMENTMODULE_H
#define MOVEMENTMODULE_H

#include <QObject>
#include <QTimer>

#include "PolyboxModule.h"

#define TABLE_SIZE_X 440
#define TABLE_SIZE_Y 440
#define TABLE_SIZE_Z 440

enum Axis
{
    XAxis=1, YAxis=2, ZAxis=4, RXAxis=8, RYAxis=16, RZAxis=32
};

class MovementModule : public QObject
{
    Q_OBJECT
public:
    static inline int rotMask2Id(int axis_mask);


    static MovementModule* getInstance();

    static void homing( char axis );
    static void disableAllMotors();
    static void setRelativePositioning();
    static void setAbsolutePositioning();
    static void moveAxis(char axis, bool relative, int distance, int speed);
    static void moveAxisByMask(int axis_mask, bool relative, int distance, int speed);

    static void moveRotByMask(int rot_mask, int dist);
    static void setCurrentPosRotByMask(int rot_mask, int pos);
    static void setEnableRotByMask(int rot_mask, bool enable);

    static void startWatchEndstop(int ms);
    static void stopWatchEndstop(int ms);
    void sendWatchEndstop();


signals:

public slots:

private:
    explicit MovementModule(QObject *parent = 0);
    static MovementModule* _instance;
    QTimer _endstopTimer;
};

#endif // MOVEMENTMODULE_H
