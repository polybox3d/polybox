#include "LabViewPage.h"
#include "ui_LabViewPage.h"

LabViewPage::LabViewPage(LabViewModule* labview, QWidget *parent, bool small_ui) :
    QWidget(parent),
    ui(new Ui::LabViewPage)
{
    _labview = labview;
    _update = false;
    connect( _labview , SIGNAL(updateUI()), this, SLOT(updateUI()));
    ui->setupUi(this);
    ui->intensityH->installEventFilter(this);
    ui->intensityV->installEventFilter(this);
    ui->r->installEventFilter(this);
    ui->g->installEventFilter(this);
    ui->b->installEventFilter(this);
    ui->intensite->installEventFilter(this);


    _currentProfile = NULL;

    loadCameras();

    loadDefaultAmbiances( Config::ambiancePathFolder );

    if ( ! small_ui )
    {
        HomeButton* hb = new HomeButton( 50,50, this );
        hb->setGeometry( this->width()-hb->width()-10,
                         this->height()-hb->height(),
                         hb->width(), hb->height());
        connect( hb, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToModulePage()));

        ui->softwareRadio->setChecked( true );
        on_softwareRadio_clicked();


    }
    else
    {
        //ui->backToHelp->deleteLater();
    }
    OnOffButton* onoff = new OnOffButton( 60, 30, this );
    onoff->setGeometry( this->width()-onoff->width()-10,
                        45,
                        onoff->width(), onoff->height());

    onoff->setState( _labview->isOn() );
    connect ( onoff, SIGNAL(released()), _labview, SLOT(toggleInter()));
    connect ( onoff, SIGNAL(released()), this, SLOT(updateUI()));
}

bool LabViewPage::eventFilter(QObject* watched, QEvent* event)
{
    QSlider* m_slider = dynamic_cast<QSlider*>(watched);
    if (event->type() == QEvent::MouseButtonPress && m_slider->isEnabled() )
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        m_slider->setValue(QStyle::sliderValueFromPosition(m_slider->minimum(), m_slider->maximum(), mouseEvent->x(), m_slider->width()));
    }

    return false;
}

LabViewPage::~LabViewPage()
{
    delete ui;
}

void LabViewPage::loadCameras()
{
    ui->cameraSelector->clear();
    ui->cameraSelector->addItems( LabViewModule::getAllCamera( Config::pathToWebcamDevice() ) );
    //1 or more camera detected, we setup UI
    if ( ui->cameraSelector->count() > 0 )
    {
        _labview->setCamera( ui->cameraSelector->currentText() );
        ui->startRecording->setEnabled( true );
        ui->startVisu->setEnabled( true );
        ui->startBroadcast->setEnabled( true );
    }
    else
    {
        ui->startRecording->setEnabled( false );
        ui->startVisu->setEnabled( false );
        ui->startBroadcast->setEnabled( false );
    }
}

void LabViewPage::setJoypad(QJoystick *joypad)
{
    _handler = new LabViewJPH( _labview, joypad, this);
}
void LabViewPage::disableJoypad()
{
    _handler->deleteLater();
    _handler = NULL;
}


void LabViewPage::on_startVisu_clicked()
{
    _labview->startCamera();
}


void LabViewPage::on_startRecording_clicked()
{
    _labview->startRecording();
}

void LabViewPage::on_startBroadcast_clicked()
{
    DialogBroadcast dialog((QWidget*)this->parent());
    int value_ret = dialog.exec();
    if ( value_ret == START_BROADCAST )
    {
        _labview->startBoardcast();
    }
}



void LabViewPage::importFromXmlFile(QString filename)
{
    //ui->individualLightRadio->setChecked( true );
    //ui->globalLightRadio->setChecked( false );
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this,
                              tr("Save to XML file"),
                              tr("Couldn't read from ")+filename,
                              QMessageBox::Ok);
        return;
    }
    QXmlStreamReader xml(file);
    while(!xml.atEnd() && !xml.hasError())
    {
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
                    _labview->parseGlobalcolor( &xml );
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
                h = xml->text().toString().toInt() ;
            }
            if(xml->name() == "verticale")
            {
                xml->readNext();
                v = xml->text().toString().toInt() ;
            }
        }
        xml->readNext();
    }
    _labview->setFaceLight( facename, h, v );
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
    updateUI();
}

void LabViewPage::on_saveProfil_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Enregistrer le profile"),
                                                    "./currentProfile.xml",
                                                    tr("Profile File (*.xml)"));
    if ( fileName != NULL && ! fileName.isEmpty() )
    {
        _labview->saveToXmlFile( fileName );
        ui->currentProfil->setText( fileName.split("/").last().split(".").first() );
        ui->selectAmb->setCurrentIndex( 0 );
    }
    updateUI();
}


void LabViewPage::loadDefaultAmbiances(QString folder_path)
{
    QDir directory(folder_path );
    QStringList ambiances_files =directory.entryList(QStringList("*.xml")) ;
    ui->selectAmb->addItem("--------","");
    foreach( QString file, ambiances_files )
    {
        ui->selectAmb->addItem(file.split(".").first(),folder_path+'/'+file);
    }
    updateUI();
}

