#ifndef DIALOGWIDGET_H
#define DIALOGWIDGET_H

#include <QDialog>

namespace Ui {
class DialogWidget;
}

class DialogWidget : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWidget(QString displayedText, QWidget *parent = 0);
    ~DialogWidget();

private slots:
    void on_close_clicked();

    void on_cancel_clicked();

private:
    Ui::DialogWidget *ui;
};

#endif // DIALOGWIDGET_H
