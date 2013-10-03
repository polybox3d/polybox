#ifndef GLOBALCHECKER_H
#define GLOBALCHECKER_H

#include <QWidget>

namespace Ui {
class GlobalChecker;
}

class GlobalChecker : public QWidget
{
    Q_OBJECT

public:
    explicit GlobalChecker(QWidget *parent = 0);
    ~GlobalChecker();

private:
    Ui::GlobalChecker *ui;
};

#endif // GLOBALCHECKER_H
