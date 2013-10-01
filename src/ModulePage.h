#ifndef MODULEPAGE_H
#define MODULEPAGE_H

#include <QWidget>
#include <iostream>

#include "pageState.h"
#include "MainWindow.h"

using namespace std;

namespace Ui {
class ModulePage;
}

class ModulePage : public QWidget
{
    Q_OBJECT

public:
    explicit ModulePage(QWidget *parent );
    ~ModulePage();

private slots:
    void on_labviewButton_clicked();

private:
    Ui::ModulePage *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    float _base_scaling_size;
};

#endif // MODULEPAGE_H
