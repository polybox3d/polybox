#ifndef INTERBUTTON_H
#define INTERBUTTON_H

#include <QWidget>

namespace Ui {
class InterButton;
}

class InterButton : public QWidget
{
    Q_OBJECT

public:
    explicit InterButton(QWidget *parent = 0);
    ~InterButton();

private:
    Ui::InterButton *ui;
};

#endif // INTERBUTTON_H
