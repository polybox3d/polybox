#ifndef PRINTERPAGE_H
#define PRINTERPAGE_H

#include <QWidget>
#include <QProcess>

#include "MainWindow.h"

namespace Ui {
class PrinterPage;
}


#define DEFAULT_SOFTWARE_PRINTER_PATH "./repetier-host"

class PrinterPage : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterPage(QWidget *parent = 0);
    ~PrinterPage();

private slots:
    void on_pushButton_clicked();


private:
    Ui::PrinterPage *ui;
    QProcess* _printerSoftware;
    QString _printerSoftwarePath;

};

#endif // PRINTERPAGE_H

