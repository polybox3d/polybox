/********************************************************************************
** Form generated from reading UI file 'SCannerChecker.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANNERCHECKER_H
#define UI_SCANNERCHECKER_H

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

class Ui_SCannerChecker
{
public:
    QGroupBox *groupBox;
    Led *turntableLed_2;
    QLabel *label_3;
    QLabel *label_4;
    Led *webcamPlugLed;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    Led *primesencePlugLed;
    QLabel *label;
    Led *turntableLed;
    QLabel *label_2;
    QLabel *label_6;

    void setupUi(QWidget *SCannerChecker)
    {
        if (SCannerChecker->objectName().isEmpty())
            SCannerChecker->setObjectName(QStringLiteral("SCannerChecker"));
        SCannerChecker->resize(400, 250);
        groupBox = new QGroupBox(SCannerChecker);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 181, 131));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        turntableLed_2 = new Led(groupBox);
        turntableLed_2->setObjectName(QStringLiteral("turntableLed_2"));
        turntableLed_2->setGeometry(QRect(10, 80, 18, 18));
        turntableLed_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        turntableLed_2->setScaledContents(true);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 80, 111, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 50, 141, 21));
        webcamPlugLed = new Led(groupBox);
        webcamPlugLed->setObjectName(QStringLiteral("webcamPlugLed"));
        webcamPlugLed->setGeometry(QRect(10, 50, 18, 18));
        webcamPlugLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        webcamPlugLed->setScaledContents(true);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 0, 21, 21));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/img/laser.png")));
        label_5->setScaledContents(true);
        groupBox_2 = new QGroupBox(SCannerChecker);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(210, 20, 181, 131));
        primesencePlugLed = new Led(groupBox_2);
        primesencePlugLed->setObjectName(QStringLiteral("primesencePlugLed"));
        primesencePlugLed->setGeometry(QRect(10, 50, 18, 18));
        primesencePlugLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        primesencePlugLed->setScaledContents(true);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 131, 21));
        turntableLed = new Led(groupBox_2);
        turntableLed->setObjectName(QStringLiteral("turntableLed"));
        turntableLed->setGeometry(QRect(10, 80, 18, 18));
        turntableLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        turntableLed->setScaledContents(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 111, 21));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, -5, 31, 31));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/img/img/primesense.png")));
        label_6->setScaledContents(true);

        retranslateUi(SCannerChecker);

        QMetaObject::connectSlotsByName(SCannerChecker);
    } // setupUi

    void retranslateUi(QWidget *SCannerChecker)
    {
        SCannerChecker->setWindowTitle(QApplication::translate("SCannerChecker", "Form", 0));
        groupBox->setTitle(QApplication::translate("SCannerChecker", "Laser", 0));
        turntableLed_2->setText(QString());
        label_3->setText(QApplication::translate("SCannerChecker", "Plateau tournant", 0));
        label_4->setText(QApplication::translate("SCannerChecker", "Branchement WebCam", 0));
        webcamPlugLed->setText(QString());
        label_5->setText(QString());
        groupBox_2->setTitle(QApplication::translate("SCannerChecker", "PrimeSense", 0));
        primesencePlugLed->setText(QString());
        label->setText(QApplication::translate("SCannerChecker", "Branchement Capteur", 0));
        turntableLed->setText(QString());
        label_2->setText(QApplication::translate("SCannerChecker", "Plateau tournant", 0));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SCannerChecker: public Ui_SCannerChecker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANNERCHECKER_H
