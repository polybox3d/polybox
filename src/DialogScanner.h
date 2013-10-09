#ifndef DIALOGSCANNER_H
#define DIALOGSCANNER_H

#include <QDialog>

#include "MainWindow.h"
#include "pageState.h"

namespace Ui {
class DialogScanner;
}
/**
 * @brief The DialogScanner class A really simple QDialog. Ask the user if he want to start Depth-sensor scanner or laser-scanner. Nothing more, Nothing less.
 */
class DialogScanner : public QDialog
{
    Q_OBJECT

public:
    explicit DialogScanner(QWidget *parent = 0);
    ~DialogScanner();

private slots:
    /**
     * @brief on_laser_clicked Called when the user click on laser scanner. Close the dialog and return ScannerLaser value.
     */
    void on_laser_clicked();
    /**
     * @brief on_primesense_clicked Called when the user click on primesense scanner. Close the dialog and return  XXX value value.
     */
    void on_primesense_clicked();
    /**
     * @brief on_close_clicked Close the dialog...
     */
    void on_close_clicked();
    /**
     * @brief on_goBackHelp_clicked Close the dialog and open help page.
     */
    void on_goBackHelp_clicked();

private:
    /**
     * @brief ui Graphical layer.
     */
    Ui::DialogScanner *ui;
};

#endif // DIALOGSCANNER_H
