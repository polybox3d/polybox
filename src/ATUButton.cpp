#include "ATUButton.h"

ATUButton::ATUButton(QWidget *parent) :
    QPushButton(parent)
{
    setIcon(QPixmap(":/img/img/atu_all.png"));
    setText(QString::number(this->width()));
    setIconSize( QSize(this->width(), this->height()) );
    //setGeometry(0,0,160,160);
    setFlat( false );
}


ATUButton::ATUButton( int w, int h, QWidget *parent) :
    QPushButton(parent)
{
    _atuActivated = true;
    setSize( w, h);
    toggleState();
    connect ( this, SIGNAL(released()), this, SLOT(toggleState()));
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
        setIcon(QPixmap(":/img/img/atu_all.png"));
        setText("ATU");
    }
    else
    {
        setIcon(QPixmap(":/img/img/atu_all_on.png"));
        setText("ATU");
    }
    _atuActivated = !_atuActivated;
    SerialPort::getSerial()->sendMCode( QString(MCODE_GLOBAL_SET_STATUS)+" S"+QString::number(_atuActivated) );
}
