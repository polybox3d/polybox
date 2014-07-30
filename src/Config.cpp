#include "Config.h"

#include <QDebug>

Config::Config()
{
}

QString Config::pathToHomeDirectory="/home/onslaught/";
QString Config::pathToPrinterSoftware=Config::pathToHomeDirectory+"Dev/reprapgiga/Repetier-HostModified/Repetier-Host-master/src/RepetierHost/bin/Release/RepetierHost.exe";
QString Config::pathToPrinterWorkingDir=Config::pathToHomeDirectory+"Dev/reprapgiga/RepetierHost";

QString Config::pathToLinuxCNC=Config::pathToHomeDirectory+"linuxcnc/";
QString Config::pathToSerialDevice="/dev/";

QString Config::pathToVirtualPolySerialDevice="/dev/";
QString Config::serialVirtualPolySerialPort="ttyPOLY";
QString Config::pathToWebcamDevice="/dev/";

QString Config::serialPortName="ttyACM0";//wildcard allowed
QString Config::linuxCNCCommand="linuxcnc";
QString Config::scannerLaserPath=Config::pathToHomeDirectory+"/fabscan100/qtTest/";
QString Config::defaultConfigFileName="./config.xml";
QString Config::pathToPolyplexerDaemon="../../externals/Polyplexer/PolyPlexer";


int Config::connectionUptimeDelay = 1000;
int Config::motherboardBaudrate=115200;
bool Config::bypassCheck = true ;

bool Config::disablePolyplexer = false;

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
                if(xml.name() == "cnc") {
                    parseCNC( &xml );
                }
                if(xml.name() == "printer") {
                    parsePrinter( &xml );
                }

                xml.readNext();
            }
            xml.readNext();
        }
        xml.readNext();
    }


}
void Config::parsePrinter(QXmlStreamReader *xml)
{
    while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "printer"))
    {
        if(xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if(xml->name() == "path_to_printer")
            {
                xml->readNext();
                Config::pathToPrinterSoftware = xml->text().toString();
            }
            if(xml->name() == "path_to_printer_workingdir")
            {
                xml->readNext();
                Config::pathToPrinterWorkingDir = xml->text().toString();
            }
        }
        xml->readNext();
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
            if(xml->name() == "path_to_virtudevice")
            {
                xml->readNext();
                Config::pathToVirtualPolySerialDevice = xml->text().toString();
            }
            if(xml->name() == "virtuserial_port")
            {
                xml->readNext();
                Config::serialVirtualPolySerialPort = xml->text().toString();
            }
            if(xml->name() == "path_polyplexer_daemon")
            {
                xml->readNext();
                Config::pathToPolyplexerDaemon = xml->text().toString();
            }
            if(xml->name() == "update_config_timer")
            {
                xml->readNext();
                Config::updateConfigModuleTimer = xml->text().toString().toInt();
            }
            if(xml->name() == "update_module_timer")
            {
                xml->readNext();
                Config::updateModuleTimer = xml->text().toString().toInt();
            }
            if(xml->name() == "by_pass_check")
            {
                xml->readNext();
                Config::bypassCheck = xml->text().toString().toInt();
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
    xml.writeTextElement("by_pass_check", QString::number(Config::bypassCheck) );
    xml.writeTextElement("path_to_virtudevice", Config::pathToVirtualPolySerialDevice);
    xml.writeTextElement("virtuserial_port", Config::serialVirtualPolySerialPort);
    xml.writeTextElement("path_polyplexer_daemon", Config::pathToPolyplexerDaemon);
    xml.writeTextElement("hardaware_timer", QString::number( Config::hardwareTimer) );
    xml.writeTextElement("update_config_timer", QString::number( Config::updateConfigModuleTimer) );
    xml.writeTextElement("update_module_timer", QString::number( Config::updateModuleTimer) );

    xml.writeEndElement();//GENERAL

    //SCANNER
    xml.writeStartElement("scanner");
    xml.writeTextElement("path_to_scanner",Config::scannerLaserPath );
    xml.writeEndElement();//scanner

    //CNC
    xml.writeStartElement("cnc");
    xml.writeTextElement("directory",Config::pathToLinuxCNC );
    xml.writeTextElement("bin_command", Config::linuxCNCCommand );
    xml.writeEndElement();//GENERAL


    //PRINTER
    xml.writeStartElement("printer");
    xml.writeTextElement("path_to_printer",Config::pathToPrinterSoftware );
    xml.writeTextElement("path_to_printer_workingdir", Config::pathToPrinterWorkingDir );
    xml.writeEndElement();//PRINTER

    xml.writeEndElement();//config
    xml.writeEndDocument();
    file->close();
}
