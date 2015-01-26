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
        else if ( QSettings().value("theme").toString().compare("Polybox3D") == 0 )
        {
            Theme::installPolybox();
        }
        else if ( QSettings().value("theme").toString().compare("White") == 0 )
        {
            qApp->setPalette( qApp->style()->standardPalette());
            //Theme::installWhite();
        }
    }
    installCommonStyleSheet();

}

void Theme::installCommonStyleSheet()
{
    QString str_style;
    QDir dir_qss(":/style/style/");
    QFileInfoList list = dir_qss.entryInfoList( QStringList("*.qss"), QDir::Files );
    foreach (QFileInfo qss, list)
    {
        QFile File(qss.absoluteFilePath());
        File.open(QFile::ReadOnly);
        str_style += QLatin1String(File.readAll());
    }

    qApp->setStyleSheet( str_style );

}

void Theme::installFusionDark()
{
    qApp->setStyle(QStyleFactory::create("fusion_dark_blu"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(35,35,35));
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

    // this is for DISABLE widget color
    darkPalette.setColor(QPalette::Disabled, QPalette::Button, QColor(25, 25, 25));
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }"
                        );
    /**
                        "QMenu {"
                        "border: 1px solid #191919;"
                        "}"
    **/
    qApp->setPalette(darkPalette);


}

void Theme::installPolybox()
{
    qApp->setStyle(QStyleFactory::create("fusion_dark_blu"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(34,34,34));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(34,34,34));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(34,34,34));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    // this is for DISABLE widget color
    darkPalette.setColor(QPalette::Disabled, QPalette::Button, QColor(15, 15, 15));
    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }"
                        );
    /**
                        "QMenu {"
                        "border: 1px solid #191919;"
                        "}"
    **/
    qApp->setPalette(darkPalette);


}

void Theme::installFusionDarkPurple()
{
    qApp->setStyle(QStyleFactory::create("fusion_dark_purple"));

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(35,35,35));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);

    // this is for DISABLE widget color
    palette.setColor(QPalette::Disabled, QPalette::Button, QColor(25, 15, 25));
    qApp->setPalette(palette);
}

void Theme::installFusionClean()
{
    qApp->setStyle(QStyleFactory::create("fusion_clean"));

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(212,219,230.));

    palette.setColor(QPalette::Highlight, QColor(132,189,223));

    qApp->setPalette(palette);
}
