#ifndef DIALOGCNC_H
#define DIALOGCNC_H

#include <QDialog>

#include "MainWindow.h"
#include "pageState.h"

namespace Ui {
class DialogCNC;
}
/**
 * @brief The DialogCNC class Small QDialog about CNC. Allow the user to start configuration, help or just start the CNC software.
 */
class DialogCNC : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCNC(QWidget *parent = 0);
    ~DialogCNC();

private slots:
    /**
     * @brief on_startCnc_clicked Called when the user click on start CNC. Close the dialog and return CNC value
     */
    void on_startCnc_clicked();
    /**
     * @brief on_configuration_clicked Called when the user click on Configuration button. Close the dialog and
     */
    void on_configuration_clicked();
    /**
     * @brief on_help_clicked Called when the user click on Help button. Close the dialog and go to the Help page.
     */
    void on_help_clicked();
    /**
     * @brief on_close_clicked Called when the user click on close. Just close...o yeah.
     */
    void on_close_clicked();

private:
    /**
     * @brief ui Graphical layer.
     */
    Ui::DialogCNC *ui;
};

#endif // DIALOGCNC_H
