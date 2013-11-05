#include "LabViewPage.h"
#include "ui_LabViewPage.h"

LabViewPage::LabViewPage(LabViewModule* labview, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabViewPage)
{
    _labview = labview;
    connect( _labview , SIGNAL(updateUI()), this, SLOT(updateUI()));
    ui->setupUi(this);


    _currentProfile = NULL;


    ui->cameraSelector->addItems( getAllCamera( Config::pathToWebcamDevice ) );
    //1 or more camera detected, we setup UI
    if ( ui->cameraSelector->count() > 0 )
    {
        _labview->setCamera( ui->cameraSelector->currentText() );
        ui->startRecording->setEnabled( true );
        ui->startVisu->setEnabled( true );
    }

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


QStringList LabViewPage::getAllCamera(QString path_directory)
{
    QDir cameras_dir(path_directory);
    return cameras_dir.entryList(QStringList("video*"),QDir::System, QDir::Name) ;
}

void LabViewPage::on_startVisu_clicked()
{
    _labview->startCamera();
}


void LabViewPage::on_startRecording_clicked()
{
    _labview->startRecording();
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
        ui->selectAmb->addItem(file.split(".").first(),file);
    }
    updateUI();
}

//Update graphicals composants.
void LabViewPage::updateUI()
{
    //  QPainter paint(this);
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

    if ( ui->globalLightRadio->isChecked() )
    {
        int hi = _labview->getGlobalIntensityH();
        int vi = _labview->getGlobalIntensityV();
        ui->intensite_2->setValue( vi );
        ui->intensite_3->setValue( hi );
        ui->intensiteSpin_2->setValue( vi );
        ui->intensiteSpin_3->setValue( hi );
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
    updateUI();
}

void LabViewPage::setLight(int light, bool horizontale, bool verticale)
{
    // user select global control
    if ( ui->globalLightRadio->isChecked() )
    {
        _labview->setAllFacesLight( light, horizontale, verticale );
    }
    if ( ui->individualLightRadio->isChecked() )
    {
        setSelectedFacesLight( light, horizontale, verticale );
    }
    updateUI();
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
    processFaceClick( &_labview->_bot, ui->bottomFace, "pattern_b");
}

void LabViewPage::on_frontFace_clicked()
{
    processFaceClick( &_labview->_front, ui->frontFace, "pattern_f");
}

void LabViewPage::on_globalLightRadio_clicked()
{
    setActivateLightControl( true );
    updateUI();
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
    updateUI();
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
    _labview->currentColor()->setRed( value );
    updateUI();
}

void LabViewPage::on_g_valueChanged(int value)
{
    _labview->currentColor()->setGreen( value );
    updateUI();
}

void LabViewPage::on_b_valueChanged(int value)
{
    _labview->currentColor()->setBlue( value );
    updateUI();
}

void LabViewPage::on_rSpin_valueChanged(int arg1)
{
    _labview->currentColor()->setRed( arg1 );
    updateUI();
}

void LabViewPage::on_gSpin_valueChanged(int arg1)
{
    _labview->currentColor()->setGreen( arg1 );
    updateUI();
}

void LabViewPage::on_bSpin_valueChanged(int arg1)
{
    _labview->currentColor()->setBlue( arg1 );
    updateUI();
}

void LabViewPage::on_intensite_valueChanged(int value)
{
    _labview->currentColor()->setAlpha( value );
    updateUI();
}

void LabViewPage::on_intensiteSpin_valueChanged(int arg1)
{
    _labview->currentColor()->setAlpha( arg1 );
    updateUI();
}

void LabViewPage::on_selectAmb_currentIndexChanged(int index)
{
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
    _labview->setCamera( ui->cameraSelector->itemText( index ) );
    updateUI();
}
