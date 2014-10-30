#include "OpenPage.h"
#include "ui_OpenPage.h"

OpenPage::OpenPage(PolyboxModule* poly,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenPage)
{
    if ( poly != NULL )
    {
        _polybox = poly;
    }
    else
    {
        qApp->exit( 42 );
    }
    ui->setupUi(this);
    changeLogo();
    _handler = NULL;

    connect(PolyboxModule::getInstance(),
            SIGNAL(newType(PolyboxModule::ConnectorType)),
            this,
            SLOT(changeLogo()));

}

OpenPage::~OpenPage()
{
    delete ui;
}

void OpenPage::changeLogo()
{
    PolyboxModule::ConnectorType type = PolyboxModule::getInstance()->connectorType();
    if ( type == PolyboxModule::ServerTCP)
    {
        ui->logo->setPixmap( QPixmap(":/img/img/logo_400_blu.png") );
    }
    else if ( type == PolyboxModule::CLientTCP)
    {
        ui->logo->setPixmap( QPixmap(":/img/img/logo_400_yellow.png") );
    }
    else //if ( type == Serial)
    {
        ui->logo->setPixmap( QPixmap(":/img/img/logo_400.png") );
    }
}

void OpenPage::setJoypad(QJoystick *joypad)
{
    _handler = new OpenPageJPH( this, joypad, this);
}
void OpenPage::disableJoypad()
{
    _handler->deleteLater();
    _handler = NULL;
}


void OpenPage::on_module_clicked()
{

    bool is_ok = _polybox->isCommonReady();
    if ( is_ok || Config::bypassCheck )
    {
        ((MainWindow*)this->parent())->changeStatePage( Module );
    }
    else
    {
        CheckerModele* checker = new CheckerModele((QWidget*)this->parent());


        checker->setWindowTitle("Etat de la machine");
        checker->setContentWidget( new GlobalChecker( _polybox->globalModule(),  checker));
        _polybox->globalModule()->updateComponents();
        int value_ret = checker->exec();
        if ( value_ret != 0 )
        {
            CHANGE_PAGE( static_cast<PageState>(value_ret) );
        }

    }


}


void OpenPage::on_help_clicked()
{
    ((MainWindow*)this->parent())->changeStatePage( Help );
}

void OpenPage::on_warning_clicked()
{
    ((MainWindow*)this->parent())->changeStatePage( Warning );
}
