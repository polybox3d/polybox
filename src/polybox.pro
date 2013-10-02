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
    LabViewModule.cpp \
    PrinterPage.cpp \
    DialogCNC.cpp \
    CNCPage.cpp \
    ConfigCNCPage.cpp \
    DialogScanner.cpp \
    Led.cpp \
    CNCChecker.cpp \
    CheckerModele.cpp \
    CNCModule.cpp \
    SCannerChecker.cpp \
    PrinterChecker.cpp

HEADERS  += MainWindow.h \
        OpenPage.h \
        Updater.h \
        ModulePage.h \
        HelpPage.h \
        pageState.h \
    Warning.h \
    HomeButton.h \
    LabViewPage.h \
    LabViewModule.h \
    PrinterPage.h \
    DialogCNC.h \
    CNCPage.h \
    ConfigCNCPage.h \
    DialogScanner.h \
    Led.h \
    CNCChecker.h \
    CheckerModele.h \
    CNCModule.h \
    SCannerChecker.h \
    PrinterChecker.h

FORMS    += MainWindow.ui \
        OpenPage.ui \
        ModulePage.ui \
        HelpPage.ui \
    Warning.ui \
    LabViewPage.ui \
    PrinterPage.ui \
    DialogCNC.ui \
    CNCPage.ui \
    ConfigCNCPage.ui \
    DialogScanner.ui \
    CNCChecker.ui \
    CheckerModele.ui \
    SCannerChecker.ui \
    PrinterChecker.ui

RESOURCES += \
    ressources.qrc
