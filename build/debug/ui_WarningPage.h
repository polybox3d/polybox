/********************************************************************************
** Form generated from reading UI file 'WarningPage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGPAGE_H
#define UI_WARNINGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "CNCChecker.h"
#include "GlobalChecker.h"
#include "PrinterChecker.h"
#include "SCannerChecker.h"

QT_BEGIN_NAMESPACE

class Ui_WarningPage
{
public:
    GlobalChecker *generalWidget;
    SCannerChecker *scannerWidget;
    PrinterChecker *printerWidget;
    CNCChecker *cncWidget;
    QFrame *line;
    QPushButton *help;
    QPushButton *configuration;
    QPushButton *dynamicTest;

    void setupUi(QWidget *WarningPage)
    {
        if (WarningPage->objectName().isEmpty())
            WarningPage->setObjectName(QStringLiteral("WarningPage"));
        WarningPage->resize(800, 550);
        generalWidget = new GlobalChecker(WarningPage);
        generalWidget->setObjectName(QStringLiteral("generalWidget"));
        generalWidget->setGeometry(QRect(0, 0, 400, 250));
        scannerWidget = new SCannerChecker(WarningPage);
        scannerWidget->setObjectName(QStringLiteral("scannerWidget"));
        scannerWidget->setGeometry(QRect(0, 260, 400, 250));
        printerWidget = new PrinterChecker(WarningPage);
        printerWidget->setObjectName(QStringLiteral("printerWidget"));
        printerWidget->setGeometry(QRect(400, 0, 400, 250));
        scannerWidget->raise();
        cncWidget = new CNCChecker(WarningPage);
        cncWidget->setObjectName(QStringLiteral("cncWidget"));
        cncWidget->setGeometry(QRect(400, 260, 400, 250));
        line = new QFrame(WarningPage);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(50, 250, 701, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        help = new QPushButton(WarningPage);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(640, 520, 81, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon);
        configuration = new QPushButton(WarningPage);
        configuration->setObjectName(QStringLiteral("configuration"));
        configuration->setGeometry(QRect(450, 520, 181, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/conf.png"), QSize(), QIcon::Normal, QIcon::Off);
        configuration->setIcon(icon1);
        dynamicTest = new QPushButton(WarningPage);
        dynamicTest->setObjectName(QStringLiteral("dynamicTest"));
        dynamicTest->setGeometry(QRect(300, 520, 141, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        dynamicTest->setIcon(icon2);

        retranslateUi(WarningPage);

        QMetaObject::connectSlotsByName(WarningPage);
    } // setupUi

    void retranslateUi(QWidget *WarningPage)
    {
        WarningPage->setWindowTitle(QApplication::translate("WarningPage", "Form", 0));
        help->setText(QApplication::translate("WarningPage", "Aide", 0));
        configuration->setText(QApplication::translate("WarningPage", "Configuration logicielle", 0));
        dynamicTest->setText(QApplication::translate("WarningPage", "Tests Dynamiques", 0));
    } // retranslateUi

};

namespace Ui {
    class WarningPage: public Ui_WarningPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGPAGE_H
