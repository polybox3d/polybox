#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "OpenPage.h"
#include "HelpPage.h"
#include "ModulePage.h"
#include "LabViewPage.h"

#include "pageState.h"

namespace Ui {
class MainWindow;
}

#define CHANGE_PAGE ((MainWindow*)this->parent())->changeStatePage

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void changeStatePage( PageState new_state );
    void backToModulePage();

private:
    void updateStatePage();

    Ui::MainWindow *ui;
    PageState _currentState;

};

#endif // MAINWINDOW_H
