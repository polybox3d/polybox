#ifndef CNCCHECKER_H
#define CNCCHECKER_H

#include <QWidget>

namespace Ui {
class CNCChecker;
}

class CNCChecker : public QWidget
{
    Q_OBJECT

public:
    explicit CNCChecker(QWidget *parent = 0);
    ~CNCChecker();

private:
    Ui::CNCChecker *ui;
};

#endif // CNCCHECKER_H
