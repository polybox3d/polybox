#ifndef MOVEMENTMODULE_H
#define MOVEMENTMODULE_H

#include <QObject>

#include "ComModule.h"

#define TABLE_SIZE_X 440
#define TABLE_SIZE_Y 440
#define TABLE_SIZE_Z 440

enum Axis
{
    XAxis=1, YAxis=2, ZAxis=4
};

class MovementModule : public QObject
{
    Q_OBJECT
public:



    explicit MovementModule(QObject *parent = 0);

    static void homing( char axis );
    static void disableAllMotors();
    static void setRelativePositioning();
    static void setAbsolutePositioning();
    static void moveAxis(char axis, bool relative, int distance, int speed);
    static void moveAxisByMask(int axis_mask, bool relative, int distance, int speed);


signals:

public slots:

};

#endif // MOVEMENTMODULE_H
