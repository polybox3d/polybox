#include "ConfigCNCPage.h"
#include "ui_ConfigCNCPage.h"

ConfigCNCPage::ConfigCNCPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigCNCPage)
{
    ui->setupUi(this);
    _linuxcncPath = DEFAULT_PATH_LINUXCNC;

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToModulePage()));
}

ConfigCNCPage::~ConfigCNCPage()
{
    delete ui;
}

void ConfigCNCPage::on_latencyHisto_clicked()
{
    QString command = _linuxcncPath+"/scripts/latencyhistogram";
    QProcess* histo = new QProcess( this );
    histo->start( command );
}


void ConfigCNCPage::on_latencyPlot_clicked()
{
    QString command = _linuxcncPath+"/scripts/latencyplot";
    QProcess* plot = new QProcess( this );
    plot->start( command );
}

void ConfigCNCPage::on_latencyTab_clicked()
{
    QString command = _linuxcncPath+"/scripts/latency-test";
    QProcess* simple = new QProcess( this );
    simple->start( command );
}

void ConfigCNCPage::on_configStepper_clicked()
{
    QString command = _linuxcncPath+"/bin/stepconf";
    QProcess* simple = new QProcess( this );
    simple->start( command );
}

void ConfigCNCPage::on_stressCNC_clicked()
{
    QString command = _linuxcncPath+"/scripts/torture.py";
    _script = new QProcess( this );
    _message = new QMessageBox( this );

    _script->start( command );
    connect( _script, SIGNAL(finished(int)),this, SLOT(outputReady()) );
    _message->exec();
    _message->setText("Working...");
}

void ConfigCNCPage::outputReady()
{
    _message->setText( "Done." );
}
