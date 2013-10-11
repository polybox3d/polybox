#include "LabViewPage.h"
#include "ui_LabViewPage.h"

LabViewPage::LabViewPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabViewPage)
{
    ui->setupUi(this);
    _mediaPlayer = NULL;
    _currentProfile = NULL;
    _currentColor.setRgb( 0, 0, 0 );

    ui->cameraSelector->addItems( getAllCamera( Config::pathToWebcamDevice ) );
    //1 or more camera detected, we setup UI
    if ( ui->cameraSelector->count() > 0 )
    {
        _selectedCamera = ui->cameraSelector->currentText();
        ui->startRecording->setEnabled( true );
        ui->startVisu->setEnabled( true );
    }


    initFaceClass();
    loadDefaultAmbiances( Config::ambiancePathFolder );

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToModulePage()));
    connect( ui->backToHelp, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToHelpPage()));
}

LabViewPage::~LabViewPage()
{
    delete ui;
}

void LabViewPage::initFaceClass()
{
    _top.name="top";
    _bot.name="bot";
    _left.name="left";
    _right.name="right";
    _back.name="back";
    _front.name="front";
}

QStringList LabViewPage::getAllCamera(QString path_directory)
{
    QDir cameras_dir(path_directory);
    return cameras_dir.entryList(QStringList("video*"),QDir::System, QDir::Name) ;
}

void LabViewPage::on_startVisu_clicked()
{
    // is an already starting mediaplayer process ? If yes, we kill him
    //It's better, especially since the user can kill the process without Qt App
    if ( _mediaPlayer != NULL )
    {
        _mediaPlayer->kill();
    }

    QString command = "vlc";
    QStringList parameters;
    parameters << "v4l2:///dev/"+_selectedCamera ;
    _mediaPlayer = new QProcess( this );
    _mediaPlayer->start( command, parameters );
}


void LabViewPage::on_startRecording_clicked()
{
    // is an already starting mediaplayer process ? If yes, we kill him
    //It's better, especially since the user can kill the process without Qt App
    if ( _mediaPlayer != NULL )
    {
        _mediaPlayer->kill();
    }

    //  Get output filename
    QString fileName = QFileDialog::getSaveFileName(this,
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


void LabViewPage::importFromXmlFile(QString filename)
{
    ui->individualLightRadio->setChecked( true );
    ui->globalLightRadio->setChecked( false );
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this,
                              "Save to XML file",
                              "Couldn't read from "+filename,
                              QMessageBox::Ok);
        return;
    }
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
        QMap<QString, QString> profile;
        // Let's check that we're really getting a profile.
        if( xml.tokenType() != QXmlStreamReader::StartElement && xml.name() == "profile") {
            return;
        }

        while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "profile")) {
            if(xml.tokenType() == QXmlStreamReader::StartElement)
            {
                if(xml.name() == "name")
                {
                    xml.readNext();
                }
                if(xml.name() == "globalcolor")
                {
                    parseGlobalcolor( &xml );
                }
                if(xml.name() == "face") {
                    parseFace( &xml );
                }

                xml.readNext();
            }
            xml.readNext();
        }
        xml.readNext();
    }

}
void LabViewPage::parseFace(QXmlStreamReader *xml)
{
    int h, v =0;
    QString facename="";
    while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "face"))
    {
        if(xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if( xml->attributes().hasAttribute("name")) {
                facename = xml->attributes().value("name").toString();
            }
            if(xml->name() == "horizontale")
            {
                xml->readNext();
                h = xml->text().toInt() ;
            }
            if(xml->name() == "verticale")
            {
                xml->readNext();
                v = xml->text().toInt() ;
            }
        }
        xml->readNext();
    }
    setFaceLight( facename, h, v );
}
void LabViewPage::setFaceLight(QString face_name, int horizontale, int verticale)
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

void LabViewPage::parseGlobalcolor(QXmlStreamReader *xml)
{
    while(!(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == "globalcolor"))
    {
        if(xml->tokenType() == QXmlStreamReader::StartElement)
        {
            if(xml->name() == "red")
            {
                xml->readNext();
                _currentColor.setRed( xml->text().toInt() );
            }
            if(xml->name() == "green")
            {
                xml->readNext();
                _currentColor.setGreen( xml->text().toInt() );
            }
            if(xml->name() == "blu")
            {
                xml->readNext();
                _currentColor.setBlue( xml->text().toInt() );
            }
            if(xml->name() == "intensity")
            {
                xml->readNext();
                _currentColor.setAlpha( xml->text().toInt() );
            }
        }
        xml->readNext();
    }
}

