#ifndef ATUBUTTON_H
#define ATUBUTTON_H

#include <QPushButton>
#include "SerialPort.h"
#include "mcode.h"

class ATUButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ATUButton(QWidget *parent = 0);
    ATUButton(int w, int h, QWidget *parent);
    void setSize( int w, int h);

signals:

public slots:
    void toggleState();
private:
    bool _atuActivated;

};

#endif // ATUBUTTON_H
