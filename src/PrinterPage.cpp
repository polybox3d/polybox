#include "PrinterPage.h"
#include "ui_PrinterPage.h"

PrinterPage::PrinterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterPage)
{
    ui->setupUi(this);
    _printerSoftware = NULL;
    _printerSoftwarePath = DEFAULT_SOFTWARE_PRINTER_PATH;

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToModulePage()));

    connect( ui->backToHelp, SIGNAL(clicked()), (MainWindow*)(parent), SLOT(backToHelpPage()));
}

PrinterPage::~PrinterPage()
{
    delete ui;
}


void PrinterPage::on_pushButton_clicked()
{
    QString command = _printerSoftwarePath;
    QStringList parameters;
    parameters << "" ;
    _printerSoftware = new QProcess( this );
    _printerSoftware->start( command, parameters );

}
