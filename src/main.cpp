#include "MainWindow.h"
#include <QTranslator>
#include <QApplication>
#include <QLibraryInfo>
#include <QSettings>

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

    /*********************  Starting EXE **********************/
    MainWindow w;
    w.show();

    return app.exec();
}
