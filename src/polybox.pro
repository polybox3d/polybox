#-------------------------------------------------
#
# Project created by QtCreator 2013-09-30T15:52:13
#
#-------------------------------------------------

QT       += core gui xml multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polybox
TEMPLATE = app

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
    SerialPort.cpp \
    Config.cpp \
    GlobalModule.cpp \
    Face.cpp \
    PrinterSmallUI.cpp \
    Qjoystick.cpp \
    qjoystickenumerator.cpp \
    JoypadHandler.cpp \
    PrinterJPH.cpp \
    ModulePageJPH.cpp \
    LabViewJPH.cpp \
    OpenPageJPH.cpp \
    interbutton.cpp \
    ATUButton.cpp \
    OnOffButton.cpp \
    Console.cpp \
    polyplexer.cpp \
    DebugPin.cpp

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
    mcode.h \
    Config.h \
    GlobalModule.h \
    Face.h \
    PrinterSmallUI.h \
    Qjoystick.h \
    qjoystickenumerator.h \
    JoypadHandler.h \
    PrinterJPH.h \
    ModulePageJPH.h \
    LabViewJPH.h \
    OpenPageJPH.h \
    interbutton.h \
    ATUButton.h \
    OnOffButton.h \
    Console.h \
    polyplexer.h \
    DebugPin.h

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
    DynamicTestPage.ui \
    PrinterSmallUI.ui \
    qjoystickenumerator.ui \
    interbutton.ui \
    Console.ui \
    DebugPin.ui

RESOURCES += \
    ressources.qrc
