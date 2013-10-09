/********************************************************************************
** Form generated from reading UI file 'GlobalChecker.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALCHECKER_H
#define UI_GLOBALCHECKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "Led.h"

QT_BEGIN_NAMESPACE

class Ui_GlobalChecker
{
public:
    QGroupBox *groupBox;
    QLabel *label_7;
    Led *arduino2Led;
    QLabel *label_9;
    Led *arduino1Led;
    QLabel *label_8;
    Led *webcamPluggedLed;
    Led *arduino3Led;
    QLabel *label_6;
    QLabel *label_4;
    Led *powerLed;
    Led *commandLed;
    QLabel *label_3;
    QLabel *label_12;
    Led *arduino4Led;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    Led *boxOpenLed;
    QLabel *label;
    Led *tempICLed;
    QLabel *label_2;
    Led *ATULed;
    QLabel *label_10;
    QLabel *label_11;
    Led *polyboxReadyLed;

    void setupUi(QWidget *GlobalChecker)
    {
        if (GlobalChecker->objectName().isEmpty())
            GlobalChecker->setObjectName(QStringLiteral("GlobalChecker"));
        GlobalChecker->resize(400, 250);
        groupBox = new QGroupBox(GlobalChecker);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(200, 20, 191, 211));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 30, 141, 16));
        arduino2Led = new Led(groupBox);
        arduino2Led->setObjectName(QStringLiteral("arduino2Led"));
        arduino2Led->setGeometry(QRect(10, 50, 15, 15));
        arduino2Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        arduino2Led->setScaledContents(true);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 70, 171, 16));
        arduino1Led = new Led(groupBox);
        arduino1Led->setObjectName(QStringLiteral("arduino1Led"));
        arduino1Led->setGeometry(QRect(10, 30, 15, 15));
        arduino1Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        arduino1Led->setScaledContents(true);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 50, 171, 16));
        webcamPluggedLed = new Led(groupBox);
        webcamPluggedLed->setObjectName(QStringLiteral("webcamPluggedLed"));
        webcamPluggedLed->setGeometry(QRect(10, 130, 15, 15));
        webcamPluggedLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        webcamPluggedLed->setScaledContents(true);
        arduino3Led = new Led(groupBox);
        arduino3Led->setObjectName(QStringLiteral("arduino3Led"));
        arduino3Led->setGeometry(QRect(10, 70, 15, 15));
        arduino3Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        arduino3Led->setScaledContents(true);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 120, 201, 31));
        label_6->setWordWrap(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 190, 121, 16));
        powerLed = new Led(groupBox);
        powerLed->setObjectName(QStringLiteral("powerLed"));
        powerLed->setGeometry(QRect(10, 190, 15, 15));
        powerLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        powerLed->setScaledContents(true);
        commandLed = new Led(groupBox);
        commandLed->setObjectName(QStringLiteral("commandLed"));
        commandLed->setGeometry(QRect(10, 160, 15, 15));
        commandLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        commandLed->setScaledContents(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 160, 141, 16));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 90, 171, 16));
        arduino4Led = new Led(groupBox);
        arduino4Led->setObjectName(QStringLiteral("arduino4Led"));
        arduino4Led->setGeometry(QRect(10, 90, 15, 15));
        arduino4Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        arduino4Led->setScaledContents(true);
        groupBox_2 = new QGroupBox(GlobalChecker);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 181, 211));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(45, 30, 101, 16));
        boxOpenLed = new Led(groupBox_2);
        boxOpenLed->setObjectName(QStringLiteral("boxOpenLed"));
        boxOpenLed->setGeometry(QRect(15, 30, 15, 15));
        boxOpenLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        boxOpenLed->setScaledContents(true);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(45, 70, 57, 17));
        tempICLed = new Led(groupBox_2);
        tempICLed->setObjectName(QStringLiteral("tempICLed"));
        tempICLed->setGeometry(QRect(15, 110, 15, 15));
        tempICLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempICLed->setScaledContents(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 100, 111, 41));
        ATULed = new Led(groupBox_2);
        ATULed->setObjectName(QStringLiteral("ATULed"));
        ATULed->setGeometry(QRect(15, 70, 15, 15));
        ATULed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        ATULed->setScaledContents(true);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 130, 31, 17));
        label_11 = new QLabel(GlobalChecker);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(220, 0, 161, 16));
        polyboxReadyLed = new Led(GlobalChecker);
        polyboxReadyLed->setObjectName(QStringLiteral("polyboxReadyLed"));
        polyboxReadyLed->setGeometry(QRect(380, 0, 15, 15));
        polyboxReadyLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        polyboxReadyLed->setScaledContents(true);

        retranslateUi(GlobalChecker);

        QMetaObject::connectSlotsByName(GlobalChecker);
    } // setupUi

    void retranslateUi(QWidget *GlobalChecker)
    {
        GlobalChecker->setWindowTitle(QApplication::translate("GlobalChecker", "Form", 0));
        groupBox->setTitle(QApplication::translate("GlobalChecker", "Branchements", 0));
        label_7->setText(QApplication::translate("GlobalChecker", "Arduino m\303\250re connect\303\251e", 0));
        arduino2Led->setText(QString());
        label_9->setText(QApplication::translate("GlobalChecker", "Arduino #3 connect\303\251e", 0));
        arduino1Led->setText(QString());
        label_8->setText(QApplication::translate("GlobalChecker", "Arduino #2 connect\303\251e", 0));
        webcamPluggedLed->setText(QString());
        arduino3Led->setText(QString());
        label_6->setText(QApplication::translate("GlobalChecker", "Webcam de surveillance\n"
" branch\303\251", 0));
        label_4->setText(QApplication::translate("GlobalChecker", "Etat de la puissance", 0));
        powerLed->setText(QString());
        commandLed->setText(QString());
        label_3->setText(QApplication::translate("GlobalChecker", "Etat des commande", 0));
        label_12->setText(QApplication::translate("GlobalChecker", "Arduino #4 connect\303\251e", 0));
        arduino4Led->setText(QString());
        groupBox_2->setTitle(QApplication::translate("GlobalChecker", "Etats", 0));
        label_5->setText(QApplication::translate("GlobalChecker", "Boitier ouvert", 0));
        boxOpenLed->setText(QString());
        label->setText(QApplication::translate("GlobalChecker", "ATU", 0));
        tempICLed->setText(QString());
        label_2->setText(QApplication::translate("GlobalChecker", "Temperature \n"
"carte \303\251lectronique", 0));
        ATULed->setText(QString());
        label_10->setText(QApplication::translate("GlobalChecker", "--\302\260C", 0));
        label_11->setText(QApplication::translate("GlobalChecker", "<b>Polybox pr\303\252te \303\240 l'emploi : </b>", 0));
        polyboxReadyLed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GlobalChecker: public Ui_GlobalChecker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALCHECKER_H
