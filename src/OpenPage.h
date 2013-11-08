#ifndef OPENPAGE_H
#define OPENPAGE_H

#include <QWidget>

#include "OpenPage.h"
#include "HelpPage.h"
#include "ModulePage.h"
#include "MainWindow.h"
#include "pageState.h"
#include "OpenPageJPH.h"

#include "PolyboxModule.h"

namespace Ui {
class OpenPage;
}
/**
 * @brief The OpenPage class QWidget use as welcoem page. This is the 1st page the user will see when opening the software.
 */
class OpenPage : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief OpenPage Constrcuts a welcome page for software opening with a parent and a poly as PolyboxModule.
     * @param poly
     * @param parent
     */
    explicit OpenPage(PolyboxModule *poly, QWidget *parent );
    ~OpenPage();

public slots:

    void setJoypad( QJoystick* joypad );
    void disableJoypad();

    /**
     * @brief on_module_clicked Open the main page if everything is okay. If the Box is not ready to use, this function call GlobalChecker and display what is wrong to the user (something not plugged, ATU on etc...)
     */
    void on_module_clicked();
    /**
     * @brief on_help_clicked Open the help page.
     */
    void on_help_clicked();
    /**
     * @brief on_warning_clicked Open the confuiguration/checker page. Display all data/ready status about the box.
     */
    void on_warning_clicked();

private:
    /**
     * @brief ui Graphical layer.
     */
    Ui::OpenPage *ui;
    PolyboxModule* _polybox;
    OpenPageJPH* _handler;
};

#endif // OPENPAGE_H



