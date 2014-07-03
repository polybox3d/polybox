#include "ModulePage.h"
#include "ui_ModulePage.h"

ModulePage::ModulePage(PolyboxModule* poly, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModulePage)
{
    if ( poly != NULL )
    {
        _polybox = poly;
    }
    else
    {
        qApp->exit( 42 );
    }
    _base_scaling_size = 10;
    ui->setupUi(this);
    ui->homeButton->installEventFilter( this );
    _updateTimer.start( Config::updateModuleTimer );
    connect( &_updateTimer, SIGNAL(timeout()), this, SLOT(repaintComponents()) );

}

ModulePage::~ModulePage()
{
    delete ui;
}

void ModulePage::back()
{
    ((MainWindow*)this->parent())->changeStatePage( Start );
}

void ModulePage::setJoypad(QJoystick *joypad)
{
    _handler = new ModulePageJPH( this, joypad, this);
}
void ModulePage::disableJoypad()
{
    _handler->deleteLater();
    _handler = NULL;
}

void ModulePage::repaintComponents()
{
    // CNC
    if ( _polybox->isCncReady() || Config::bypassCheck )
    {
        ui->cncButton->setStyleSheet( QString("background-color: ")+DEFAULT_CNC_BUTTON+";" );
    }
    else
    {
        ui->cncButton->setStyleSheet( QString("background-color: ")+DEFAULT_DISABLE_BUTTON+";" );
    }
    // SCANNER
    if ( _polybox->isScannerReady() || Config::bypassCheck )
    {
        ui->scannerButton->setStyleSheet(  QString("background-color: ")+DEFAULT_SCANNER_BUTTON+";" );
    }
    else
    {
        ui->scannerButton->setStyleSheet(  QString("background-color: ")+DEFAULT_DISABLE_BUTTON+";" );
    }
    // PRINTER
    if ( _polybox->isPrinterReady() || Config::bypassCheck )
    {
        ui->printerButton->setStyleSheet(  QString("background-color: ")+DEFAULT_PRINTER_BUTTON+";" );
    }
    else
    {
        ui->printerButton->setStyleSheet(  QString("background-color: ")+DEFAULT_DISABLE_BUTTON+";" );
    }

}

bool ModulePage::eventFilter(QObject *obj, QEvent *event)
{
    if ( obj == ui->homeButton )
    {
        if ( event->type() == QEvent::Enter )
        {
            ui->homeButton->setGeometry(ui->homeButton->x()-_base_scaling_size/2,
                                        ui->homeButton->y()-_base_scaling_size/2,
                                        ui->homeButton->width()+_base_scaling_size,
                                        ui->homeButton->height()+_base_scaling_size);
            return true;
        }
        else if ( event->type() == QEvent::MouseButtonRelease )
        {
            back();
            return true;
        }
        else if ( event->type() == QEvent::Leave )
        {
            ui->homeButton->setGeometry(ui->homeButton->x()+_base_scaling_size/2,
                                        ui->homeButton->y()+_base_scaling_size/2,
                                        ui->homeButton->width()-_base_scaling_size,
                                        ui->homeButton->height()-_base_scaling_size);
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}


void ModulePage::on_labviewButton_clicked()
{
    CHANGE_PAGE( LabView );
}


void ModulePage::on_printerButton_clicked()
{
    CHANGE_PAGE( Printer );
}

void ModulePage::on_cncButton_clicked()
{
    CHANGE_PAGE( CNC );
}

void ModulePage::on_scannerButton_clicked()
{
    CHANGE_PAGE( Scanner );
}
