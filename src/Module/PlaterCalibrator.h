#ifndef PLATERCALIBRATOR_H
#define PLATERCALIBRATOR_H

#include <QObject>

#define MAX_PLATER_ANGLE 45


class PlaterCalibrator : public QObject
{
    Q_OBJECT
public:
    explicit PlaterCalibrator(QObject *parent = 0);


    float rx () const;
    void setRx ( float rx ) ;

    float ry () const;
    void setRy ( float ry ) ;


signals:

public slots:
    void startCalibrationProcess();

private:

    float _rx;
    float _ry;

};

#endif // PLATERCALIBRATOR_H
