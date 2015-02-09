#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPainter>
#include <QThread>
#include <QApplication>


#include "PolyboxModule.h"
#include "ClosedLoopTimer.h"

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(const QPixmap& pixmap);
    ~SplashScreen();
    virtual void drawContents(QPainter *painter);
    void setFont(const QFont &f);
    void showStatusMessage(const QString &message, const QColor &color = Qt::black);
    void setMessageRect(QRect rect, int alignment = Qt::AlignLeft);
    void connectingProcess();


signals:

public slots:

private:
 QString _message;
 int _alignement;
 QColor _color;
 QFont _font;
 QFont _fontVersion;
 QRect _rect;

};

#endif // SPLASHSCREEN_H
