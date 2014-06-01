#include "HelpPage.h"
#include "ui_HelpPage.h"

HelpPage::HelpPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpPage)
{
    ui->setupUi(this);
    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width(), this->height()-hb->height(), hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), this, SLOT(backPage()));

}

void HelpPage::backPage()
{
    CHANGE_PAGE( Start );

}

HelpPage::~HelpPage()
{
    delete ui;
}
