#include "Config.h"

#include <QStandardPaths>
#include <QDebug>

QString Config::pathToHomeDirectory()
{
    return QStandardPaths::locate(QStandardPaths::HomeLocation, QString(), QStandardPaths::LocateDirectory);
}

QString Config::defaultConfigFileName="./config.xml";


QColor Config::colorLabviewFaceSelected = QColor( 70, 230, 255 );
QString Config::ambiancePathFolder=":/xml/ambiances";



/**************************************************************************
 *              GUI_TIMER_GROUP
 * ***********************************************************************/

int Config::hardwareTimer()
{
    return Config::get(GUI_TIMER_GROUP,"hardwareTimer", 3000).toInt();
}
int Config::updateConfigModuleTimer()
{
return Config::get(GUI_TIMER_GROUP,"updateConfigModuleTimer", 500).toInt();
}
int Config::updateModuleTimer()
{
    return Config::get(GUI_TIMER_GROUP,"updateModuleTimer", 1000).toInt();
}



/**************************************************************************
 *              SETTINGS_GROUP
 * ***********************************************************************/


QString Config::runtimePath()
{
    return Config::get(SETTINGS_GROUP,"runtimePath", "../../").toString();
}

QString Config::broadcastIP()
{
    return Config::get(SETTINGS_GROUP,"broadcastIP", "127.0.0.1").toString();
}

int Config::broadcastPort()
{
    return Config::get(SETTINGS_GROUP,"broadcastPort", "6842").toInt();
}

void Config::setBroadcastIP(QString IP)
{
    Config::set(SETTINGS_GROUP,"broadcastIP", IP);
}
void Config::setBroadcastPort(int port)
{
    Config::set(SETTINGS_GROUP,"broadcastPort", port);
}

QString Config::pathToConfigFile()
{
    return "Configurations";
}

QString Config::translationPath()
{
    return Config::get(SETTINGS_GROUP,"translationPath", Config::runtimePath()+"i18n").toString();
}

QString Config::pathToDropbox()
{
    return Config::get(SETTINGS_GROUP,"pathToDropbox",Config::pathToHomeDirectory()+"plbx-dropbox/").toString();
}

bool Config::bypassCheck()
{
    return Config::get(SETTINGS_GROUP,"bypassCheck", true).toBool();
}
/**************************************************************************
 *              GLOBAL_GROUP
 * ***********************************************************************/
float Config::webCamRotation()
{
    return Config::get(GLOBAL_GROUP,"webCamRotation", 0).toFloat();
}
/**************************************************************************
 *              CONNECTION_GROUP
 * ***********************************************************************/

QString Config::pathToSerialDevice()
{
    return Config::get(CONNECTION_GROUP,"pathToSerialDevice", "/dev/").toString();
}

QString Config::pathToVirtualPolySerialDevice()
{
    return Config::get(CONNECTION_GROUP,"pathToVirtualPolySerialDevice", "/dev/").toString();
}
QString Config::serialVirtualPolySerialPort()
{
    return Config::get(CONNECTION_GROUP,"serialVirtualPolySerialPort", "ttyPOLY").toString();
}
QString Config::pathToWebcamDevice()
{
    return Config::get(CONNECTION_GROUP,"pathToWebcamDevice", "/dev/").toString();
}

QString Config::serialPortName()
{
    return Config::get(CONNECTION_GROUP,"serialPortName", "ttyACM0").toString();
}

QString Config::pathToPolyplexerDaemon()
{
    return Config::get(CONNECTION_GROUP,"pathToPolyplexerDaemon", Config::runtimePath()+"externals/Polyplexer/PolyPlexer").toString();
}
int Config::connectionUptimeDelay()
{
    return Config::get(CONNECTION_GROUP,"connectionUptimeDelay", 1000).toInt();
}
int Config::motherboardBaudrate()
{
    return Config::get(CONNECTION_GROUP,"motherboardBaudrate", 115200).toInt();
}

bool Config::disablePolyplexer()
{
    return Config::get(CONNECTION_GROUP,"disablePolyplexer", false).toBool();
}

QHostAddress Config::serverListeningAddress()
{
    QString s = Config::get(CONNECTION_GROUP,"serverListeningAddress", "127.0.0.1").toString();
    QHostAddress h(s);
    return h;
}

quint16 Config::serverListeningPort()
{
    return Config::get(CONNECTION_GROUP,"serverListeningPort", "8862").toInt();
}

/**************************************************************************
 *              SCANNER_GROUP
 * ***********************************************************************/

/**************************************************************************
 *              CNC_GROUP
 * ***********************************************************************/

QString Config::pathToLinuxCNC()
{
    return Config::get(CNC_GROUP,"pathToLinuxCNC", Config::pathToHomeDirectory()+"linuxcnc/").toString();
}
QString Config::linuxCNCCommand()
{
    return Config::get(CNC_GROUP,"linuxCNCCommand", "linuxcnc").toString();
}

/**************************************************************************
 *              PRINTER_GROUP
 * ***********************************************************************/

QString Config::pathToPrinterSoftware()
{
    return Config::get(PRINTER_GROUP, "pathToPrinterSoftware",
                Config::pathToHomeDirectory()+"Dev/reprapgiga/Repetier-HostModified/Repetier-Host-master/src/RepetierHost/bin/Release/RepetierHost.exe" ).toString();
}
QString Config::pathToPrinterWorkingDir()
{
    return Config::get(PRINTER_GROUP, "pathToPrinterWorkingDir",
                Config::pathToHomeDirectory()+"Dev/reprapgiga/RepetierHost" ).toString();
}

float Config::bedTempPla()
{
    return Config::get(PRINTER_GROUP,"bedTempPla", 50).toInt();

}
float Config::bedTempAbs()
{
    return Config::get(PRINTER_GROUP,"bedTempAbs", 70).toInt();

}
float Config::bedTempNylon()
{
    return Config::get(PRINTER_GROUP,"bedTempNylon", 65).toInt();
}

QString Config::pathToJoypadOverlay=Config::pathToHomeDirectory()+"joypadoverlay/src/JoypadOverlay";



Config::Config()
{
}


void Config::init()
{
    QSettings().setValue("LOG/nbrExec", QSettings().value("LOG/nbrExec").toInt() + 1 );
    QSettings().setValue("ABOUT/version", QCoreApplication::applicationVersion() );
    // no settings found
    if ( QSettings().value(QString(SETTINGS_GROUP)+"/runtimePath").toString().isEmpty() )
    {
        // We must find the runtime path (means we want the top level of the git repository
        QDir dir;
        for ( u_int8_t i = 0 ; i < 6 ; ++i )
        {

            if ( dir.cd("src") )
            {
                dir.cdUp();
                Config::get(SETTINGS_GROUP,"runtimePath", dir.path()+"/").toString();
                return;
            }
            else
            {
                dir.cdUp();
            }
        }
        Config::get(ERRORS_GROUP,"runtimePath", "CRITICAL : Can't find src directory... The software will not work.").toString();
    }



    /*
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


*/
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
 /*   while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "printer"))
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
    }*/
}

void Config::parseGeneral(QXmlStreamReader *xml)
{/*
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
*/
}
void Config::parseCNC(QXmlStreamReader *xml)
{/*
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
    file->close();*/
}
