#include "ContactPointLevelingPage.h"
#include "ui_ContactPointLevelingPage.h"

int ContactPointLevelingPage::next_id = 0;

ContactPointLevelingPage::ContactPointLevelingPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ContactPointLevelingPage)
{
    _id = (ContactPointLevelingPage::next_id++);
    _contactor = false;
    ui->setupUi(this);

}

ContactPointLevelingPage::~ContactPointLevelingPage()
{
    delete ui;
}

void ContactPointLevelingPage::initializePage()
{
    setupField();
    connect(PolyboxModule::getInstance(), SIGNAL(newData(QByteArray)),this,SLOT(parseMCode(QByteArray)));
}

void ContactPointLevelingPage::parseMCode(QByteArray stream)
{
    QString str(stream);
    int idx = 0;
    int size = str.size();

    if ( stream.contains("Z-probe state:"))
    {
        SerialPort::nextField( str, idx);
        SerialPort::nextField( str, idx);

       if ( str[idx] == 'H' )
       {
           _contactor = true;
       }
       else if ( str[idx] == 'L' )
       {
           if ( _contactor )
           {
               ui->startContactProcess->setEnabled( true );
           }
       }
    }
}

void ContactPointLevelingPage::setupField()
{
    if ( this->_id == 0 )
    {
        registerField("Az*",ui->a_z);
    }
    else if ( this->_id == 1 )
    {
        registerField("Bz*",ui->b_z);
    }
    else if ( this->_id == 1 )
    {
        registerField("Cz*",ui->c_z);
    }

    ui->a_z->setText(field("Az").toString());
    ui->b_z->setText(field("Bz").toString());
    ui->c_z->setText(field("Cz").toString());

    ui->a_x->setText(  Config::get(SETTINGS_GROUP,"contactPointA_x", "50").toString() );
    ui->a_y->setText( Config::get(SETTINGS_GROUP,"contactPointA_y", "50").toString() );

    ui->b_x->setText( Config::get(SETTINGS_GROUP,"contactPointB_x", "450").toString() );
    ui->b_y->setText( Config::get(SETTINGS_GROUP,"contactPointB_y", "50").toString() );

    ui->c_x->setText( Config::get(SETTINGS_GROUP,"contactPointC_x", "220").toString() );
    ui->c_y->setText( Config::get(SETTINGS_GROUP,"contactPointC_y", "450").toString() );

}

void ContactPointLevelingPage::on_startContactProcess_clicked()
{
    PolyboxModule::getInstance()->connector()->sendMCode(QString::number(MCODE_SEND_GCODE)+" "+QString::number(GCODE_SINGLE_ZPROBE));
}

