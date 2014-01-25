#include "DynamicTestPage.h"
#include "ui_DynamicTestPage.h"

DynamicTestPage::DynamicTestPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DynamicTestPage)
{
    ui->setupUi(this);


    HomeButton* hb = new HomeButton( 50,50, this );
    hb->setGeometry( this->width()-hb->width()-10,
                     this->height()-hb->height(),
                     hb->width(), hb->height());
    connect( hb, SIGNAL(clicked()), this, SLOT(backToConfiguration()));
}


void DynamicTestPage::backToConfiguration()
{
    CHANGE_PAGE( Warning );
}

DynamicTestPage::~DynamicTestPage()
{
    delete ui;
}
