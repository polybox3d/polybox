#ifndef THEME_H
#define THEME_H

#include <QObject>
#include <QString>
#include <QSettings>
#include <QStyleFactory>
#include <QApplication>
#include <QColor>
#include <QPalette>
#include <QStyle>

class Theme : public QObject
{
    Q_OBJECT
public:
    explicit Theme(QObject *parent = 0);
    static void installTheme( QString name ="" );

    static void installFusionDark();
    static void installFusionDarkPurple();
    static void installFusionClean();

signals:

public slots:

};

#endif // THEME_H
