#ifndef DIALOGCNC_H
#define DIALOGCNC_H

#include <QDialog>

#include "MainWindow.h"
#include "pageState.h"

namespace Ui {
class DialogCNC;
}

class DialogCNC : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCNC(QWidget *parent = 0);
    ~DialogCNC();

private slots:

    void on_startCnc_clicked();

    void on_configuration_clicked();

    void on_help_clicked();

    void on_close_clicked();

private:
    Ui::DialogCNC *ui;
};

#endif // DIALOGCNC_H
