#include "PlaterCalibrator.h"

PlaterCalibrator::PlaterCalibrator(QObject *parent) :
    QObject(parent)
{
    _rx = 0.0;
    _ry = 0.0;
}


void PlaterCalibrator::startCalibrationProcess()
{

}

float PlaterCalibrator::rx () const {
  return _rx;
}

void PlaterCalibrator::setRx ( float rx ) {
  _rx = rx;
  if (_rx > MAX_PLATER_ANGLE )
  {
      _rx = MAX_PLATER_ANGLE;
  }
  if (_rx < (MAX_PLATER_ANGLE*-1) )
  {
      _rx < MAX_PLATER_ANGLE *-1;
  }
}


float PlaterCalibrator::ry () const {
  return _ry;
}

void PlaterCalibrator::setRy ( float ry ) {
  _ry = ry;
  if (_ry > MAX_PLATER_ANGLE )
  {
      _ry = MAX_PLATER_ANGLE;
  }
  if (_ry < (MAX_PLATER_ANGLE*-1) )
  {
      _ry < MAX_PLATER_ANGLE *-1;
  }
}

