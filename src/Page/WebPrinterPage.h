#ifndef WEBPRINTERPAGE_H
#define WEBPRINTERPAGE_H

#include <QWidget>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebView>
#include <QMouseEvent>

#include "Config.h"
#include "PolyboxModule.h"
#include "PrinterModule.h"

#include <iostream>
#include <cstdlib>

namespace Ui {
class WebPrinterPage;
}

class WebPrinterPage : public QWidget
{
    Q_OBJECT

public:
    explicit WebPrinterPage(QWidget *parent = 0);
    ~WebPrinterPage();

    void goToHomePage();

    void updateServerState();

protected :
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_close_clicked();

    void on_refresh_clicked();

    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

    void on_prev_clicked();

    void on_next_clicked();

    void on_move_pressed();

    void on_move_released();

    void on_serverState_clicked();

    void on_home_clicked();

private:
    Ui::WebPrinterPage *ui;
    bool _moveWidget;
    QPoint _clickPosition;
    QRect _buttonMovePosition;
};

#endif // WEBPRINTERPAGE_H
