#ifndef FACE_H
#define FACE_H

#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QColor>

#include "SerialPort.h"
#include "mcode.h"

#define FACE_TOP_ID 0
#define FACE_BOT_ID 1
#define FACE_LEFT_ID 2
#define FACE_RIGHT_ID 3
#define FACE_BACK_ID 4
#define FACE_FRONT_ID 5

class Face
{
public:
    Face();
    QString name;
    int id;

    void setHIntensity( int h );
    void setVIntensity( int v );

    void sendIntensity();

    void setColor( int r, int g, int b);
    void setColor( QColor c);
    void sendColor();
    QColor color(){ return _color; }
    QColor* getColor(){ return &_color; }

    int h();
    int v();

    void toXml( QXmlStreamWriter* xml );

    static int defaultLight;

private:
    int _h;
    int _v;
    QColor _color;

};

#endif // FACE_H
