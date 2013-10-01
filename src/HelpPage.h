#ifndef HELPPAGE_H
#define HELPPAGE_H

#include <QWidget>

#include "HomeButton.h"
#include "MainWindow.h"

namespace Ui {
class HelpPage;
}

class HelpPage : public QWidget
{
    Q_OBJECT

public:
    explicit HelpPage(QWidget *parent = 0);
    ~HelpPage();
public slots:
    void backPage();
private:
    Ui::HelpPage *ui;
};

#endif // HELPPAGE_H
