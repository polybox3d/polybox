#ifndef DIALOGCONFIGSOFT_H
#define DIALOGCONFIGSOFT_H

#include <QDialog>

namespace Ui {
class DialogConfigSoft;
}

class DialogConfigSoft : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigSoft(QWidget *parent = 0);
    ~DialogConfigSoft();

private slots:

    void on_close_clicked();

    void on_validate_clicked();

private:
    Ui::DialogConfigSoft *ui;
};

#endif // DIALOGCONFIGSOFT_H
