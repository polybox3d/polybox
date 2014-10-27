#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>

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

private:
    Ui::DialogClient *ui;
};

#endif // DIALOGCLIENT_H
