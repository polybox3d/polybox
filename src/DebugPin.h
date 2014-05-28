#ifndef DEBUGPIN_H
#define DEBUGPIN_H

#include <QWidget>
#include <QTimer>

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
    void parseData();

    void on_sendPinValue_clicked();

private:
    Ui::DebugPin *ui;
    QTimer _updtaeTimer;

    void setupComponents();
};

#endif // DEBUGPIN_H
