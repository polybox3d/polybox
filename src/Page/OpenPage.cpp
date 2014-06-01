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
    _handler = NULL;
}

OpenPage::~OpenPage()
{
    delete ui;
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
