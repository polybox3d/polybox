#include "Config.h"

#include <QDebug>

Config::Config()
{
}

QString Config::pathToHomeDirectory="/home/onslaught/";
QString Config::pathToPrinterSoftware=Config::pathToHomeDirectory+"Dev/reprapgiga/Repetier-HostModified/Repetier-Host-master/src/RepetierHost/bin/Release/RepetierHost.exe";
QString Config::pathToPrinterWorkingDir=Config::pathToHomeDirectory+"Dev/reprapgiga/RepetierHost";
QString Config::pathToLinuxCNC=Config::pathToHomeDirectory+"linuxcnc/";
QString Config::pathToWebcamDevice="/dev/";
QString Config::webcamName="video0";
QString Config::pathToSerialDevice="/dev/";

QString Config::pathToVirtualPolySerialDevice="/dev/";
QString Config::serialVirtualPolySerialPort="ttyPOLY";

QString Config::serialPortName="ttyACM0";//wildcard allowed
QString Config::linuxCNCCommand="linuxcnc";
QString Config::scannerLaserPath=Config::pathToHomeDirectory+"/fabscan100/qtTest/";
QString Config::defaultConfigFileName="./config.xml";
QString Config::pathToPolyplexerDaemon="/home/onslaught/Dev/reprapgiga/Tools-Polybox/polyplexer/PolyPlexer";

int Config::motherboardBaudrate=115200;
bool Config::bypassCheck = true ;
QColor Config::colorLabviewFaceSelected = QColor( 70, 230, 255 );
QString Config::ambiancePathFolder=":/xml/ambiances";

float Config::bedTempPla=60;
float Config::bedTempAbs=75;
float Config::bedTempNylon=70;
int Config::hardwareTimer=3000; // ms
int Config::updateConfigModuleTimer = 500; // 1sec = 1000 ms
int Config::updateModuleTimer = 1000; // 1sec = 1000 ms

QString Config::pathToJoypadOverlay=Config::pathToHomeDirectory+"joypadoverlay/src/JoypadOverlay";





void Config::init()
{
    // does the default file exists ? if yes, we load it, if no, we load the basic file form QtRessources.
    QDir dir;
    if ( dir.exists(Config::defaultConfigFileName) )
    {
        Config::importFromXmlFile( Config::defaultConfigFileName);
        qDebug()<<"Default config loaded";
    }
    else
    {
        Config::importFromXmlFile( INITIAL_CONFIG_FILE );
        qDebug()<<"Initial factory config loaded";
    }
}

void Config::importFromXmlFile( QString filename )
{
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QMap<QString, QString> config;
        // Let's check that we're really getting a config.
        if( xml.tokenType() != QXmlStreamReader::StartElement && xml.name() == "config") {
            return;
        }

        while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "config")) {
            if(xml.tokenType() == QXmlStreamReader::StartElement)
            {
                if(xml.name() == "name")
                {
                    xml.readNext();
                }
                if(xml.name() == "general")
                {
                    parseGeneral( &xml );
                }
                if(xml.name() == "webcam") {
                    parseWebcam( &xml );
                }
                if(xml.name() == "cnc") {
                    parseCNC( &xml );
                }

                xml.readNext();
            }
            xml.readNext();
        }
        xml.readNext();
    }


}

void Config::parseGeneral(QXmlStreamReader *xml)
{
    while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "general"))
    {
        if(xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if(xml->name() == "home_directory")
            {
                xml->readNext();
                Config::pathToHomeDirectory = xml->text().toString();
            }
            if(xml->name() == "device_path")
            {
                xml->readNext();
                Config::pathToSerialDevice = xml->text().toString();
            }
            if(xml->name() == "device_name")
            {
                xml->readNext();
                Config::serialPortName = xml->text().toString();
            }
            if(xml->name() == "baudrate")
            {
                xml->readNext();
                Config::motherboardBaudrate = xml->text().toString().toInt();
            }
        }
        xml->readNext();
    }

}
void Config::parseCNC(QXmlStreamReader *xml)
{
    while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "cnc"))
    {
        if(xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if(xml->name() == "directory")
            {
                xml->readNext();
                Config::pathToLinuxCNC = xml->text().toString();
            }
            if(xml->name() == "bin_command")
            {
                xml->readNext();
                Config::linuxCNCCommand = xml->text().toString();
            }
        }
        xml->readNext();
    }
}
void Config::parseWebcam(QXmlStreamReader *xml)
{
    while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "webcam"))
    {
        if(xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if(xml->name() == "directory")
            {
                xml->readNext();
                Config::pathToWebcamDevice = xml->text().toString();
            }
            if(xml->name() == "device_name")
            {
                xml->readNext();
                Config::webcamName = xml->text().toString();
            }
        }
        xml->readNext();
    }
}

void Config::saveToXmlFile( QString filename )
{
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();

    xml.writeStartElement("config");
    xml.writeTextElement("name", filename.split("/").last().split(".").first());
    //GENERAL
    xml.writeStartElement("general");
    xml.writeTextElement("home_directory",Config::pathToHomeDirectory );
    xml.writeTextElement("device_path", Config::pathToSerialDevice );
    xml.writeTextElement("device_name", Config::serialPortName );
    xml.writeTextElement("baudrate", QString::number( Config::motherboardBaudrate) );
    xml.writeEndElement();//GENERAL

    //GENERAL
    xml.writeStartElement("webcam");
    xml.writeTextElement("directory",Config::pathToWebcamDevice );
    xml.writeTextElement("device_name", Config::webcamName );
    xml.writeEndElement();//GENERAL

    //GENERAL
    xml.writeStartElement("cnc");
    xml.writeTextElement("directory",Config::pathToLinuxCNC );
    xml.writeTextElement("bin_command", Config::linuxCNCCommand );
    xml.writeEndElement();//GENERAL


    xml.writeEndElement();//config
    xml.writeEndDocument();
    file->close();
}
