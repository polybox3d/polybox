#include "Theme.h"

Theme::Theme(QObject *parent) :
    QObject(parent)
{
}

void Theme::installTheme(QString name)
{
    if ( !name.isEmpty())
    {
        QSettings().setValue("theme", name);
    }

    else
    {
        if ( QSettings().value("theme").isNull())
        {
            QSettings().setValue("theme","Fusion Dark");
        }

        if ( QSettings().value("theme").toString().compare("Fusion White") == 0 )
        {

        }
        else if ( QSettings().value("theme").toString().compare("Fusion Dark") == 0 )
        {
            Theme::installFusionDark();
        }
        else if ( QSettings().value("theme").toString().compare("Fusion Purple") == 0 )
        {
            Theme::installFusionDarkPurple();
        }
        else if ( QSettings().value("theme").toString().compare("Fusion Clean") == 0 )
        {
            Theme::installFusionClean();
        }
        else if ( QSettings().value("theme").toString().compare("White") == 0 )
        {
            qApp->setPalette( qApp->style()->standardPalette());
            //Theme::installWhite();
        }
    }

}

void Theme::installFusionDark()
{
    qApp->setStyle(QStyleFactory::create("fusion_dark_blu"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

}

void Theme::installFusionDarkPurple()
{
    qApp->setStyle(QStyleFactory::create("fusion_dark_purple"));

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(15,15,15));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(palette);
}

void Theme::installFusionClean()
{
    qApp->setStyle(QStyleFactory::create("fusio_clean"));

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(15,15,15));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(palette);
}
