#include "PlaterCalibrator.h"

PlaterCalibrator::PlaterCalibrator(PolyboxModule* polybox, QObject *parent) :
QObject(parent), AbstractModule(polybox)
{
    initAll();

}
void PlaterCalibrator::initAll()
{
    _rx = 0.0;
    _ry = 0.0;
    _rz = 0.0;
    connect(PolyboxModule::getInstance(), SIGNAL(newData(QByteArray)),this,SLOT(parseMCode(QByteArray)));
}
bool PlaterCalibrator::isReady() const
{
    return true;
}

void PlaterCalibrator::updateComponents()
{

}

void PlaterCalibrator::defineOffsetFromCurrentPos()
{
    defineOffset( (_ax - _rx), (_ay - _ry), (_az - _rz));
}

void PlaterCalibrator::defineOffset(float x_offset, float y_offset, float z_offset)
{
    ComModule::getInstance()->sendMCode( QString::number(MCODE_GLOBAL_SET_GYRO_OFFSET)+" X"+QString::number(x_offset)
                           +" Y"+QString::number(y_offset)
                           +" Z"+QString::number(z_offset));

}

void PlaterCalibrator::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    int size = str.size();
    switch ( value )
    {
    case MCODE_GLOBAL_GET_GYRO_RELATIF:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'A')
            {
                if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    this->setRx( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='2')
                {
                    SerialPort::nextValue( str, idx);
                    this->setRy( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='3')
                {
                    SerialPort::nextValue( str, idx);
                    this->setRz( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
    case MCODE_GLOBAL_GET_GYRO_ABSOLU:
    {
        while ( idx < size )
        {
            SerialPort::nextField( str, idx);
            if ( str[idx] == 'Z')
            {
                if ( str[idx+1]=='0')
                {
                    SerialPort::nextValue( str, idx);
                    this->setAx( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='1')
                {
                    SerialPort::nextValue( str, idx);
                    this->setAy( SerialPort::embeddedstr2l( str, idx ) );
                }
                else if ( str[idx+1]=='2')
                {
                    SerialPort::nextValue( str, idx);
                    this->setAz( SerialPort::embeddedstr2l( str, idx ) );
                }
            }
        }
    }
        break;
    default:
        break;
    }
    emit updateUI();

}

void PlaterCalibrator::startCalibrationProcess()
{

}

float PlaterCalibrator::getXOffset() const
{
    return _ax - _rx ;
}

float PlaterCalibrator::getYOffset() const
{
    return _ay - _ry ;
}

float PlaterCalibrator::getZOffset() const
{
    return _az - _rz ;
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
  if (_rx < (MAX_PLATER_ANGLE*-1.0) )
  {
      _rx < MAX_PLATER_ANGLE *-1.0;
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
  if (_ry < (MAX_PLATER_ANGLE*-1.0) )
  {
      _ry < MAX_PLATER_ANGLE *-1.0;
  }
}

float PlaterCalibrator::rz () const {
  return _rz;
}

void PlaterCalibrator::setRz ( float rz ) {
  _rz = rz;
  if (_rz > MAX_PLATER_ANGLE )
  {
      _rz = MAX_PLATER_ANGLE;
  }
  if (_rz < (MAX_PLATER_ANGLE*-1.0) )
  {
      _rz < MAX_PLATER_ANGLE *-1.0;
  }
}


float PlaterCalibrator::ax () const {
  return _ax;
}

void PlaterCalibrator::setAx ( float ax ) {
  _ax = ax;
}

float PlaterCalibrator::ay () const {
  return _ay;
}

void PlaterCalibrator::setAy ( float ay ) {
  _ay = ay;
}

float PlaterCalibrator::az () const {
  return _az;
}

void PlaterCalibrator::setAz ( float az ) {
  _az = az;
}


