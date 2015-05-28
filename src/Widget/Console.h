#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>
#include <QScrollBar>

#include "PolyboxModule.h"

/**
 * Input : green
 * Output : yellow
 */

namespace Ui {
class Console;
}

class Console : public QWidget
{
    Q_OBJECT

public:
    explicit Console(QWidget *parent = 0);
    ~Console();
public slots:
    void parseData();
    void dataWritten(QString data);

private slots:
    void on_sendCodeButton_clicked();

    void on_inputCode_returnPressed();

    void on_clearLog_clicked();

    void on_scrollToTop_clicked();

    void on_scrollToBot_clicked();

    void on_outputCB_toggled(bool checked);

    void on_inputCB_toggled(bool checked);

private:
    Ui::Console *ui;
    bool _displayInput;
    bool _displayOutput;
};

#endif // CONSOLE_H
