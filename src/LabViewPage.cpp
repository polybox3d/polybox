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
    _selectedCamera="video0";

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

void LabViewPage::on_loadProfil_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Selectionner un profile"), ".", tr("Profile Files (*.xml)"));
    if ( ! fileName.isEmpty() )
    {
        _currentProfile = new QFile( fileName );
    }
}

void LabViewPage::on_saveProfil_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Enregistrer le profile"),
                                                    "./currentProfile.xml",
                                                    tr("Profile File (*.xml)"));
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

