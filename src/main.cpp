#include "MainWindow.h"
#include <QTranslator>
#include <QApplication>
#include <QLibraryInfo>
#include <QSettings>
#include <QStyleFactory>
#include <QStandardPaths>

#include "Theme.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*********************  INIT **********************/
    QSettings().setPath(QSettings::NativeFormat, QSettings::UserScope, Config::pathToConfigFile() );
    QCoreApplication::setOrganizationName("Polybox3D");
    QCoreApplication::setOrganizationDomain("www.polybox3d.com");
    QCoreApplication::setApplicationName("PolySoftware");
    /***  GIT_VERSION defined in .pro file ***/
    QCoreApplication::setApplicationVersion( GIT_VERSION );
    Config::init();
    /*********************  Translation **********************/
    QTranslator qtTranslator;

    if ( QSettings().value("lang").isNull())
    {
        QSettings().setValue("lang",QLocale::system().name().section("_",1,1));
    }
    qtTranslator.load("polybox_" + QSettings().value("lang").toString() , Config::translationPath());
    app.installTranslator(&qtTranslator);

    if(!QFile::exists(Config::translationPath()+"/polybox_fr.qm"))
        qWarning(Config::translationPath().toStdString().c_str());

    /*********************  THEMES **********************/
    Theme::installTheme();

    /*********************  Starting EXE **********************/
    MainWindow w;
    w.show();    

    return app.exec();
}
