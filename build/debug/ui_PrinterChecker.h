/********************************************************************************
** Form generated from reading UI file 'PrinterChecker.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTERCHECKER_H
#define UI_PRINTERCHECKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Led.h"

QT_BEGIN_NAMESPACE

class Ui_PrinterChecker
{
public:
    QGroupBox *groupBox;
    QGroupBox *buse1Bloc;
    Led *tempTopBuse1Led;
    Led *tempBotBuse1Led;
    QGroupBox *buse2Bloc;
    Led *tempBotBuse2Led;
    Led *tempTopBuse2Led;
    QGroupBox *boxBloc;
    Led *tempBoxTopLed;
    Led *tempBoxBotLed;
    Led *tempBoxMiddleLed;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *bedBloc;
    Led *tempBedMidLed;
    Led *tempBedExtLed;
    QLabel *label_9;
    QLabel *label_10;
    QGroupBox *coldBloc;
    Led *coldBuse1Led;
    QGroupBox *coldBoxBloc;
    Led *coldBox1Led;
    Led *coldBox2Led;
    Led *coldBox3Led;
    Led *coldBox4Led;
    Led *coldBuse2Led;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QGroupBox *groupBox_8;
    QLabel *label;
    Led *printerPlugLed;
    Led *detectPlasticLed;
    QLabel *label_2;
    Led *bedPlugLed;
    QLabel *label_8;
    QLabel *label_11;
    Led *printerReadyLed;

    void setupUi(QWidget *PrinterChecker)
    {
        if (PrinterChecker->objectName().isEmpty())
            PrinterChecker->setObjectName(QStringLiteral("PrinterChecker"));
        PrinterChecker->resize(400, 230);
        groupBox = new QGroupBox(PrinterChecker);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 171, 201));
        buse1Bloc = new QGroupBox(groupBox);
        buse1Bloc->setObjectName(QStringLiteral("buse1Bloc"));
        buse1Bloc->setGeometry(QRect(10, 20, 71, 51));
        tempTopBuse1Led = new Led(buse1Bloc);
        tempTopBuse1Led->setObjectName(QStringLiteral("tempTopBuse1Led"));
        tempTopBuse1Led->setGeometry(QRect(10, 30, 15, 15));
        tempTopBuse1Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempTopBuse1Led->setScaledContents(true);
        tempBotBuse1Led = new Led(buse1Bloc);
        tempBotBuse1Led->setObjectName(QStringLiteral("tempBotBuse1Led"));
        tempBotBuse1Led->setGeometry(QRect(40, 30, 15, 15));
        tempBotBuse1Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempBotBuse1Led->setScaledContents(true);
        buse2Bloc = new QGroupBox(groupBox);
        buse2Bloc->setObjectName(QStringLiteral("buse2Bloc"));
        buse2Bloc->setGeometry(QRect(90, 20, 71, 51));
        tempBotBuse2Led = new Led(buse2Bloc);
        tempBotBuse2Led->setObjectName(QStringLiteral("tempBotBuse2Led"));
        tempBotBuse2Led->setGeometry(QRect(40, 30, 15, 15));
        tempBotBuse2Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempBotBuse2Led->setScaledContents(true);
        tempTopBuse2Led = new Led(buse2Bloc);
        tempTopBuse2Led->setObjectName(QStringLiteral("tempTopBuse2Led"));
        tempTopBuse2Led->setGeometry(QRect(10, 30, 15, 15));
        tempTopBuse2Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempTopBuse2Led->setScaledContents(true);
        boxBloc = new QGroupBox(groupBox);
        boxBloc->setObjectName(QStringLiteral("boxBloc"));
        boxBloc->setGeometry(QRect(10, 70, 151, 71));
        tempBoxTopLed = new Led(boxBloc);
        tempBoxTopLed->setObjectName(QStringLiteral("tempBoxTopLed"));
        tempBoxTopLed->setGeometry(QRect(20, 50, 15, 15));
        tempBoxTopLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempBoxTopLed->setScaledContents(true);
        tempBoxBotLed = new Led(boxBloc);
        tempBoxBotLed->setObjectName(QStringLiteral("tempBoxBotLed"));
        tempBoxBotLed->setGeometry(QRect(120, 50, 15, 15));
        tempBoxBotLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempBoxBotLed->setScaledContents(true);
        tempBoxMiddleLed = new Led(boxBloc);
        tempBoxMiddleLed->setObjectName(QStringLiteral("tempBoxMiddleLed"));
        tempBoxMiddleLed->setGeometry(QRect(70, 50, 15, 15));
        tempBoxMiddleLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempBoxMiddleLed->setScaledContents(true);
        widget = new QWidget(boxBloc);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 133, 20));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        bedBloc = new QGroupBox(groupBox);
        bedBloc->setObjectName(QStringLiteral("bedBloc"));
        bedBloc->setGeometry(QRect(10, 140, 151, 51));
        tempBedMidLed = new Led(bedBloc);
        tempBedMidLed->setObjectName(QStringLiteral("tempBedMidLed"));
        tempBedMidLed->setGeometry(QRect(50, 30, 15, 15));
        tempBedMidLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempBedMidLed->setScaledContents(true);
        tempBedExtLed = new Led(bedBloc);
        tempBedExtLed->setObjectName(QStringLiteral("tempBedExtLed"));
        tempBedExtLed->setGeometry(QRect(130, 30, 15, 15));
        tempBedExtLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        tempBedExtLed->setScaledContents(true);
        label_9 = new QLabel(bedBloc);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 28, 45, 17));
        label_10 = new QLabel(bedBloc);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(70, 28, 61, 17));
        coldBloc = new QGroupBox(PrinterChecker);
        coldBloc->setObjectName(QStringLiteral("coldBloc"));
        coldBloc->setGeometry(QRect(190, 110, 201, 111));
        coldBuse1Led = new Led(coldBloc);
        coldBuse1Led->setObjectName(QStringLiteral("coldBuse1Led"));
        coldBuse1Led->setGeometry(QRect(150, 42, 15, 15));
        coldBuse1Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        coldBuse1Led->setScaledContents(true);
        coldBoxBloc = new QGroupBox(coldBloc);
        coldBoxBloc->setObjectName(QStringLiteral("coldBoxBloc"));
        coldBoxBloc->setGeometry(QRect(10, 20, 71, 80));
        coldBox1Led = new Led(coldBoxBloc);
        coldBox1Led->setObjectName(QStringLiteral("coldBox1Led"));
        coldBox1Led->setGeometry(QRect(10, 30, 15, 15));
        coldBox1Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        coldBox1Led->setScaledContents(true);
        coldBox2Led = new Led(coldBoxBloc);
        coldBox2Led->setObjectName(QStringLiteral("coldBox2Led"));
        coldBox2Led->setGeometry(QRect(40, 30, 15, 15));
        coldBox2Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        coldBox2Led->setScaledContents(true);
        coldBox3Led = new Led(coldBoxBloc);
        coldBox3Led->setObjectName(QStringLiteral("coldBox3Led"));
        coldBox3Led->setGeometry(QRect(10, 60, 15, 15));
        coldBox3Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        coldBox3Led->setScaledContents(true);
        coldBox4Led = new Led(coldBoxBloc);
        coldBox4Led->setObjectName(QStringLiteral("coldBox4Led"));
        coldBox4Led->setGeometry(QRect(40, 60, 15, 15));
        coldBox4Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        coldBox4Led->setScaledContents(true);
        coldBuse2Led = new Led(coldBloc);
        coldBuse2Led->setObjectName(QStringLiteral("coldBuse2Led"));
        coldBuse2Led->setGeometry(QRect(150, 67, 15, 15));
        coldBuse2Led->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        coldBuse2Led->setScaledContents(true);
        widget1 = new QWidget(coldBloc);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(90, 40, 47, 42));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        groupBox_8 = new QGroupBox(PrinterChecker);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(190, 20, 201, 91));
        label = new QLabel(groupBox_8);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 81, 17));
        printerPlugLed = new Led(groupBox_8);
        printerPlugLed->setObjectName(QStringLiteral("printerPlugLed"));
        printerPlugLed->setGeometry(QRect(10, 30, 15, 15));
        printerPlugLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        printerPlugLed->setScaledContents(true);
        detectPlasticLed = new Led(groupBox_8);
        detectPlasticLed->setObjectName(QStringLiteral("detectPlasticLed"));
        detectPlasticLed->setGeometry(QRect(10, 50, 15, 15));
        detectPlasticLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        detectPlasticLed->setScaledContents(true);
        label_2 = new QLabel(groupBox_8);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 30, 151, 17));
        bedPlugLed = new Led(groupBox_8);
        bedPlugLed->setObjectName(QStringLiteral("bedPlugLed"));
        bedPlugLed->setGeometry(QRect(10, 70, 15, 15));
        bedPlugLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        bedPlugLed->setScaledContents(true);
        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 70, 151, 17));
        label_11 = new QLabel(PrinterChecker);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(270, 5, 101, 16));
        printerReadyLed = new Led(PrinterChecker);
        printerReadyLed->setObjectName(QStringLiteral("printerReadyLed"));
        printerReadyLed->setGeometry(QRect(370, 7, 15, 15));
        printerReadyLed->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));
        printerReadyLed->setScaledContents(true);

        retranslateUi(PrinterChecker);

        QMetaObject::connectSlotsByName(PrinterChecker);
    } // setupUi

    void retranslateUi(QWidget *PrinterChecker)
    {
        PrinterChecker->setWindowTitle(QApplication::translate("PrinterChecker", "Form", 0));
        groupBox->setTitle(QApplication::translate("PrinterChecker", "Capteurs de Temp\303\251rature", 0));
        buse1Bloc->setTitle(QApplication::translate("PrinterChecker", "Buse #1", 0));
        tempTopBuse1Led->setText(QString());
        tempBotBuse1Led->setText(QString());
        buse2Bloc->setTitle(QApplication::translate("PrinterChecker", "Buse #2", 0));
        tempBotBuse2Led->setText(QString());
        tempTopBuse2Led->setText(QString());
        boxBloc->setTitle(QApplication::translate("PrinterChecker", "Boitier", 0));
        tempBoxTopLed->setText(QString());
        tempBoxBotLed->setText(QString());
        tempBoxMiddleLed->setText(QString());
        label_3->setText(QApplication::translate("PrinterChecker", "Haut     ", 0));
        label_4->setText(QApplication::translate("PrinterChecker", "Milieu    ", 0));
        label_5->setText(QApplication::translate("PrinterChecker", "Bas", 0));
        bedBloc->setTitle(QApplication::translate("PrinterChecker", "Lits", 0));
        tempBedMidLed->setText(QString());
        tempBedExtLed->setText(QString());
        label_9->setText(QApplication::translate("PrinterChecker", "Milieu", 0));
        label_10->setText(QApplication::translate("PrinterChecker", "Exterieur", 0));
        coldBloc->setTitle(QApplication::translate("PrinterChecker", "Bloc de refroidissement", 0));
        coldBuse1Led->setText(QString());
        coldBoxBloc->setTitle(QApplication::translate("PrinterChecker", "Boitier", 0));
        coldBox1Led->setText(QString());
        coldBox2Led->setText(QString());
        coldBox3Led->setText(QString());
        coldBox4Led->setText(QString());
        coldBuse2Led->setText(QString());
        label_6->setText(QApplication::translate("PrinterChecker", "Buse #1", 0));
        label_7->setText(QApplication::translate("PrinterChecker", "Buse #2", 0));
        groupBox_8->setTitle(QApplication::translate("PrinterChecker", "M\303\251canique", 0));
        label->setText(QApplication::translate("PrinterChecker", "File d\303\251tect\303\251", 0));
        printerPlugLed->setText(QString());
        detectPlasticLed->setText(QString());
        label_2->setText(QApplication::translate("PrinterChecker", "Outil Imprimante branch\303\251", 0));
        bedPlugLed->setText(QString());
        label_8->setText(QApplication::translate("PrinterChecker", "Lit chauffant branch\303\251", 0));
        label_11->setText(QApplication::translate("PrinterChecker", "<html><head/><body><p><span style=\" font-weight:600;\">Pr\303\252t \303\240 l'emploi : <br/></span></p></body></html>", 0));
        printerReadyLed->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PrinterChecker: public Ui_PrinterChecker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTERCHECKER_H
