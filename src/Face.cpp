#include "Face.h"

int Face::defaultLight=0;

Face::Face()
{
    name="default-face";
    v=defaultLight;
    h=defaultLight;
}


void  Face::toXml(QXmlStreamWriter *xml)
{
    xml->writeStartElement("face");
    xml->writeAttribute("name", name);
    xml->writeTextElement("horizontale", QString::number(h) );
    xml->writeTextElement("verticale", QString::number(v) );
    xml->writeEndElement();
}
