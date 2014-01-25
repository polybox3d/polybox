#include "HomeButton.h"

HomeButton::HomeButton(QWidget *parent) :
    QPushButton(parent)
{
    setIcon(QPixmap(":/img/img/logo_400.png"));
    setText(QString::number(this->width()));
    setIconSize( QSize(this->width(), this->height()) );
    //setGeometry(0,0,160,160);
    setFlat( true );
}


HomeButton::HomeButton( int w, int h, QWidget *parent) :
    QPushButton(parent)
{
    setIcon(QPixmap(":/img/img/logo_400.png"));
    setText("");
    setSize( w, h);
    setFlat( true );
}

void HomeButton::setSize(int w, int h)
{
    setGeometry(0,0,w,h);
    setIconSize( QSize(w, h) );
}

