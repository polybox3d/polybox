/********************************************************************************
** Form generated from reading UI file 'ModulePage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULEPAGE_H
#define UI_MODULEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModulePage
{
public:
    QLabel *homeButton;
    QPushButton *printerButton;
    QPushButton *cncButton;
    QPushButton *scannerButton;
    QPushButton *labviewButton;

    void setupUi(QWidget *ModulePage)
    {
        if (ModulePage->objectName().isEmpty())
            ModulePage->setObjectName(QStringLiteral("ModulePage"));
        ModulePage->resize(800, 550);
        homeButton = new QLabel(ModulePage);
        homeButton->setObjectName(QStringLiteral("homeButton"));
        homeButton->setGeometry(QRect(250, 130, 300, 290));
        homeButton->setAutoFillBackground(false);
        homeButton->setPixmap(QPixmap(QString::fromUtf8("logo_400.png")));
        homeButton->setScaledContents(true);
        printerButton = new QPushButton(ModulePage);
        printerButton->setObjectName(QStringLiteral("printerButton"));
        printerButton->setGeometry(QRect(620, 70, 121, 91));
        printerButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 190, 190);"));
        printerButton->setCheckable(false);
        cncButton = new QPushButton(ModulePage);
        cncButton->setObjectName(QStringLiteral("cncButton"));
        cncButton->setGeometry(QRect(50, 70, 121, 91));
        cncButton->setStyleSheet(QStringLiteral("background-color: rgb(180, 210, 255);"));
        scannerButton = new QPushButton(ModulePage);
        scannerButton->setObjectName(QStringLiteral("scannerButton"));
        scannerButton->setGeometry(QRect(60, 380, 121, 91));
        scannerButton->setStyleSheet(QStringLiteral("background-color: rgb(180, 255, 165);"));
        labviewButton = new QPushButton(ModulePage);
        labviewButton->setObjectName(QStringLiteral("labviewButton"));
        labviewButton->setGeometry(QRect(620, 380, 121, 91));
        labviewButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 230, 155);"));

        retranslateUi(ModulePage);

        QMetaObject::connectSlotsByName(ModulePage);
    } // setupUi

    void retranslateUi(QWidget *ModulePage)
    {
        ModulePage->setWindowTitle(QApplication::translate("ModulePage", "Form", 0));
        homeButton->setText(QString());
        printerButton->setText(QApplication::translate("ModulePage", "Imprimante", 0));
        cncButton->setText(QApplication::translate("ModulePage", "CNC", 0));
        scannerButton->setText(QApplication::translate("ModulePage", "Scanner", 0));
        labviewButton->setText(QApplication::translate("ModulePage", "LabView", 0));
    } // retranslateUi

};

namespace Ui {
    class ModulePage: public Ui_ModulePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULEPAGE_H
