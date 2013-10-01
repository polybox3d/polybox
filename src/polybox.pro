#-------------------------------------------------
#
# Project created by QtCreator 2013-09-30T15:52:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polybox
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
        OpenPage.cpp \
        Updater.cpp \
        ModulePage.cpp \
        HelpPage.cpp \
    Warning.cpp \
    HomeButton.cpp \
    LabViewPage.cpp \
    LabViewModule.cpp

HEADERS  += MainWindow.h \
        OpenPage.h \
        Updater.h \
        ModulePage.h \
        HelpPage.h \
        pageState.h \
    Warning.h \
    HomeButton.h \
    LabViewPage.h \
    LabViewModule.h

FORMS    += MainWindow.ui \
        OpenPage.ui \
        ModulePage.ui \
        HelpPage.ui \
    Warning.ui \
    LabViewPage.ui

RESOURCES += \
    ressources.qrc
