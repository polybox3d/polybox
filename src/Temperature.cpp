#include "Temperature.h"

Temperature::Temperature()
{
    _value = DEFAULT_TEMP_VALUE;
    _mode = Celcius;
}


bool Temperature::isDefault() const
{
    return (_value >= DEFAULT_TEMP_VALUE-EPSYLON && _value <= DEFAULT_TEMP_VALUE+EPSYLON);
}

float Temperature::getValue() const
{
    return _value;
}

QString Temperature::str()
{
    if ( _mode == Celcius )
    {
        if ( isDefault() )
        {
            return "-";
        }
        else
        {
            return QString::number(_value)+"°C";
        }
    }
    else
    {
        return "";
    }
}
