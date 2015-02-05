#include "ATUButton.h"

ATUButton::ATUButton(QWidget *parent) :
    QPushButton(parent)
{
    this->setFont( QFont("Sans Serif", 7) );
    setIcon(QPixmap(":/img/img/atu_all.png"));
    setText(QString::number(this->width()));
    setIconSize( QSize(this->width(), this->height()) );
    setFlat( false );
}

ATUButton::ATUButton(int w, int h, bool activated, QWidget *parent) :
    QPushButton(parent)
{
    this->setFont( QFont("Sans Serif", 7) );
    _atuActivated = activated;
    setSize( w, h);
    toggleState();
    connect ( this, SIGNAL(released()), this, SLOT(toggleState()));
}

void ATUButton::setState(bool activated)
{
    _atuActivated = !activated;
    toggleState();
}

void ATUButton::setSize(int w, int h)
{
    setGeometry(0,0,w,h);
    setIconSize( QSize(w, h) );
}


void ATUButton::toggleState()
{
    if ( _atuActivated )
    {
        setIcon(QPixmap(":/img/img/atu_all_on.png"));
        setText(tr("ATU"));
    }
    else
    {
        setIcon(QPixmap(":/img/img/atu_all.png"));
        setText(tr("ATU"));
    }
    _atuActivated = !_atuActivated;
    PolyboxModule::getInstance()->connector()->sendMCode( QString::number(MCODE_GLOBAL_SET_STATUS)+" S"+QString::number(_atuActivated) );
}
