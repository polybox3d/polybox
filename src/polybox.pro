#-------------------------------------------------
#
# Project created by QtCreator 2013-09-30T15:52:13
#
#-------------------------------------------------

QT       += core gui xml multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polybox
TEMPLATE = app

TRANSLATIONS = ../i18n/polybox_en.ts ../i18n/polybox_fr.ts

CONFIG(release, debug|release)
{
DEFINES += QT_NO_DEBUG_OUTPUT
DEFINES += BYPASS_CHECK
QMAKE_CXXFLAGS_DEBUG +=  -O3 -Ofast
}

DEFINES += NO_SCAN
#UART Lib
include(../externals/qextserialport/src/qextserialport.pri)


#include(../externals/FabScan100/qtTest/qtTest.pri)

INCLUDEPATH += Checker
INCLUDEPATH += Page
INCLUDEPATH += Module
INCLUDEPATH += Widget

SOURCES += main.cpp\
        MainWindow.cpp \
        Updater.cpp \
    Temperature.cpp \
    SerialPort.cpp \
    Config.cpp \
    Face.cpp \
    PrinterSmallUI.cpp \
    Qjoystick.cpp \
    qjoystickenumerator.cpp \
    JoypadHandler.cpp \
    PrinterJPH.cpp \
    ModulePageJPH.cpp \
    LabViewJPH.cpp \
    OpenPageJPH.cpp \
    Widget/Console.cpp \
    Widget/HomeButton.cpp \
    Widget/DialogCNC.cpp \
    Widget/DialogScanner.cpp \
    Widget/Led.cpp \
    Widget/DialogConfigSoft.cpp \
    Widget/interbutton.cpp \
    Widget/ATUButton.cpp \
    Widget/OnOffButton.cpp \
    Widget/DebugPin.cpp \
    Checker/AbstractChecker.cpp \
    Checker/CNCChecker.cpp \
    Checker/CheckerModele.cpp \
    Checker/SCannerChecker.cpp \
    Checker/PrinterChecker.cpp \
    Checker/GlobalChecker.cpp \
    Page/DynamicTestPage.cpp \
    Page/WarningPage.cpp \
    Page/CNCPage.cpp \
    Page/ConfigCNCPage.cpp \
    Page/PrinterPage.cpp \
    Page/LabViewPage.cpp \
    Page/OpenPage.cpp \
    Page/ModulePage.cpp \
    Page/HelpPage.cpp \
    Module/GlobalModule.cpp \
    Module/LabViewModule.cpp \
    Module/CNCModule.cpp \
    Module/PolyboxModule.cpp \
    Module/PrinterModule.cpp \
    Module/ScannerModule.cpp \
    Module/AbstractModule.cpp \
    polyplexer.cpp \
    Widget/FolderButton.cpp

HEADERS  += MainWindow.h \
        Updater.h \
    Temperature.h \
    SerialPort.h \
    mcode.h \
    Config.h \
    Face.h \
    PrinterSmallUI.h \
    Qjoystick.h \
    qjoystickenumerator.h \
    JoypadHandler.h \
    PrinterJPH.h \
    ModulePageJPH.h \
    LabViewJPH.h \
    OpenPageJPH.h \
    Widget/interbutton.h \
    Widget/ATUButton.h \
    Widget/OnOffButton.h \
    Widget/Console.h \
    Widget/HomeButton.h \
    Widget/DialogCNC.h \
    Widget/DialogScanner.h \
    Widget/Led.h \
    Widget/DialogConfigSoft.h \
    Widget/DebugPin.h \
    Checker/CNCChecker.h \
    Checker/CheckerModele.h \
    Checker/SCannerChecker.h \
    Checker/PrinterChecker.h \
    Checker/AbstractChecker.h \
    Checker/GlobalChecker.h \
    Page/WarningPage.h \
    Page/DynamicTestPage.h \
    Page/ConfigCNCPage.h \
    Page/CNCPage.h \
    Page/PrinterPage.h \
    Page/ModulePage.h \
    Page/HelpPage.h \
    Page/pageState.h \
    Page/LabViewPage.h \
    Page/OpenPage.h \
    Module/CNCModule.h \
    Module/LabViewModule.h \
    Module/PolyboxModule.h \
    Module/PrinterModule.h \
    Module/ScannerModule.h \
    Module/AbstractModule.h \
    Module/GlobalModule.h \
    polyplexer.h \
    Widget/FolderButton.h

FORMS    += MainWindow.ui \
    PrinterSmallUI.ui \
    qjoystickenumerator.ui \
    Widget/interbutton.ui \
    Widget/Console.ui \
    Widget/DialogCNC.ui \
    Widget/DialogScanner.ui \
    Widget/DialogConfigSoft.ui \
    Widget/DebugPin.ui \
    Checker/CNCChecker.ui \
    Checker/CheckerModele.ui \
    Checker/SCannerChecker.ui \
    Checker/PrinterChecker.ui \
    Checker/GlobalChecker.ui \
    Page/CNCPage.ui \
    Page/ConfigCNCPage.ui \
    Page/WarningPage.ui \
    Page/DynamicTestPage.ui \
    Page/OpenPage.ui \
    Page/ModulePage.ui \
    Page/HelpPage.ui \
    Page/LabViewPage.ui \
    Page/PrinterPage.ui

RESOURCES += \
    ressources.qrc
