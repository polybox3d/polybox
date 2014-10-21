#ifndef DIALOGBROADCAST_H
#define DIALOGBROADCAST_H

#include <QDialog>

#include "MainWindow.h"
#include "Config.h"

namespace Ui {
class DialogBroadcast;
}

#define START_BROADCAST 1

class DialogBroadcast : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBroadcast(QWidget *parent = 0);
    ~DialogBroadcast();

private slots:
    void on_closeButton_clicked();

    void on_broadcastButton_clicked();

    void on_port_editingFinished();

private:
    Ui::DialogBroadcast *ui;
};

#endif // DIALOGBROADCAST_H
