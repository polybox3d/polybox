/********************************************************************************
** Form generated from reading UI file 'CNCChecker.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNCCHECKER_H
#define UI_CNCCHECKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include "Led.h"

QT_BEGIN_NAMESPACE

class Ui_CNCChecker
{
public:
    QLabel *label_8;
    Led *cncReadyLed;
    QGroupBox *groupBox;
    Led *levelLubLed;
    QLabel *label_2;
    Led *motorLubLed;
    Led *vacuumLed;
    QLabel *label_4;
    Led *cncPlugLed;
    QLabel *label;
    QLabel *label_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *proxonRadio;
    QRadioButton *manuelRadio;

    void setupUi(QWidget *CNCChecker)
    {
        if (CNCChecker->objectName().isEmpty())
            CNCChecker->setObjectName(QStringLiteral("CNCChecker"));
        CNCChecker->resize(400, 250);
        label_8 = new QLabel(CNCChecker);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 0, 171, 21));
        cncReadyLed = new Led(CNCChecker);
        cncReadyLed->setObjectName(QStringLiteral("cncReadyLed"));
        cncReadyLed->setGeometry(QRect(380, 0, 15, 15));
        cncReadyLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        cncReadyLed->setScaledContents(true);
        groupBox = new QGroupBox(CNCChecker);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 341, 161));
        levelLubLed = new Led(groupBox);
        levelLubLed->setObjectName(QStringLiteral("levelLubLed"));
        levelLubLed->setGeometry(QRect(10, 103, 15, 15));
        levelLubLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        levelLubLed->setScaledContents(true);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 76, 106, 17));
        motorLubLed = new Led(groupBox);
        motorLubLed->setObjectName(QStringLiteral("motorLubLed"));
        motorLubLed->setGeometry(QRect(10, 76, 15, 15));
        motorLubLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        motorLubLed->setScaledContents(true);
        vacuumLed = new Led(groupBox);
        vacuumLed->setObjectName(QStringLiteral("vacuumLed"));
        vacuumLed->setGeometry(QRect(10, 130, 15, 15));
        vacuumLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        vacuumLed->setScaledContents(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 103, 118, 17));
        cncPlugLed = new Led(groupBox);
        cncPlugLed->setObjectName(QStringLiteral("cncPlugLed"));
        cncPlugLed->setGeometry(QRect(10, 29, 15, 15));
        cncPlugLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        cncPlugLed->setScaledContents(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 29, 109, 17));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 130, 119, 17));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 50, 206, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        proxonRadio = new QRadioButton(layoutWidget);
        proxonRadio->setObjectName(QStringLiteral("proxonRadio"));
        proxonRadio->setEnabled(false);
        proxonRadio->setCheckable(true);

        horizontalLayout->addWidget(proxonRadio);

        manuelRadio = new QRadioButton(layoutWidget);
        manuelRadio->setObjectName(QStringLiteral("manuelRadio"));
        manuelRadio->setEnabled(false);
        manuelRadio->setCheckable(true);

        horizontalLayout->addWidget(manuelRadio);


        retranslateUi(CNCChecker);

        QMetaObject::connectSlotsByName(CNCChecker);
    } // setupUi

    void retranslateUi(QWidget *CNCChecker)
    {
        CNCChecker->setWindowTitle(QApplication::translate("CNCChecker", "Form", 0));
        label_8->setText(QApplication::translate("CNCChecker", "<html><head/><body><p><span style=\" font-weight:600;\">Module CN pr\303\252t \303\240 l'emploi :</span></p></body></html>", 0));
        cncReadyLed->setText(QString());
        groupBox->setTitle(QApplication::translate("CNCChecker", "D\303\251tails", 0));
        levelLubLed->setText(QString());
        label_2->setText(QApplication::translate("CNCChecker", "Moteur lubrificant", 0));
        motorLubLed->setText(QString());
        vacuumLed->setText(QString());
        label_4->setText(QApplication::translate("CNCChecker", "Niveau de lubrifiant", 0));
        cncPlugLed->setText(QString());
        label->setText(QApplication::translate("CNCChecker", "Outils CN branch\303\251", 0));
        label_5->setText(QApplication::translate("CNCChecker", "Module d'aspiration", 0));
        proxonRadio->setText(QApplication::translate("CNCChecker", "Proxon", 0));
        manuelRadio->setText(QApplication::translate("CNCChecker", "Manuel", 0));
    } // retranslateUi

};

namespace Ui {
    class CNCChecker: public Ui_CNCChecker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNCCHECKER_H
