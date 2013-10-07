#ifndef OPENPAGE_H
#define OPENPAGE_H

#include <QWidget>

#include "OpenPage.h"
#include "HelpPage.h"
#include "ModulePage.h"
#include "MainWindow.h"
#include "pageState.h"

#include "PolyboxModule.h"

namespace Ui {
class OpenPage;
}

class OpenPage : public QWidget
{
    Q_OBJECT

public:
    explicit OpenPage(PolyboxModule *poly, QWidget *parent );
    ~OpenPage();

private slots:
    void on_module_clicked();

    void on_help_clicked();

    void on_warning_clicked();

private:
    Ui::OpenPage *ui;
    PolyboxModule* _polybox;
};

#endif // OPENPAGE_H



