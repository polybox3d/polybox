#ifndef ATUBUTTON_H
#define ATUBUTTON_H

#include <QPushButton>
#include "ComModule.h"
#include "mcode.h"

class ATUButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ATUButton(QWidget *parent = 0);
    ATUButton(int w, int h, bool activated, QWidget *parent);
    void setSize( int w, int h);
    void setState( bool activated );
signals:

public slots:
    void toggleState();
private:
    bool _atuActivated;

};

#endif // ATUBUTTON_H
