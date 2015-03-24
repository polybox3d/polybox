#ifndef PLATERCALIBRATOR_H
#define PLATERCALIBRATOR_H

#include <QObject>
#include <QByteArray>

#include "AbstractModule.h"
#include "PolyboxModule.h"

#define MAX_PLATER_ANGLE 45


class PlaterCalibrator : public QObject, public AbstractModule
{
    Q_OBJECT
public:
    explicit PlaterCalibrator(PolyboxModule* polybox, QObject *parent = 0);
    virtual bool isReady() const;

    float rx () const;
    void setRx ( float rx ) ;

    float ry () const;
    void setRy ( float ry ) ;

    float rz () const;
    void setRz ( float rz ) ;

    float ax () const;
    void setAx ( float ax ) ;

    float ay () const;
    void setAy ( float ay ) ;

    float az () const;
    void setAz ( float az ) ;

    float getXOffset() const;
    float getYOffset() const;
    float getZOffset() const;

    void defineOffsetFromCurrentPos();
    void defineOffset( float x_offset, float y_offset, float z_offset);

signals:
    void updateUI();

public slots:
    void startCalibrationProcess();
    virtual void updateComponents();
    virtual void parseMCode(QByteArray stream);

private:
    virtual void initAll();

    /** relatif value. Ref: machine **/
    float _rx;
    float _ry;
    float _rz;

    /** Absolute value. i.e galilean **/
    float _ax;
    float _ay;
    float _az;

    void sendValues();
};

#endif // PLATERCALIBRATOR_H
