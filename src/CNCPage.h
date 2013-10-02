#ifndef CNCPAGE_H
#define CNCPAGE_H

#include <QWidget>

#include "HomeButton.h"
#include "MainWindow.h"

namespace Ui {
class CNCPage;
}

class CNCPage : public QWidget
{
    Q_OBJECT

public:
    explicit CNCPage(QWidget *parent = 0);
    ~CNCPage();

private:
    Ui::CNCPage *ui;
};

#endif // CNCPAGE_H
