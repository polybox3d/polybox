#ifndef DEBUGPIN_H
#define DEBUGPIN_H

#include <QWidget>
#include <QTimer>

#include "ComModule.h"

namespace Ui {
class DebugPin;
}

class DebugPin : public QWidget
{
    Q_OBJECT

public:
    explicit DebugPin(QWidget *parent = 0);
    ~DebugPin();


private slots:
    void on_boardCombo_currentIndexChanged(int index);
    void updateComponents();
    void parseData(QByteArray data);

    void on_sendPinValue_clicked();

    void on_send0_clicked();

    void on_send255_clicked();

    void on_in_clicked();

    void on_out_clicked();

    void on_pinNumber_editingFinished();

    void on_pinNumber_textChanged(const QString &arg1);

private:
    Ui::DebugPin *ui;
    QTimer _updateTimer;

    void setupComponents();
};

#endif // DEBUGPIN_H
