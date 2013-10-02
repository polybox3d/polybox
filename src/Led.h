#ifndef LED_H
#define LED_H

#include <QLabel>

#define DEFAULT_LED_SIZE 20

class Led : public QLabel
{
    Q_OBJECT
public:
    explicit Led(QWidget *parent = 0);
    Led(bool activated, QWidget *parent);

signals:

public slots:
    void updateLed();
    void off();
    void on();
    void toggle();
    void setActivated( bool activated );
    void setSize( int w, int h );

private:
    void init();

    bool _activated;


};

#endif // LED_H
