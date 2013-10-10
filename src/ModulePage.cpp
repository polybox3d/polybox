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

}

ModulePage::~ModulePage()
{
    delete ui;
}

void ModulePage::paintEvent(QPaintEvent *)
{
    // CNC
    if ( _polybox->isCncReady() )
    {
        ui->cncButton->setStyleSheet( QString("background-color: ")+DEFAULT_CNC_BUTTON+";" );
    }
    else
    {
        ui->cncButton->setStyleSheet( QString("background-color: ")+DEFAULT_DISABLE_BUTTON+";" );
    }
    // SCANNER
    if ( _polybox->isScannerReady() )
    {
        ui->scannerButton->setStyleSheet(  QString("background-color: ")+DEFAULT_SCANNER_BUTTON+";" );
    }
    else
    {
        ui->scannerButton->setStyleSheet(  QString("background-color: ")+DEFAULT_DISABLE_BUTTON+";" );
    }
    // PRINTER
    if ( _polybox->isPrinterReady() )
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
            ((MainWindow*)this->parent())->changeStatePage( Start );
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
    bool printer_ok = _polybox->isPrinterReady();
    if ( printer_ok || Config::bypassCheck )
    {
        CHANGE_PAGE( Printer );
    }
    else
    {
        CheckerModele* checker = new CheckerModele((QWidget*)this->parent());

        checker->setWindowTitle("Etat de l'imprimante");
        checker->setContentWidget( new PrinterChecker( _polybox->printerModule(), checker));
        int value_ret = checker->exec();
        if ( value_ret != 0 )
        {
            CHANGE_PAGE( static_cast<PageState>(value_ret) );
        }
    }
}

void ModulePage::on_cncButton_clicked()
{
    bool cnc_ok = _polybox->isCncReady();
    if ( cnc_ok || Config::bypassCheck )
    {
        DialogCNC dialog((QWidget*)this->parent());
        int value_ret = dialog.exec();
        if ( value_ret != 0 )
        {
            CHANGE_PAGE( static_cast<PageState>(value_ret) );
        }
    }
    else
    {
        CheckerModele* checker = new CheckerModele((QWidget*)this->parent());


        checker->setWindowTitle("Etat de la CN");
        checker->setContentWidget( new CNCChecker( _polybox->cncModule(), checker));
        int value_ret = checker->exec();
        if ( value_ret != 0 )
        {
            CHANGE_PAGE( static_cast<PageState>(value_ret) );
        }

    }
}

void ModulePage::on_scannerButton_clicked()
{
    bool scanner_ok = _polybox->isScannerReady();
    if ( scanner_ok || Config::bypassCheck )
    {
        DialogScanner dialog((QWidget*)this->parent());
        int value_ret = dialog.exec();
        if ( value_ret != 0 )
        {
            CHANGE_PAGE( static_cast<PageState>(value_ret) );
        }
    }
    else
    {
        CheckerModele* checker = new CheckerModele((QWidget*)this->parent());

        checker->setWindowTitle("Etat du Scanner");
        checker->setContentWidget( new SCannerChecker( _polybox->scannerModule(), checker));
        int value_ret = checker->exec();
        if ( value_ret != 0 )
        {
            CHANGE_PAGE( static_cast<PageState>(value_ret) );
        }
    }
}
