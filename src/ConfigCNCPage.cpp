#include "ConfigCNCPage.h"
#include "ui_ConfigCNCPage.h"

ConfigCNCPage::ConfigCNCPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigCNCPage)
{
    ui->setupUi(this);

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
