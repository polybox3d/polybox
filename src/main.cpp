#include "MainWindow.h"
#include <QTranslator>
#include <QApplication>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    QTranslator qtTranslator;
    qtTranslator.load("polybox_" + QLocale::system().name().section("_",1,1),
            QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    MainWindow w;
    w.show();

    return app.exec();
}
