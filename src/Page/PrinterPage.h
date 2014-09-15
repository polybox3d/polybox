#ifndef PRINTERPAGE_H
#define PRINTERPAGE_H

#include <QWidget>
#include <QProcess>

#include "MainWindow.h"
#include "PrinterModule.h"
#include "ATUButton.h"
#include "OnOffButton.h"
#include <iostream>
#include <QTimer>

using namespace std;
namespace Ui {
class PrinterPage;
}


#define DEFAULT_SOFTWARE_PRINTER_PATH "./repetier-host"
#define MIN_TEMP_VALUE 20
class PrinterPage : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterPage(PrinterModule* printer, QWidget *parent = 0);
    ~PrinterPage();

private slots:

    void on_bedTempSlider_valueChanged(int value);

    void on_bedtempSpin_valueChanged(int arg1);

    void on_boxTempSlider_valueChanged(int value);

    void on_boxTempSpin_valueChanged(int arg1);

    void on_inactifBed_clicked();

    void on_plaBed_clicked();

    void on_absBed_clicked();

    void on_nylonBed_clicked();

    void on_box60_clicked();

    void on_box75_clicked();

    void on_boxInactif_clicked();

    void on_customBed_clicked();

    void on_boxCustom_clicked();

    void on_bed_bl_clicked();

    void on_bed_br_clicked();

    void on_bed_fl_clicked();

    void on_bed_fr_clicked();

    void on_selectAllBed_clicked();

    void on_selectNoBed_clicked();

    void on_fanPelletier_valueChanged(int value);

    void on_fanPulsor_valueChanged(int value);

    void on_fanExtractor_valueChanged(int value);

    void on_pelletierSpin_valueChanged(int arg1);

    void on_pulsorSpin_valueChanged(int arg1);

    void on_extractorSpin_valueChanged(int arg1);

    void repaintComponents();

    void on_startPrint_clicked();

    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    Ui::PrinterPage *ui;
    QProcess _printerSoftware;
    QString _printerSoftwarePath;
    PrinterModule* _printer;

    void setBedActivated(bool activated);
    void setChamberActivated(bool activated);
    void selectCustomBed();
    void selectCustomChamber();

    QTimer _updateModuleTimer;
    bool _update;
};

#endif // PRINTERPAGE_H
