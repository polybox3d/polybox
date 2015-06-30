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

    this->setMessageRect(QRect(this->width()/2-300,this->height()/2+50,450,200));
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
    this->showStatusMessage(tr("Start connection process..."), Qt::white);
    Polyplexer::ConnectionStatus connection_status = Polyplexer::getInstance()->start( Polyplexer::Serial );
    if ( connection_status == Polyplexer::Connected )
    {
        this->showStatusMessage(tr("     Polyplexer started. \nInitialize Connection..."), Qt::white);
        this->setPixmap(QPixmap(":/img/img/splashscreen_wait_fitted.png"));
        qApp->processEvents();
        ClosedLoopTimer loop;
        loop.startClosedLoop( 1000 );
        ComModule::getInstance()->beginConnection();
        connection_status = ComModule::getInstance()->checkPingPongConnection();
        if (  connection_status == Polyplexer::Connected )
        {
            this->setPixmap(QPixmap(":/img/img/splashscreen_connected_fitted.png"));
            this->showStatusMessage(tr("Connected !"), Qt::white);
            qApp->processEvents();
        }
        else
        {
            this->setPixmap(QPixmap(":/img/img/splashscreen_unconnected_error_fitted.png"));
            this->showStatusMessage(tr(QString("Failed to establish connection.\n"+ComModule::connectionStatusMessage.value(connection_status)).toStdString().c_str()), Qt::white);
            qApp->processEvents();
        }
    }
    else
    {
        this->setPixmap(QPixmap(":/img/img/splashscreen_unconnected_fitted.png"));
        this->showStatusMessage( ComModule::connectionStatusMessage.value(connection_status), Qt::white);
        qApp->processEvents();
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
