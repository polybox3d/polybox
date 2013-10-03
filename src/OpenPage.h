#ifndef OPENPAGE_H
#define OPENPAGE_H

#include <QWidget>

#include "OpenPage.h"
#include "HelpPage.h"
#include "ModulePage.h"
#include "MainWindow.h"
#include "pageState.h"

namespace Ui {
class OpenPage;
}

class OpenPage : public QWidget
{
    Q_OBJECT

public:
    explicit OpenPage(QWidget *parent );
    ~OpenPage();

private slots:
    void on_module_clicked();

    void on_help_clicked();

    void on_warning_clicked();

private:
    Ui::OpenPage *ui;
};

#endif // OPENPAGE_H



