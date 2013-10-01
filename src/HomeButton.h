#ifndef HOMEBUTTON_H
#define HOMEBUTTON_H

#include <QPushButton>

class HomeButton : public QPushButton
{
    Q_OBJECT
public:
    explicit HomeButton(QWidget *parent = 0);
    HomeButton(int w, int h, QWidget *parent);
    void setSize( int w, int h);


signals:

public slots:

};

#endif // HOMEBUTTON_H
