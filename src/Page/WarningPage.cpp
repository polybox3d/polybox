#include "WarningPage.h"
#include "DebugPin.h"
#include "ui_WarningPage.h"

WarningPage::WarningPage(PolyboxModule *polybox, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarningPage)
{
    ui->setupUi(this);
    _polybox = polybox;
    _updateComponentsTimer.start( Config::updateConfigModuleTimer()  );
    connect( &_updateComponentsTimer, SIGNAL(timeout()), this, SLOT(updateModules()));
    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), this, SLOT(goBack()));

    ui->generalWidget->setModule( _polybox->globalModule() );
    ui->scannerWidget->setModule( _polybox->scannerModule() );
    ui->cncWidget->setModule( _polybox->cncModule() );
    ui->printerWidget->setModule( _polybox->printerModule() );

}
void WarningPage::updateModules()
{
    bool running;
    running = Polyplexer::isConnected();

    ui->generalWidget->setEnabled( running );
    ui->scannerWidget->setEnabled( running );
    ui->cncWidget->setEnabled( running );
    ui->printerWidget->setEnabled( running );
    ui->console->setEnabled( running );
    ui->pinEditor->setEnabled( running );

    if ( running )
    {
        ui->generalWidget->updateModuleValues();
        ui->scannerWidget->updateModuleValues();
        ui->cncWidget->updateModuleValues();
        ui->printerWidget->updateModuleValues();
    }



}

void WarningPage::goBack()
{
    CHANGE_PAGE( Start );
}

WarningPage::~WarningPage()
{
    delete ui;
}

void WarningPage::on_help_clicked()
{
    CHANGE_PAGE( Help );
}

void WarningPage::on_configuration_clicked()
{
    QDesktopServices::openUrl(QUrl(Config::pathToConfigFile()+"/"+QCoreApplication::organizationName()+"/"+QCoreApplication::applicationName()+".conf"));
}

void WarningPage::on_console_clicked()
{
    MainWindow::getMainWindow()->startConsoleWindow();

}

void WarningPage::on_pinEditor_clicked()
{
    DebugPin* debugpin = new DebugPin();
    debugpin->setWindowTitle(tr("Editeur de pins"));
    debugpin->show();
}

void WarningPage::on_touchscreen_clicked()
{
    if ( ! QFile::exists( Config::pathToTouchScreenCalibrator()) )
    {
        QMessageBox::critical(0, QWidget::tr("Error, missing folder: TouchScreenCalibrator"), QWidget::tr("Error, TouchScreenCalibrator folder not found.  \n \n Commands :  \t cd ~; git clone https://github.com/polybox3d/TouchScreenCalibrator.git && cd ~/TouchScreenCalibrator && qmake && make \n") );
        return;
    }
    else if ( ! QFile::exists( Config::pathToTouchScreenCalibrator()+"/TouchScreenCalibrator") )
    {
        QMessageBox::critical(0, tr("Error, missing executable: TouchScreenCalibrator"), tr("Error, TouchScreenCalibrator executable not found.  \n Path: ")+Config::pathToTouchScreenCalibrator()+"/TouchScreenCalibrator" +tr(" \n Commands :  \t cd ~/TouchScreenCalibrator && qmake && make \n") );
        return;
    }

    QString command = Config::pathToTouchScreenCalibrator()+"/TouchScreenCalibrator";
    QStringList parameters;

    QProcess* touchscreen = new QProcess( qApp );
    touchscreen->execute( command, parameters);

}

void WarningPage::on_pushButton_clicked()
{
    CHANGE_PAGE( CalibratePlate );
}
