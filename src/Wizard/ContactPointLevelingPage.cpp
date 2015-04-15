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
    if ( stream.contains("Z-probe:"))
    {
        SerialPort::nextValue( str, idx);

        float z = SerialPort::embeddedstr2l( str, idx );
        float x =0.0 , y = 0.0;
        SerialPort::nextField( str, idx);
        if ( str[idx] == 'X' )
        {
            SerialPort::nextValue( str, idx);
             x = SerialPort::embeddedstr2l( str, idx );
        }
        else if ( str[idx] == 'Y' )
        {
            SerialPort::nextValue( str, idx);
            y = SerialPort::embeddedstr2l( str, idx );
        }
        this->saveProbing( x, y, z);

        ui->x_pos->setText(QString::number(x));
        ui->y_pos->setText(QString::number(y));
        ui->z_pos->setText(QString::number(z));
    }

}
void ContactPointLevelingPage::saveProbing(float x, float  y, float z)
{
    if ( this->_id == 0 )
    {
        ui->a_x->setText( QString::number(x) );
        ui->a_y->setText( QString::number(y) );
        ui->a_z->setText( QString::number(z) );
    }
    else if ( this->_id == 1 )
    {
        ui->b_x->setText( QString::number(x) );
        ui->b_y->setText( QString::number(y) );
        ui->b_z->setText( QString::number(z) );
    }
    else if ( this->_id == 1 )
    {
        ui->c_x->setText( QString::number(x) );
        ui->c_y->setText( QString::number(y) );
        ui->c_z->setText( QString::number(z) );
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

