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


void Face::setColor( int r, int g, int b)
{
    setColor( QColor(r,g,b) );
}
void Face::setColor( QColor c)
{
    _color = c;
    sendColor();
}

void Face::sendColor()
{
    SerialPort::getSerial()->sendMCode(QString::number(MCODE_LABVIEW_SET_FACE_RGB)
                                       +" S"+QString::number(this->id)
                                       +" R"+QString::number(_color.red())
                                       +" E"+QString::number(_color.green())
                                       +" P"+QString::number(_color.blue())
                                       +" I"+QString::number(_color.alpha()));
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
    SerialPort::getSerial()->sendMCode(QString::number(MCODE_LABVIEW_SET_FACE_I)+" S"+QString::number(id)+" X"+QString::number(_h)+" Y"+QString::number(_v));
}

int Face::h()
{
    return _h;
}

int Face::v()
{
    return _v;
}