//Update graphicals composants.
void LabViewPage::updateUI()
{
    // prevent update loop and multiple MCode send
    _update = true;
    //sliders
    ui->r->setValue( _labview->currentColor()->red());
    ui->g->setValue( _labview->currentColor()->green());
    ui->b->setValue( _labview->currentColor()->blue());
    ui->intensite->setValue( _labview->currentColor()->alpha());

    //Spin edit box
    ui->rSpin->setValue( _labview->currentColor()->red());
    ui->gSpin->setValue( _labview->currentColor()->green());
    ui->bSpin->setValue( _labview->currentColor()->blue());
    ui->intensiteSpin->setValue( _labview->currentColor()->alpha());

    ui->showColor->setStyleSheet("border-color: rgb(0, 0, 0);\nbackground-color: rgba("+
                                 QString::number(_labview->currentColor()->red())+", "+
                                 QString::number(_labview->currentColor()->green())+","+
                                 QString::number(_labview->currentColor()->blue())+","+
                                 QString::number(_labview->currentColor()->alpha())+");\nselection-color: rgb(255, 0, 4);");
    // rgb edit line
    QString rgb_str;
    QString tmp = QString::number(_labview->currentColor()->red(), 16);
    if ( tmp.size() < 2)
    {
        tmp = "0"+tmp;
    }
    rgb_str = tmp;

    tmp = QString::number(_labview->currentColor()->green(), 16 );
    if ( tmp.size() < 2)
    {
        tmp = "0"+tmp;
    }
    rgb_str += tmp;

    tmp = QString::number(_labview->currentColor()->blue(), 16 );
    if ( tmp.size() < 2)
    {
        tmp = "0"+tmp;
    }
    rgb_str += tmp;

    ui->rgbLineEdit->setText( rgb_str ) ;

    if ( ui->globalLightRadio->isChecked() )
    {
        int hi = _labview->getGlobalIntensityH();
        int vi = _labview->getGlobalIntensityV();
        ui->intensityV->setValue( vi );
        ui->intensityH->setValue( hi );
        ui->intensityVSpin->setValue( vi );
        ui->intensityHSpin->setValue( hi );
    }
    if ( ui->individualLightRadio->isChecked() )
    {
        if ( ! _selectedFaces.isEmpty() )
        {
            Face* face = _selectedFaces.first();
            ui->intensityV->setValue( face->v() );
            ui->intensityH->setValue( face->h() );
            ui->intensityVSpin->setValue( face->v() );
            ui->intensityHSpin->setValue( face->h() );
        }

    }
    if ( ! _labview->isOn())
    {
        ui->colorBox->setEnabled( false );
        ui->lightBox->setEnabled( false );
        ui->selectFaceBox->setEnabled( false );
        ui->startRecording->setEnabled( false );
        ui->startVisu->setEnabled( false );
    }
    loadCameras();



    _update = false;
}

void LabViewPage::setSelectedFacesLight(int light, bool horizontale, bool verticale)
{
    Face* current_face;
    foreach (current_face, _selectedFaces)
    {
        if ( horizontale )
        {
            current_face->setHIntensity( light );
        }
        if ( verticale )
        {
            current_face->setVIntensity( light );
        }
    }
    updateUI();
}

void LabViewPage::setColor(QColor color)
{

    if ( ui->individualLightRadio->isChecked() )
    {
        _labview->setAllFacesColor( color );
    }
    else
    {
        _labview->setAllFacesColor( color );
    }
}
void LabViewPage::setRed( int value )
{
    QColor *c = _labview->getGlobalColor();
    c->setRed( value );
    setColor( *c );

}
void LabViewPage::setGreen( int value )
{
    QColor *c = _labview->getGlobalColor();
    c->setGreen( value );
    setColor( *c );
}
void LabViewPage::setBlue( int value )
{
    QColor *c = _labview->getGlobalColor();
    c->setBlue( value );
    setColor( *c );
}
void LabViewPage::setAlpha( int value )
{
    QColor *c = _labview->getGlobalColor();
    c->setAlpha( value );
    setColor( *c );
}
void LabViewPage::setLight(int light, bool horizontale, bool verticale)
{
    if( _vhSliderLocked )
    {
        horizontale = verticale = true;
    }
    // user select global control
    if ( ui->globalLightRadio->isChecked() )
    {
        _labview->setAllFacesLight( light, horizontale, verticale );

    }
    if ( ui->individualLightRadio->isChecked() )
    {
        setSelectedFacesLight( light, horizontale, verticale );
    }
}


void LabViewPage::setActivateLightControl(bool activated)
{
    ui->intensityH->setEnabled( activated );
    ui->intensityHSpin->setEnabled( activated );
    ui->intensityV->setEnabled( activated );
    ui->intensityVSpin->setEnabled( activated );
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
    updateUI();
}

void LabViewPage::on_backFace_clicked()
{
    processFaceClick( &_labview->_back, ui->backFace, "pattern_back");
}

