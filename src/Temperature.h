#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QString>

enum Mode{
    Celcius, Kelvin
};

#define DEFAULT_TEMP_VALUE -42.42
#define EPSYLON 0.01

class Temperature
{
public:
    explicit Temperature();
    float getValue() const;
    QString str();

    bool isDefault() const;

private:
    float _value;
    Mode _mode;

};

#endif // TEMPERATURE_H
