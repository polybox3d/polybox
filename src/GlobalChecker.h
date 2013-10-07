#ifndef GLOBALCHECKER_H
#define GLOBALCHECKER_H

#include <QWidget>

#include "AbstractChecker.h"
#include "GlobalModule.h"

namespace Ui {
class GlobalChecker;
}

class GlobalChecker : public QWidget, public AbstractChecker
{
    Q_OBJECT

public:
    explicit GlobalChecker(QWidget *parent = 0);
    explicit GlobalChecker(GlobalModule* global, QWidget *parent = 0);

    virtual void setModule( GlobalModule* module );
    ~GlobalChecker();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::GlobalChecker *ui;
    GlobalModule* _global;
};

#endif // GLOBALCHECKER_H
