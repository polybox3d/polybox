#-------------------------------------------------
#
# Project created by QtCreator 2013-09-30T15:52:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polybox
TEMPLATE = app

#UART Lib
include(../externals/qextserialport/src/qextserialport.pri)

SOURCES += main.cpp\
        MainWindow.cpp \
        OpenPage.cpp \
        Updater.cpp \
        ModulePage.cpp \
        HelpPage.cpp \
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
    PrinterChecker.cpp \
    WarningPage.cpp \
    GlobalChecker.cpp \
    DialogConfigSoft.cpp \
    DynamicTestPage.cpp \
    PolyboxModule.cpp \
    PrinterModule.cpp \
    ScannerModule.cpp \
    AbstractChecker.cpp \
    AbstractModule.cpp \
    Temperature.cpp \
    SerialPort.cpp

HEADERS  += MainWindow.h \
        OpenPage.h \
        Updater.h \
        ModulePage.h \
        HelpPage.h \
        pageState.h \
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
    PrinterChecker.h \
    WarningPage.h \
    GlobalChecker.h \
    DialogConfigSoft.h \
    DynamicTestPage.h \
    PolyboxModule.h \
    PrinterModule.h \
    ScannerModule.h \
    AbstractChecker.h \
    AbstractModule.h \
    Temperature.h \
    SerialPort.h \
    mcode.h

FORMS    += MainWindow.ui \
        OpenPage.ui \
        ModulePage.ui \
        HelpPage.ui \
    LabViewPage.ui \
    PrinterPage.ui \
    DialogCNC.ui \
    CNCPage.ui \
    ConfigCNCPage.ui \
    DialogScanner.ui \
    CNCChecker.ui \
    CheckerModele.ui \
    SCannerChecker.ui \
    PrinterChecker.ui \
    WarningPage.ui \
    GlobalChecker.ui \
    DialogConfigSoft.ui \
    DynamicTestPage.ui

RESOURCES += \
    ressources.qrc
