#ifndef PRINTERSMALLUI_H
#define PRINTERSMALLUI_H

#include <QWidget>

namespace Ui {
class PrinterSmallUI;
}

class PrinterSmallUI : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterSmallUI(QWidget *parent = 0);
    ~PrinterSmallUI();

private:
    Ui::PrinterSmallUI *ui;
};

#endif // PRINTERSMALLUI_H
