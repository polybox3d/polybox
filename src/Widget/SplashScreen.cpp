#include "SplashScreen.h"

SplashScreen::SplashScreen(const QPixmap& pixmap)
{
    QSplashScreen::setPixmap(pixmap);
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::drawContents(QPainter *painter)
{
    QPixmap textPix = QSplashScreen::pixmap();
    painter->setPen(this->_color);
    painter->drawText(this->_rect, this->_alignement, this->_message);
}

void SplashScreen::connectingProcess()
{
    bool connected = PolyboxModule::getInstance( qApp )->connectToPrinter();
    // If connected, we gonna check ping/pong process and swap
    if ( connected )
    {
        qApp->processEvents();
        QThread::sleep( 5 ); // wait for ping/pong, check if board connected
        qApp->processEvents();
        if ( PolyboxModule::getInstance()->isConnected() )
        {
            QPixmap pixmap2(":/img/img/logo_400_yellow.png");
            this->setPixmap( pixmap2.scaledToHeight(288) );
        }
        else
        {
            QPixmap pixmap2(":/img/img/logo_400_blu.png");
            this->setPixmap( pixmap2.scaledToHeight(288) );
        }
    }
    else
    {
        QPixmap pixmap2(":/img/img/logo_per_150.png");
        this->setPixmap( pixmap2.scaledToHeight(288) );
    }
    qApp->processEvents();
    QThread::sleep( 4 );
}

void SplashScreen::showStatusMessage(const QString &message, const QColor &color)
{
    this->_message = message;
    this->_color = color;
    this->showMessage(this->_message, this->_alignement, this->_color);
}

void SplashScreen::setMessageRect(QRect rect, int alignement)
{
    this->_rect = rect;
    this->_alignement = alignement;
}
