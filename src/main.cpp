#include "MainWindow.h"
#include <QTranslator>
#include <QApplication>
#include <QLibraryInfo>
#include <QSettings>
#include <QStyleFactory>
#include <QStandardPaths>
#include <QSplashScreen>
#include <QThread>
#include <QTranslator>

#include "Theme.h"
#include "ClosedLoopTimer.h"
#include "SplashScreen.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /*QString fontName(QLatin1String("../../src/style/fonts/Xperia.ttf"));
    int appFontId = QFontDatabase::addApplicationFont(fontName);
    if (appFontId < 0)
    {
        qWarning() << "Attempt to load application font: "<< fontName << " failed.";
    }*/
    /*********************  SPLASHSCREEN **********************/
    SplashScreen splash( QPixmap(":/img/img/splashscreen_unconnected_fitted.png") );
    splash.show();
    splash.showStatusMessage(QObject::tr("                   Initialization..."),Qt::white);
    qApp->processEvents();

    /*********************  INIT **********************/
    QSettings().setPath(QSettings::NativeFormat, QSettings::UserScope, Config::pathToConfigFile() );
    QCoreApplication::setOrganizationName("Polybox3D");
    QCoreApplication::setOrganizationDomain("www.polybox3d.com");
    QCoreApplication::setApplicationName("PolySoftware");
    /***  GIT_VERSION defined in .pro file ***/
    QCoreApplication::setApplicationVersion( GIT_VERSION );
    Config::init();
    app.processEvents();

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

    app.processEvents();

    /*********************  THEMES **********************/
    splash.showStatusMessage("                   Loading Skins...",Qt::white);
    Theme::installTheme();
    app.processEvents();

    /*********************  Starting EXE **********************/
    qApp->processEvents();
    splash.connectingProcess();

    ClosedLoopTimer closed_loop;
    closed_loop.startClosedLoop( 4000 );


    MainWindow w;


    w.show();
    splash.finish( &w );

    return app.exec();
}
