#ifndef WARNING_H
#define WARNING_H

#include <QWidget>

#include "MainWindow.h"
#include "CNCChecker.h"
#include "SCannerChecker.h"
#include "PrinterChecker.h"
#include "GlobalChecker.h"
#include "HomeButton.h"
#include "DialogConfigSoft.h"

#include "PolyboxModule.h"

namespace Ui {
class WarningPage;
}

class WarningPage : public QWidget
{
    Q_OBJECT

public:
    explicit WarningPage(PolyboxModule* polybox, QWidget *parent = 0);
    ~WarningPage();

public slots:

    void goBack();

private slots:
    void on_help_clicked();

    void on_configuration_clicked();

    void on_dynamicTest_clicked();

private:
    Ui::WarningPage *ui;
    PolyboxModule* _polybox;
};

#endif // WARNING_H
