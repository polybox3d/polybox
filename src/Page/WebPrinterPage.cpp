#include "WebPrinterPage.h"
#include "ui_WebPrinterPage.h"

WebPrinterPage::WebPrinterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebPrinterPage)
{
    ui->setupUi(this);

    _buttonMovePosition = ui->move->geometry();
    _moveWidget = false;
    _clickPosition = QCursor::pos();
    this->goToHomePage();
    //this->installEventFilter( this );
    ui->move->installEventFilter( this );
    ui->move->setMouseTracking( true );
    this->setMouseTracking(true);
    ui->serverState->setHidden( true );
}

void WebPrinterPage::goToHomePage()
{
    QUrl url =  Config::printerWebInterfaceUrl();
    url.setPort( Config::printerWebInterfacePort());
    ui->webRender->load( url );
}

WebPrinterPage::~WebPrinterPage()
{
    delete ui;
}

void WebPrinterPage::updateServerState()
{
    if ( PolyboxModule::getInstance()->printerModule()->printerWebInterfaceIsRunning() )
    {
        ui->serverState->setText("Stop Server");
        ui->serverState->setIcon(QIcon(":/img/img/led_on.png"));
    }
    else
    {
        ui->serverState->setText("Start Server");
        ui->serverState->setIcon( QIcon(":/img/img/led_off_red.png"));
    }
}

bool WebPrinterPage::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
      if ( _moveWidget )
      {
          QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

          this->move( (mouseEvent->globalPos()-(ui->move->pos()+QPoint(ui->move->width()/2,ui->move->height()/2))));
      }
  }
  return false;
}
void WebPrinterPage::on_close_clicked()
{
    this->close();
}

void WebPrinterPage::on_refresh_clicked()
{
    ui->webRender->triggerPageAction(QWebPage::Reload);
}

void WebPrinterPage::on_zoomIn_clicked()
{
    ui->webRender->setZoomFactor( ui->webRender->zoomFactor()*1.15);
}

void WebPrinterPage::on_zoomOut_clicked()
{
    ui->webRender->setZoomFactor( ui->webRender->zoomFactor()*0.85);
}

void WebPrinterPage::on_prev_clicked()
{
    ui->webRender->triggerPageAction(QWebPage::Back);
}

void WebPrinterPage::on_next_clicked()
{
    ui->webRender->triggerPageAction(QWebPage::Forward);
}

void WebPrinterPage::on_move_pressed()
{
    _moveWidget = true;
    _buttonMovePosition = ui->move->geometry();
    ui->move->setGeometry(ui->move->x()-40, ui->move->y()-40,100,100);

}

void WebPrinterPage::on_move_released()
{
    _moveWidget = false;
    ui->move->setGeometry( _buttonMovePosition  );
}

void WebPrinterPage::on_serverState_clicked()
{
    if ( PolyboxModule::getInstance()->printerModule()->printerWebInterfaceIsRunning() )
    {
        PolyboxModule::getInstance()->printerModule()->printerWebInterfaceStop();
    }
    else
    {
        PolyboxModule::getInstance()->printerModule()->printerWebInterfaceStart();
    }
    updateServerState();
}

void WebPrinterPage::on_home_clicked()
{
    goToHomePage();
}
