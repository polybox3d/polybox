#include "WarningPage.h"
#include "ui_WarningPage.h"

WarningPage::WarningPage(PolyboxModule *polybox, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarningPage)
{
    ui->setupUi(this);
    _polybox = polybox;

    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), this, SLOT(goBack()));

    ui->generalWidget->setModule( _polybox->globalModule() );
    ui->scannerWidget->setModule( _polybox->scannerModule() );
    ui->cncWidget->setModule( _polybox->cncModule() );
    ui->printerWidget->setModule( _polybox->printerModule() );

    /* ui->cncWidget = new CNCChecker( this );
    ui->cncWidget->setGeometry( this->width()/2, this->height()/2, 400, 250);

    ui->scannerWidget = new SCannerChecker( this );
    ui->scannerWidget->setGeometry( 0, this->height()/2, 400, 250);

    ui->printerWidget = new PrinterChecker( this );
    ui->printerWidget->setGeometry( this->width()/2, 0, 400, 250);*/
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
    DialogConfigSoft dialog( _polybox, (QWidget*)this->parent());
    int value_ret = dialog.exec();
    if ( value_ret != 0 )
    {

    }
}

void WarningPage::on_dynamicTest_clicked()
{
    CHANGE_PAGE( DynamicTest );
}
