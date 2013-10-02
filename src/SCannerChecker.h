#ifndef SCANNERCHECKER_H
#define SCANNERCHECKER_H

#include <QWidget>

namespace Ui {
class SCannerChecker;
}

class SCannerChecker : public QWidget
{
    Q_OBJECT

public:
    explicit SCannerChecker(QWidget *parent = 0);
    ~SCannerChecker();

private:
    Ui::SCannerChecker *ui;
};

#endif // SCANNERCHECKER_H
