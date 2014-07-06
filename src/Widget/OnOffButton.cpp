#include "OnOffButton.h"

OnOffButton::OnOffButton(QWidget *parent) :
    QPushButton(parent)
{
    _isOn = true;
    toggleState();
}


OnOffButton::OnOffButton( int w, int h, QWidget *parent) :
    QPushButton(parent)
{
    _isOn = true;
    toggleState();
    setSize( w, h);
    connect ( this, SIGNAL(released()), this, SLOT(toggleState()));
}

void OnOffButton::setSize(int w, int h)
{
    setGeometry(0,0,w,h);
    setIconSize( QSize(w, h) );
}
void OnOffButton::setState(bool state)
{
    _isOn = !state;
    toggleState();
}

void OnOffButton::toggleState()
{
    if ( _isOn )
    {
        setText("ON");
        setIcon(QPixmap(":/img/img/on.png"));
    }
    else
    {
        setText("OFF");
        setIcon(QPixmap(":/img/img/off.png"));

    }
    _isOn = !_isOn;
}
