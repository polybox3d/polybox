#include "LabViewModule.h"

LabViewModule::LabViewModule(PolyboxModule *polybox, QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}


void LabViewModule::initAll()
{
    _mediaPlayer = NULL;
    _currentColor.setRgb( 0, 0, 0 );
    initFaceClass();
}

QStringList LabViewModule::getAllCamera(QString path_directory)
{
    QDir cameras_dir(path_directory);
    return cameras_dir.entryList(QStringList("video*"),QDir::System, QDir::Name) ;
}

QStringList LabViewModule::getConnectedCameraPath()
{
    QString command = "ls";
    QStringList parameters;
    parameters << PATH_TO_DEVICE ;
    QProcess* proc = new QProcess( this );
    proc->start( command, parameters );

}

void LabViewModule::initFaceClass()
{
    _top.name="top";
    _bot.name="bot";
    _left.name="left";
    _right.name="right";
    _back.name="back";
    _front.name="front";
}

bool LabViewModule::isReady() const
{
    return true;
}

void LabViewModule::setCamera(QString cam)
{
    _selectedCamera = cam;
}

QProcess* LabViewModule::startCamera(QProcess* process, QString camera)
{
    if ( process != NULL )
    {
        process->kill();
    }

    QString command = "vlc";
    QStringList parameters;
    parameters << "v4l2:///dev/"+camera ;
    process = new QProcess( );
    process->start( command, parameters );
    return process;
}

void LabViewModule::startCamera()
{
    _mediaPlayer = startCamera( _mediaPlayer, _selectedCamera );
}

void LabViewModule::startRecording()
{
    // is an already starting mediaplayer process ? If yes, we kill him
    //It's better, especially since the user can kill the process without Qt App
    if ( _mediaPlayer != NULL )
    {
        _mediaPlayer->kill();
    }

    //  Get output filename
    QString fileName = QFileDialog::getSaveFileName(NULL,
                                                    tr("Vidéo de sortie"),
                                                    "./output_video.ps");
    //start Recording

    QString command = "vlc";
    QStringList parameters;
    parameters << "v4l2:///dev/"+_selectedCamera<<"--file-logging"<<"--logfile=vlc-log.txt"
               <<"--sout=#transcode{vcodec=h264,vb=0,scale=0,acodec=mpga,ab=128,channels=2,samplerate=44100}:std{access=file,mux=mp4,dst='"+fileName+"'}";
    _mediaPlayer = new QProcess( this );
    _mediaPlayer->start( command, parameters );

}

void LabViewModule::setAllFacesLight(int light, bool horizontale, bool verticale)
{
    if ( horizontale )
    {
        _left.h = _right.h = _top.h = _bot.h = _back.h = _front.h = light;
    }
    if ( verticale)
    {
        _left.v = _right.v = _top.v = _bot.v = _back.v = _front.v = light;
    }
}

void LabViewModule::exportXmlAllFaces(QXmlStreamWriter *xml)
{
    _top.toXml( xml );
    _bot.toXml( xml );
    _left.toXml( xml );
    _right.toXml( xml );
    _back.toXml( xml );
    _front.toXml( xml );
}

void LabViewModule::parseMCode(QByteArray stream)
{
    QString str(stream);
    long value = SerialPort::embeddedstr2l( str, 0 );
    int idx = 0;
    int size = str.size();
    switch ( value )
    {
    case 621:
    {
        SerialPort::nextField( str, idx);
        while ( idx < size )
        {
            if ( str[idx] == 'R' )
            {
                SerialPort::nextValue( str, idx);
                _currentColor.setRed( SerialPort::embeddedstr2l( str, idx ) );
            }
            if ( str[idx] == 'E' )
            {
                SerialPort::nextValue( str, idx);
                _currentColor.setGreen( SerialPort::embeddedstr2l( str, idx ) );
            }
            if ( str[idx] == 'B' )
            {
                SerialPort::nextValue( str, idx);
                _currentColor.setBlue( SerialPort::embeddedstr2l( str, idx ) );
            }
            if ( str[idx] == 'I' )
            {
                SerialPort::nextValue( str, idx);
                _currentColor.setAlpha( SerialPort::embeddedstr2l( str, idx ) );
            }
            SerialPort::nextField( str, idx);
        }
    }
        break;
    case 614:
    {
        /*SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_, str[idx] );*/
    }
        break;
    default:
        break;
    }
   emit updateUI();
}

void LabViewModule::saveToXmlFile(QString filename)
{
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(NULL,
                              "Save to XML file",
                              "Couldn't write to "+filename,
                              QMessageBox::Ok);
        return;
    }
    QXmlStreamWriter xml(file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();

    xml.writeStartElement("profile");
    xml.writeTextElement("name", filename.split("/").last().split(".").first());
    //COLOR
    xml.writeStartElement("globalcolor");
    xml.writeTextElement("red", QString::number(_currentColor.red()));
    xml.writeTextElement("green", QString::number(_currentColor.green()) );
    xml.writeTextElement("blu", QString::number(_currentColor.blue()) );
    xml.writeTextElement("intensity", QString::number(_currentColor.alpha()) );
    xml.writeEndElement();//color

    exportXmlAllFaces( &xml );

    xml.writeEndElement();//profile
    xml.writeEndDocument();
    file->close();
}

void LabViewModule::parseGlobalcolor(QXmlStreamReader *xml)
{
    while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "globalcolor"))
    {
        if(xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if(xml->name() == "red")
            {
                xml->readNext();
                _currentColor.setRed( xml->text().toString().toInt() );
            }
            if(xml->name() == "green")
            {
                xml->readNext();
                _currentColor.setGreen( xml->text().toString().toInt() );
            }
            if(xml->name() == "blu")
            {
                xml->readNext();
                _currentColor.setBlue( xml->text().toString().toInt() );
            }
            if(xml->name() == "intensity")
            {
                xml->readNext();
                _currentColor.setAlpha( xml->text().toString().toInt() );
            }
        }
        xml->readNext();
    }
}
void LabViewModule::setFaceLight(QString face_name, int horizontale, int verticale)
{
    if ( face_name == "top" )
    {
        _top.h = horizontale;
        _top.v = verticale;
    }
    if ( face_name == "bot" )
    {
        _bot.h = horizontale;
        _bot.v = verticale;
    }
    if ( face_name == "left" )
    {
         _left.h = horizontale;
         _left.v = verticale;
    }
    if ( face_name == "right" )
    {
         _right.h = horizontale;
         _right.v = verticale;
    }
    if ( face_name == "back" )
    {
         _back.h = horizontale;
         _back.v = verticale;
    }
    if ( face_name == "front" )
    {
         _front.h = horizontale;
         _front.v = verticale;
    }
}

void LabViewModule::updateComponents()
{

}


