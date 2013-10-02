#ifndef MODULEPAGE_H
#define MODULEPAGE_H

#include <QWidget>
#include <iostream>

#include "pageState.h"
#include "MainWindow.h"
#include "DialogCNC.h"
#include "DialogScanner.h"
#include "CheckerModele.h"
#include "CNCChecker.h"
#include "PrinterChecker.h"
#include "SCannerChecker.h"

using namespace std;

namespace Ui {
class ModulePage;
}

class ModulePage : public QWidget
{
    Q_OBJECT

public:
    explicit ModulePage(QWidget *parent );
    ~ModulePage();

private slots:
    void on_labviewButton_clicked();

    void on_printerButton_clicked();

    void on_cncButton_clicked();

    void on_scannerButton_clicked();

private:
    Ui::ModulePage *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    float _base_scaling_size;
};

#endif // MODULEPAGE_H



