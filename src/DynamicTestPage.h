#ifndef DYNAMICTESTPAGE_H
#define DYNAMICTESTPAGE_H

#include <QWidget>

#include "MainWindow.h"
#include "pageState.h"

namespace Ui {
class DynamicTestPage;
}
/**
 * @brief The DynamicTestPage class A QWidget page for dynamic test. User can start test such as home-endstop, motors test, extruder test etc...
 */
class DynamicTestPage : public QWidget
{
    Q_OBJECT

public:
    explicit DynamicTestPage(QWidget *parent = 0);
    ~DynamicTestPage();

public slots:

    void backToConfiguration();

private:
    Ui::DynamicTestPage *ui;
};

#endif // DYNAMICTESTPAGE_H
