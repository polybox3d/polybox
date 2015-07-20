#ifndef MOVEMENTMODULE_H
#define MOVEMENTMODULE_H

#include <QObject>
#include <QTimer>

#include "ComModule.h"

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
    static void moveRotByMaskRelative(int rot_mask, int dist, int direction);
    static void setCurrentPosRotByMask(int rot_mask, int pos);
    static void setEnableRotByMask(int rot_mask, bool enable);

    static void startWatchEndstop(int ms);
    static void stopWatchEndstop();

    static bool data2endstop( QString section, int start_pos );

    bool _x_min;
    bool _x_max;
    bool _x_home;

    bool _y_min;
    bool _y_max;
    bool _y_home;

    bool _z_min;
    bool _z_max;
    bool _z_home;


signals:

public slots:
    void parseMCode(QByteArray stream);
    void sendWatchEndstop();

private:
    explicit MovementModule(QObject *parent = 0);
    static MovementModule* _instance;
    QTimer _endstopTimer;

};

#endif // MOVEMENTMODULE_H