void LabViewPage::saveToXmlFile(QString filename)
{
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this,
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
void LabViewPage::exportXmlAllFaces(QXmlStreamWriter *xml)
{
    _top.toXml( xml );
    _bot.toXml( xml );
    _left.toXml( xml );
    _right.toXml( xml );
    _back.toXml( xml );
    _front.toXml( xml );
}

void LabViewPage::on_loadProfil_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Selectionner un profile"), ".", tr("Profile Files (*.xml)"));
    if ( fileName != NULL && ! fileName.isEmpty() )
    {
       importFromXmlFile( fileName );
       ui->currentProfil->setText( fileName.split("/").last().split(".").first() );
       ui->selectAmb->setCurrentIndex( 0 );
    }
}

void LabViewPage::on_saveProfil_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Enregistrer le profile"),
                                                    "./currentProfile.xml",
                                                    tr("Profile File (*.xml)"));
    if ( fileName != NULL && ! fileName.isEmpty() )
    {
        saveToXmlFile( fileName );
        ui->currentProfil->setText( fileName.split("/").last().split(".").first() );
        ui->selectAmb->setCurrentIndex( 0 );
    }
}

void LabViewPage::loadDefaultAmbiances(QString folder_path)
{
    QDir directory(folder_path );
    QStringList ambiances_files =directory.entryList(QStringList("*.xml")) ;
    ui->selectAmb->addItem("--------","");
    foreach( QString file, ambiances_files )
    {
        ui->selectAmb->addItem(file.split(".").first(),file);
    }
}

//Update graphicals composants.
void LabViewPage::paintEvent(QPaintEvent *)
{
    //  QPainter paint(this);
    //sliders
    ui->r->setValue( _currentColor.red());
    ui->g->setValue( _currentColor.green());
    ui->b->setValue( _currentColor.blue());
    ui->intensite->setValue( _currentColor.alpha());

    //Spin edit box
    ui->rSpin->setValue( _currentColor.red());
    ui->gSpin->setValue( _currentColor.green());
    ui->bSpin->setValue( _currentColor.blue());
    ui->intensiteSpin->setValue( _currentColor.alpha());

    ui->showColor->setStyleSheet("border-color: rgb(0, 0, 0);\nbackground-color: rgba("+
                                 QString::number(_currentColor.red())+", "+
                                 QString::number(_currentColor.green())+","+
                                 QString::number(_currentColor.blue())+","+
                                 QString::number(_currentColor.alpha())+");\nselection-color: rgb(255, 0, 4);");

    if ( ui->globalLightRadio->isChecked() )
    {
        ui->intensite_2->setValue( _top.v );
        ui->intensite_3->setValue( _top.h );
        ui->intensiteSpin_2->setValue( _top.v );
        ui->intensiteSpin_3->setValue( _top.h );
    }
    if ( ui->individualLightRadio->isChecked() )
    {
        if ( ! _selectedFaces.isEmpty() )
        {
            Face* face = _selectedFaces.first();
            ui->intensite_2->setValue( face->v );
            ui->intensite_3->setValue( face->h );
            ui->intensiteSpin_2->setValue( face->v );
            ui->intensiteSpin_3->setValue( face->h );
        }

    }
}

void LabViewPage::setAllFacesLight(int light, bool horizontale, bool verticale)
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
void LabViewPage::setSelectedFacesLight(int light, bool horizontale, bool verticale)
{
    Face* current_face;
    foreach (current_face, _selectedFaces)
    {
        if ( horizontale )
        {
            current_face->h = light;
        }
        if ( verticale )
        {
            current_face->v = light;
        }
    }
}

void LabViewPage::setLight(int light, bool horizontale, bool verticale)
{
    // user select global control
    if ( ui->globalLightRadio->isChecked() )
    {
        setAllFacesLight( light, horizontale, verticale );
    }
    if ( ui->individualLightRadio->isChecked() )
    {
        setSelectedFacesLight( light, horizontale, verticale );
    }
}


