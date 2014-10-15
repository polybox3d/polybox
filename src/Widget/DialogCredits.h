#ifndef DIALOGCREDITS_H
#define DIALOGCREDITS_H

#include <QDialog>

namespace Ui {
class DialogCredits;
}

class DialogCredits : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCredits(QWidget *parent = 0);
    ~DialogCredits();

private:
    Ui::DialogCredits *ui;
};

#endif // DIALOGCREDITS_H
