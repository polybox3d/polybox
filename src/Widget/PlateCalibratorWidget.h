#ifndef PLATECALIBRATORWIDGET_H
#define PLATECALIBRATORWIDGET_H

#include <QWidget>
#include <QTimer>

#include "PolyboxModule.h"
#include "MainWindow.h"
#include "HomeButton.h"
#include "PlaterCalibrator.h"

namespace Ui {
class PlateCalibratorWidget;
}

class PlateCalibratorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlateCalibratorWidget(QWidget *parent = 0);
    ~PlateCalibratorWidget();

public slots:
    void goBack();
    void updateUi();

private slots:
    void on_y_plus_clicked();

    void on_y_minus_clicked();

    void on_x_minus_clicked();

    void on_x_plus_clicked();

private:
    Ui::PlateCalibratorWidget *ui;

    QTimer _update_timer;
    PlaterCalibrator* _plater;
};

#endif // PLATECALIBRATORWIDGET_H
