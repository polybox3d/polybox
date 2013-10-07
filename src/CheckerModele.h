#ifndef CHECKERMODELE_H
#define CHECKERMODELE_H

#include <QWidget>
#include <QDialog>

#include "pageState.h"
#include "AbstractChecker.h"


namespace Ui {
class CheckerModele;
}

class CheckerModele : public QDialog
{
    Q_OBJECT

public:
    explicit CheckerModele(QWidget *parent = 0);
    ~CheckerModele();
public slots:
    void setContentWidget( QWidget* content );

private slots:
    void on_close_clicked();

    void on_help_clicked();

    void on_pushButton_clicked();

private:
    Ui::CheckerModele *ui;
};

#endif // CHECKERMODELE_H

