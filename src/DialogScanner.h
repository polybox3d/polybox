#ifndef DIALOGSCANNER_H
#define DIALOGSCANNER_H

#include <QDialog>

#include "MainWindow.h"
#include "pageState.h"

namespace Ui {
class DialogScanner;
}

class DialogScanner : public QDialog
{
    Q_OBJECT

public:
    explicit DialogScanner(QWidget *parent = 0);
    ~DialogScanner();

private slots:
    void on_laser_clicked();

    void on_primesense_clicked();

    void on_close_clicked();

    void on_goBackHelp_clicked();

private:
    Ui::DialogScanner *ui;
};

#endif // DIALOGSCANNER_H
