#ifndef FACE_H
#define FACE_H

#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include "SerialPort.h"

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

    int h();
    int v();

    void toXml( QXmlStreamWriter* xml );

    static int defaultLight;

private:
    int _h;
    int _v;

};

#endif // FACE_H
