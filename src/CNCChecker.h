#ifndef CNCCHECKER_H
#define CNCCHECKER_H

#include <QWidget>
#include <QPaintEvent>

#include "CNCModule.h"
#include "AbstractChecker.h"

namespace Ui {
class CNCChecker;
}

class CNCChecker : public QWidget, public AbstractChecker
{
    Q_OBJECT

public:
    explicit CNCChecker(QWidget *parent = 0);
    CNCChecker(CNCModule* cnc, QWidget *parent = 0);
    void setModule(CNCModule *module);

    ~CNCChecker();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::CNCChecker *ui;
    CNCModule* _cnc;
};

#endif // CNCCHECKER_H
