#include "MainWindow.h"
#include <QTranslator>
#include <QApplication>
#include <QLibraryInfo>
#include <QSettings>
#include <QStyleFactory>

#include "Theme.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*********************  INIT **********************/
    QCoreApplication::setOrganizationName("Polybox3D");
    QCoreApplication::setOrganizationDomain("www.polybox3d.com");
    QCoreApplication::setApplicationName("PolySoftware");

    /*********************  Translation **********************/
    QTranslator qtTranslator;
    if ( QSettings().value("lang").isNull())
    {
        QSettings().setValue("lang",QLocale::system().name().section("_",1,1));
    }
    qtTranslator.load("polybox_" + QSettings().value("lang").toString() , Config::translationPath);
    app.installTranslator(&qtTranslator);

    if(!QFile::exists(Config::translationPath+"/polybox_fr.qm"))
        qWarning(Config::translationPath.toStdString().c_str());

    /*********************  THEMES **********************/
    Theme::installTheme();

    /*********************  Starting EXE **********************/
    MainWindow w;
/*
    QWidget* handler_w = new QWidget(0,Qt::FramelessWindowHint);
    QDockWidget* dock;
    dock = new QDockWidget("PolySoftware", handler_w);
    dock->setWidget( new MainWindow);
    dock->setFloating( false );
    dock->setFixedSize(800,600);
    dock->show();

    handler_w->show();**/
    w.show();

    return app.exec();
}
