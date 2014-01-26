#include "LabViewModule.h"

LabViewModule::LabViewModule(PolyboxModule *polybox, QObject *parent) :
    QObject(parent), AbstractModule(polybox)
{
    initAll();
}


void LabViewModule::initAll()
{
    _mediaPlayer = NULL;
    setGlobalColor( QColor( 0, 0, 0 ) );
    initFaceClass();
}

void LabViewModule::setGlobalColor(QColor c)
{
    _currentColor = c;
    sendGlobalColor();
}

void LabViewModule::sendGlobalColor()
{
    QString param(QString(MCODE_LABVIEW_SET_RGB)+" R");
    param+=_currentColor.red();
    param+=" E";
    param+= _currentColor.green();
    param+=" P";
    param+=_currentColor.blue();
    param+=" I";
    param+=_currentColor.alpha();
    SerialPort::getSerial()->sendMCode( param.toStdString().c_str() );
}

QStringList LabViewModule::getAllCamera(QString path_directory)
{
    QList<QByteArray> cameras = QCamera::availableDevices();
    QStringList list_cameras;
    QCamera* camera;
    foreach(const QByteArray &deviceName, cameras )
    {
        list_cameras.append( camera->deviceDescription(deviceName) );
    }
    return list_cameras;
    /*QDir cameras_dir(path_directory);
    return cameras_dir.entryList(QStringList("video*"),QDir::System, QDir::Name) ;*/
}

QStringList LabViewModule::getConnectedCameraPath()
{
    QString command = "ls";
    QStringList parameters;
    parameters << PATH_TO_DEVICE ;
    QProcess* proc = new QProcess( this );
    proc->start( command, parameters );

}

void LabViewModule::toggleInter()
{
    _isOn = !_isOn;
    _polybox->port()->sendMCode( QString(MCODE_LABVIEW_SET_STATUS)+" S"+QString::number(_isOn) );
}

void LabViewModule::initFaceClass()
{
    _top.name="top";
    _top.id = FACE_TOP_ID;

    _bot.name="bot";
    _bot.id = FACE_BOT_ID;

    _left.name="left";
    _left.id = FACE_LEFT_ID;

    _right.name="right";
    _right.id = FACE_RIGHT_ID;

    _back.name="back";
    _back.id = FACE_BACK_ID;

    _front.name="front";
    _front.id = FACE_FRONT_ID;
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
        _left.setHIntensity( light);
        _right.setHIntensity( light);
        _top.setHIntensity( light);
        _bot.setHIntensity( light);
        _back.setHIntensity( light);
        _front.setHIntensity( light);
    }
    if ( verticale)
    {
        _left.setVIntensity( light);
        _right.setVIntensity( light);
        _top.setVIntensity( light);
        _bot.setVIntensity( light);
        _back.setVIntensity( light);
        _front.setVIntensity( light);
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
    case MCODE_LABVIEW_GET_RGB:
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
            if ( str[idx] == 'P' )
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
    case MCODE_LABVIEW_GET_GLOBAL_I:
    {
        SerialPort::nextField( str, idx);
        while ( idx < size )
        {
            if ( str[idx] == 'X' )
            {
                SerialPort::nextValue( str, idx);

                setAllFacesLight( SerialPort::embeddedstr2l( str, idx ), true, false );

            }
            if ( str[idx] == 'Y' )
            {
                SerialPort::nextValue( str, idx);
                setAllFacesLight( SerialPort::embeddedstr2l( str, idx ), false, true );
            }
            SerialPort::nextField( str, idx);
        }
        /*SerialPort::nextField( str, idx);
        SerialPort::parseTrueFalse( &_, str[idx] );*/
    }
        break;
    case MCODE_LABVIEW_GET_FACE_I:
    {
        SerialPort::nextField( str, idx);
        int x, y, id ;
        x=y=id=0;
        while ( idx < size )
        {
            if ( str[idx] == 'P' )
            {
                SerialPort::nextValue( str, idx);
                id = SerialPort::embeddedstr2l( str, idx );
            }
            if ( str[idx] == 'X' )
            {
                SerialPort::nextValue( str, idx);
                x = SerialPort::embeddedstr2l( str, idx );
                setFaceLight( SerialPort::embeddedstr2l( str, idx ), false, true );
            }
            if ( str[idx] == 'Y' )
            {
                SerialPort::nextValue( str, idx);
                y = SerialPort::embeddedstr2l( str, idx );
                setFaceLight( SerialPort::embeddedstr2l( str, idx ), false, true );
            }
            SerialPort::nextField( str, idx);
        }
        setFaceLight( id, x, y );
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
    xml.writeTextElement("red", QString::number( getGlobalColor().red()));
    xml.writeTextElement("green", QString::number( getGlobalColor().green()) );
    xml.writeTextElement("blu", QString::number( getGlobalColor().blue()) );
    xml.writeTextElement("intensity", QString::number( getGlobalColor().alpha()) );
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
    sendGlobalColor(); // we update firmware data
}
void LabViewModule::setFaceLight(int face_id, int horizontale, int verticale)
{
    if ( face_id == FACE_TOP_ID )
        setFaceLight( "top", horizontale, verticale );
    if ( face_id == FACE_BOT_ID )
        setFaceLight( "bot", horizontale, verticale );
    if ( face_id == FACE_LEFT_ID )
        setFaceLight( "left", horizontale, verticale );
    if ( face_id == FACE_RIGHT_ID )
        setFaceLight( "right", horizontale, verticale );
    if ( face_id == FACE_BACK_ID )
        setFaceLight( "back", horizontale, verticale );
    if ( face_id == FACE_FRONT_ID )
        setFaceLight( "front", horizontale, verticale );
}

void LabViewModule::setFaceLight(QString face_name, int horizontale, int verticale)
{
    Face* cface = NULL;
    if ( face_name == "top" )
    {
        cface = &_top;
    }
    if ( face_name == "bot" )
    {
        cface = &_bot;
    }
    if ( face_name == "left" )
    {
         cface = &_left;
    }
    if ( face_name == "right" )
    {
        cface = &_right;
    }
    if ( face_name == "back" )
    {
        cface = &_back;
    }
    if ( face_name == "front" )
    {
        cface = &_front;
    }
    if ( cface != NULL )
    {
        cface->setHIntensity( horizontale );
        cface->setVIntensity( verticale );
    }
}

void LabViewModule::updateComponents()
{

}


