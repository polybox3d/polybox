#ifndef MODULEPAGE_H
#define MODULEPAGE_H

#include <QWidget>
#include <QPaintEvent>
#include <iostream>

#include "pageState.h"
#include "MainWindow.h"
#include "DialogCNC.h"
#include "DialogScanner.h"
#include "CheckerModele.h"
#include "CNCChecker.h"
#include "PrinterChecker.h"
#include "SCannerChecker.h"
#include "PolyboxModule.h"


using namespace std;

namespace Ui {
class ModulePage;
}

#define DEFAULT_DISABLE_BUTTON "rgb(150, 150, 150)"
#define DEFAULT_CNC_BUTTON "rgb(150, 150, 150)"
#define DEFAULT_SCANNER_BUTTON "rgb(150, 150, 150)"
#define DEFAULT_LABVIEW_BUTTON "rgb(150, 150, 150)"
#define DEFAULT_PRINTER_BUTTON "rgb(150, 150, 150)"


class ModulePage : public QWidget
{
    Q_OBJECT

public:
    explicit ModulePage(PolyboxModule* poly, QWidget *parent );
    ~ModulePage();
protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_labviewButton_clicked();

    void on_printerButton_clicked();

    void on_cncButton_clicked();

    void on_scannerButton_clicked();

private:
    Ui::ModulePage *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    float _base_scaling_size;

    PolyboxModule* _polybox;
};

#endif // MODULEPAGE_H



