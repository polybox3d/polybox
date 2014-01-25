#ifndef ONOFFBUTTON_H
#define ONOFFBUTTON_H

#include <QPushButton>

class OnOffButton : public QPushButton
{
    Q_OBJECT
public:
    explicit OnOffButton(QWidget *parent = 0);
    OnOffButton(int w, int h, QWidget *parent);
    void setSize( int w, int h);
    void setState( bool state );
signals:

public slots:
    void toggleState();
private:
    bool _isOn;

};

#endif // ONOFFBUTTON_H
