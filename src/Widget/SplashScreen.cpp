#include "SplashScreen.h"

SplashScreen::SplashScreen(const QPixmap& pixmap)
{
    init(pixmap);
}
SplashScreen::SplashScreen()
{

}
void SplashScreen::init(const QPixmap &pixmap)
{

    QSplashScreen::setPixmap(pixmap);
    _font = qApp->font();
    //_font = QFont("Xperia");
    _font.setPointSize( 12 );
    _font.setItalic( true );

    _fontVersion = qApp->font();
    _fontVersion.setPointSize( 8 );
    _fontVersion.setItalic( true );

    this->setMessageRect(QRect(this->width()/2-200,this->height()/2+50,275,200));
}

SplashScreen::~SplashScreen()
{

}
void SplashScreen::setFont(const QFont &f)
{
    this->_font = f;
}

void SplashScreen::drawContents(QPainter *painter)
{
    QPixmap textPix = QSplashScreen::pixmap();
    painter->setPen( this->_color );
    painter->setFont( this->_font );
    painter->drawText( this->_rect, this->_alignement, this->_message );

    painter->setFont( this->_fontVersion);
    painter->setPen( Qt::gray );
    painter->drawText( QRect(this->width()/2-40,this->height()/2+10,200,100), this->_alignement, QApplication::applicationVersion() );
}

void SplashScreen::connectingProcess()
{
    this->showStatusMessage(tr("Attempt to connect..."), Qt::white);
    PolyboxModule::ConnectionStatus connection_status = PolyboxModule::getInstance( qApp )->connection( Config::blockedConnectionThread() );
    // If connected, we gonna check ping/pong process and swap
    if ( connection_status == PolyboxModule::Connected )
    {
        this->showStatusMessage(tr("     Polyplexer started. \nWaiting for Polybox3D response..."), Qt::white);
        this->setPixmap(QPixmap(":/img/img/splashscreen_wait_fitted.png"));
        qApp->processEvents();

        /** We need to wait the end of ping/pong process. It's an closed loop, we process QtEvent and check if the connection is active **/
        ClosedLoopTimer closed_loop;

        if ( closed_loop.startClosedLoop( 15000, PolyboxModule::isConnected ) )
        {
            this->setPixmap(QPixmap(":/img/img/splashscreen_connected_fitted.png"));
            this->showStatusMessage(tr("Connected !"), Qt::white);
        }
        else
        {
            this->setPixmap(QPixmap(":/img/img/splashscreen_unconnected_error_fitted.png"));
            this->showStatusMessage(tr("Failed to establish connection"), Qt::white);
        }
    }
    else
    {
        this->setPixmap(QPixmap(":/img/img/splashscreen_unconnected_fitted.png"));
        this->showStatusMessage(tr("Error when starting Polyplexer"), Qt::white);
    }
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
