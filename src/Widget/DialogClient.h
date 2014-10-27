#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>
#include <QUdpSocket>

#include "Config.h"

namespace Ui {
class DialogClient;
}

class DialogClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClient(QWidget *parent = 0);
    ~DialogClient();

private slots:
    void on_close_clicked();
    void processPendingDatagrams();

private:
    Ui::DialogClient *ui;
    QUdpSocket* _udpSocket;
};

#endif // DIALOGCLIENT_H
