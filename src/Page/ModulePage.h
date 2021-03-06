#ifndef MODULEPAGE_H
#define MODULEPAGE_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include <iostream>
#include <QDesktopServices>

#include "pageState.h"
#include "MainWindow.h"
#include "DialogCNC.h"
#include "DialogScanner.h"
#include "CheckerModele.h"
#include "CNCChecker.h"
#include "PrinterChecker.h"
#include "SCannerChecker.h"
#include "PolyboxModule.h"

#include "ModulePageJPH.h"


using namespace std;

namespace Ui {
class ModulePage;
}

/**
  * @todo move DEFAULT define color to Config::.
  **/
/** Default **/
/*#define DEFAULT_DISABLE_BUTTON "rgb(150, 150, 150)"
#define DEFAULT_CNC_BUTTON     "rgb(180, 210, 255)"
#define DEFAULT_SCANNER_BUTTON "rgb(180, 255, 165)"
#define DEFAULT_LABVIEW_BUTTON "rgb(255, 230, 155)"
#define DEFAULT_PRINTER_BUTTON "rgb(255, 190, 190)"
*/
/** Bootstrap theme **/
#define DEFAULT_DISABLE_BUTTON "rgb(150, 150, 150)"
#define DEFAULT_CNC_BUTTON     "rgb(66, 139, 202)"
#define DEFAULT_SCANNER_BUTTON "rgb(92, 184, 92)"
#define DEFAULT_LABVIEW_BUTTON "rgb(240, 173, 78)"
#define DEFAULT_PRINTER_BUTTON "rgb(217, 83, 79)"


class ModulePage : public QWidget
{
    Q_OBJECT

public:
    explicit ModulePage(PolyboxModule* poly, QWidget *parent );
    ~ModulePage();
    void back();

protected:

public slots:
    void setJoypad( QJoystick* joypad );
    void disableJoypad();

    void on_labviewButton_clicked();

    void on_printerButton_clicked();

    void on_cncButton_clicked();

    void on_scannerButton_clicked();

    void changeLogo();

protected slots:
    void repaintComponents();

private slots:
    void on_shareButton_clicked();

    void on_configButton_clicked();

    void on_shareButton_2_clicked();

private:
    Ui::ModulePage *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    float _base_scaling_size;

    PolyboxModule* _polybox;
    ModulePageJPH* _handler;
    QTimer _updateTimer;
};

#endif // MODULEPAGE_H