void LabViewPage::setActivateLightControl(bool activated)
{
    ui->intensite_2->setEnabled( activated );
    ui->intensite_3->setEnabled( activated );
    ui->intensiteSpin_2->setEnabled( activated );
    ui->intensiteSpin_3->setEnabled( activated );
}

void LabViewPage::processFaceClick(Face *face, QPushButton *face_button, QString base_name)
{
    if ( !ui->individualLightRadio->isChecked() )
    {
        return;
    }
    int index_of =  _selectedFaces.indexOf( face );
    if ( index_of == -1 ) // I.E not found
    {
        face_button->setStyleSheet( QString(BASE_STYLESHEET_FACE_BUTTON)+QRC_STYLESHEET_FACE_BUTTON+base_name+"_s.png);" );
        _selectedFaces.append( face );

        // We just an the 1st element, so we need to enabvle light controle slider/etc...
        if ( _selectedFaces.size() == 1)
        {
            setActivateLightControl( true );
        }
    }
    else
    {
        _selectedFaces.remove( index_of );
        face_button->setStyleSheet( QString(BASE_STYLESHEET_FACE_BUTTON)+QRC_STYLESHEET_FACE_BUTTON+base_name+".png);" );
        if ( _selectedFaces.isEmpty() )
        {
            setActivateLightControl( false );
        }
    }
}

void LabViewPage::on_backFace_clicked()
{
    processFaceClick( &_back, ui->backFace, "pattern_back");
}

void LabViewPage::on_rightFace_clicked()
{
    processFaceClick( &_right, ui->rightFace, "pattern_r");
}

void LabViewPage::on_leftFace_clicked()
{
    processFaceClick( &_left, ui->leftFace, "pattern_l");
}

void LabViewPage::on_topFace_clicked()
{
    processFaceClick( &_top, ui->topFace, "pattern_t");
}

void LabViewPage::on_bottomFace_clicked()
{
    processFaceClick( &_bot, ui->bottomFace, "pattern_b");
}

void LabViewPage::on_frontFace_clicked()
{
    processFaceClick( &_front, ui->frontFace, "pattern_f");
}

void LabViewPage::on_globalLightRadio_clicked()
{
    setActivateLightControl( true );
}

void LabViewPage::on_individualLightRadio_clicked()
{
    if ( _selectedFaces.isEmpty() )
    {
        setActivateLightControl( false );
    }
    else
    {
        setActivateLightControl( true );
    }
}

void LabViewPage::on_intensite_2_valueChanged(int value)
{
    setLight( value, false, true );
}

void LabViewPage::on_intensite_3_valueChanged(int value)
{
    setLight( value, true, false );
}

void LabViewPage::on_intensiteSpin_2_valueChanged(int arg1)
{
    setLight( arg1, false, true );
}

void LabViewPage::on_intensiteSpin_3_valueChanged(int arg1)
{
    setLight( arg1, true, false );
}

void LabViewPage::on_r_valueChanged(int value)
{
    _currentColor.setRed( value );
}

void LabViewPage::on_g_valueChanged(int value)
{
    _currentColor.setGreen( value );
}

void LabViewPage::on_b_valueChanged(int value)
{
    _currentColor.setBlue( value );
}

void LabViewPage::on_rSpin_valueChanged(int arg1)
{
    _currentColor.setRed( arg1 );
}

void LabViewPage::on_gSpin_valueChanged(int arg1)
{
    _currentColor.setGreen( arg1 );
}

void LabViewPage::on_bSpin_valueChanged(int arg1)
{
    _currentColor.setBlue( arg1 );
}

void LabViewPage::on_intensite_valueChanged(int value)
{
    _currentColor.setAlpha( value );
}

void LabViewPage::on_intensiteSpin_valueChanged(int arg1)
{
    _currentColor.setAlpha( arg1 );
}

void LabViewPage::on_selectAmb_currentIndexChanged(int index)
{
    QString filename = ui->selectAmb->itemData( index ).toString();
    if ( !filename.isEmpty() )
    {
        importFromXmlFile( filename );
        ui->currentProfil->setText( ui->selectAmb->itemText( index ) );
    }
}

void LabViewPage::on_cameraSelector_currentIndexChanged(int index)
{
    _selectedCamera = ui->cameraSelector->itemText( index );
}
