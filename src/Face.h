#ifndef FACE_H
#define FACE_H

#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class Face
{
public:
    Face();
    int h;
    int v;
    QString name;

    void toXml( QXmlStreamWriter* xml );

    static int defaultLight;

};

#endif // FACE_H
