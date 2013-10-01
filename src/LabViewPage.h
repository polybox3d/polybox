#ifndef LABVIEW_H
#define LABVIEW_H

#include <QWidget>

#include "MainWindow.h"
#include "HomeButton.h"

#include <QProcess>
#include <QFile>
#include <QColor>
#include <QFileDialog>

namespace Ui {
class LabViewPage;
}

class LabViewPage : public QWidget
{
    Q_OBJECT

public:
    explicit LabViewPage(QWidget *parent = 0);
    ~LabViewPage();
protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_startVisu_clicked();

    void on_loadProfil_clicked();

    void on_saveProfil_clicked();

    void on_r_valueChanged(int value);

    void on_g_valueChanged(int value);

    void on_b_valueChanged(int value);

    void on_rSpin_valueChanged(int arg1);

    void on_gSpin_valueChanged(int arg1);

    void on_bSpin_valueChanged(int arg1);

    void on_intensite_valueChanged(int value);

    void on_intensiteSpin_valueChanged(int arg1);

private:
    Ui::LabViewPage *ui;
    QProcess* _mediaPlayer;
    QFile* _currentProfile;
    QColor _currentColor;
};

#endif // LABVIEW_H
