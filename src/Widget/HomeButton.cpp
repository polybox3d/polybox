#include "HomeButton.h"

HomeButton::HomeButton(QWidget *parent) :
    QPushButton(parent)
{
    changeIconOnConnectorType( Polyplexer::connectorType() );
    setText("");
    setIconSize( QSize(this->width(), this->height()) );
    //setGeometry(0,0,160,160);
    setFlat( true );
}


HomeButton::HomeButton( int w, int h, QWidget *parent) :
    QPushButton(parent)
{
    changeIconOnConnectorType(  Polyplexer::connectorType() );
    setText("");
    setSize( w, h);
    setFlat( true );
    connect( Polyplexer::getInstance( this ),
            SIGNAL(newType(PolyboxModule::ConnectorType)),
            this,
            SLOT(changeIconOnConnectorType(PolyboxModule::ConnectorType)));
}

void HomeButton::setSize(int w, int h)
{
    setGeometry(0,0,w,h);
    setIconSize( QSize(w, h) );
}


void HomeButton::changeIcon(QPixmap img)
{
    setIcon(img);
    setIconSize( QSize(this->width(), this->height()) );
}

void HomeButton::changeIconOnConnectorType(Polyplexer::ConnectorType type)
{
    /*if ( type == Polyplexer::ServerTCP)
    {
        changeIcon( QPixmap(":/img/img/logo_400_blu.png") );
    }
    else if ( type == PolyboxModule::CLientTCP)
    {
        changeIcon( QPixmap(":/img/img/logo_400_yellow.png") );
    }
    else //if ( type == Serial)
    {
        changeIcon( QPixmap(":/img/img/logo_400.png") );
    }*/
}
