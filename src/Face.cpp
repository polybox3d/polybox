#include "Face.h"

int Face::defaultLight=0;

Face::Face()
{
    id = 0;
    name="default-face";
    _v=defaultLight;
    _h=defaultLight;
}


void  Face::toXml(QXmlStreamWriter *xml)
{
    xml->writeStartElement("face");
    xml->writeAttribute("name", name);
    xml->writeTextElement("horizontale", QString::number(_h) );
    xml->writeTextElement("verticale", QString::number(_v) );
    xml->writeEndElement();
}


void Face::setHIntensity( int h )
{
    _h = h;
    sendIntensity();
}

void Face::setVIntensity( int v )
{
    _v = v;
    sendIntensity();
}
void Face::sendIntensity()
{
    SerialPort::getSerial()->sendMCode(QString::number(MCODE_LABVIEW_SET_FACE_I)+" S"+QString::number(id)+" X"+QString::number(_h)+"Y"+QString::number(_v));
}

int Face::h()
{
    return _h;
}

int Face::v()
{
    return _v;
}