void LabViewPage::on_rightFace_clicked()
{
    processFaceClick( &_labview->_right, ui->rightFace, "pattern_r");
}

void LabViewPage::on_leftFace_clicked()
{
    processFaceClick( &_labview->_left, ui->leftFace, "pattern_l");
}

void LabViewPage::on_topFace_clicked()
{
    processFaceClick( &_labview->_top, ui->topFace, "pattern_t");
}

void LabViewPage::on_bottomFace_clicked()
{
    processFaceClick( &_labview->_front, ui->bottomFace, "pattern_b");
    //processFaceClick( &_labview->_bot, ui->bottomFace, "pattern_b");
}

void LabViewPage::on_frontFace_clicked()
{
    processFaceClick( &_labview->_front, ui->frontFace, "pattern_f");
}

void LabViewPage::on_globalLightRadio_clicked()
{
    ui->selectFaceBox->setEnabled( false );
    setActivateLightControl( true );
    updateUI();
}

void LabViewPage::on_individualLightRadio_clicked()
{
    ui->selectFaceBox->setEnabled( true );
    if ( _selectedFaces.isEmpty() )
    {
        setActivateLightControl( false );
    }
    else
    {
        setActivateLightControl( true );
    }
    updateUI();
}

void LabViewPage::on_r_valueChanged(int value)
{
    if ( _update ) return;
    this->setRed( value );
    updateUI();
}

void LabViewPage::on_g_valueChanged(int value)
{
    if ( _update ) return;
    setGreen( value );
    updateUI();
}

void LabViewPage::on_b_valueChanged(int value)
{
    if ( _update ) return;
    setBlue( value );
    updateUI();
}

void LabViewPage::on_rSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    this->setRed( arg1 );
    updateUI();
}

void LabViewPage::on_gSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    this->setGreen( arg1 );
    updateUI();
}

void LabViewPage::on_bSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    this->setBlue( arg1 );
    updateUI();
}

void LabViewPage::on_intensite_valueChanged(int value)
{
    if ( _update ) return;
    this->setAlpha( value );
    updateUI();
}

void LabViewPage::on_intensiteSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    this->setAlpha( arg1 );
    updateUI();
}

void LabViewPage::on_selectAmb_currentIndexChanged(int index)
{
    if ( _update ) return;
    QString filename = ui->selectAmb->itemData( index ).toString();
    if ( !filename.isEmpty() )
    {
        importFromXmlFile( filename );
        ui->currentProfil->setText( ui->selectAmb->itemText( index ) );
    }
    updateUI();
}

void LabViewPage::on_cameraSelector_currentIndexChanged(int index)
{
    if ( _update ) return;
    _labview->setCamera( ui->cameraSelector->itemText( index ) );
    updateUI();
}

void LabViewPage::on_rgbLineEdit_editingFinished()
{
    if ( _update ) return;
    QString color_str = ui->rgbLineEdit->text().right(6); // we delete #
    bool ok;
    _labview->currentColor()->setRed( color_str.left(2).toInt( &ok, 16) );
    _labview->currentColor()->setGreen( color_str.right(4).left(2).toInt(&ok, 16) );
    _labview->currentColor()->setBlue(color_str.right(2).toInt(&ok, 16) );
    updateUI();
}

void LabViewPage::on_showColor_clicked()
{
    QColor c = QColorDialog::getColor( _labview->currentColor()->toRgb(), this );
    //ui->showColor->setStyleSheet( "background-color: rgb("+QString::number(c.red())+", "+QString::number(c.green())+", "+QString::number(c.blue())+", "+QString::number(c.alpha())+");");
    QColor *cn = _labview->getGlobalColor();
    *cn = c;
    setColor( c );
    updateUI();

}


void LabViewPage::on_softwareRadio_clicked()
{
    _labview->sendController( LabViewModule::Software);
    ui->colorBox->setEnabled( true );
    ui->lightBox->setEnabled( true );
    ui->selectFaceBox->setEnabled( true );
}

void LabViewPage::on_teleRadio_clicked()
{
    _labview->sendController( LabViewModule::Manual );
    ui->colorBox->setEnabled( false );
    ui->lightBox->setEnabled( false );
    ui->selectFaceBox->setEnabled( false );
}


void LabViewPage::on_intensityV_valueChanged(int value)
{
    if ( _update ) return;
    setLight( value, false, true );
    updateUI();
}

void LabViewPage::on_intensityHSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    setLight( arg1, true, false );
    updateUI();
}

void LabViewPage::on_intensityVSpin_valueChanged(int arg1)
{
    if ( _update ) return;
    setLight( arg1, false, true );
    updateUI();
}

void LabViewPage::on_intensityH_valueChanged(int value)
{
    if ( _update ) return;
    setLight( value, true, false );
    updateUI();
}


void LabViewPage::on_lockButton_clicked()
{
    _vhSliderLocked = !_vhSliderLocked;

    if ( _vhSliderLocked )
    {
        setLight( ui->intensityH->value(), true, true );
        updateUI();
    }

}
