/********************************************************************************
** Form generated from reading UI file 'PrinterPage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTERPAGE_H
#define UI_PRINTERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrinterPage
{
public:
    QGroupBox *groupBox;
    QPushButton *bed_fl;
    QPushButton *bed_bl;
    QPushButton *bed_fr;
    QPushButton *bed_br;
    QGroupBox *bedBox;
    QWidget *layoutWidget;
    QHBoxLayout *bedTempSelectorLayer;
    QRadioButton *inactifBed;
    QRadioButton *plaBed;
    QRadioButton *absBed;
    QRadioButton *nylonBed;
    QRadioButton *customBed;
    QWidget *widget;
    QHBoxLayout *bedtempSliderLayer;
    QSlider *bedTempSlider;
    QSpinBox *bedtempSpin;
    QLabel *label;
    QGroupBox *printerboxBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QSlider *boxTempSlider;
    QSpinBox *boxTempSpin;
    QLabel *label_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *boxInactif;
    QRadioButton *box60;
    QRadioButton *box75;
    QRadioButton *boxCustom;
    QPushButton *pushButton;
    QPushButton *backToHelp;

    void setupUi(QWidget *PrinterPage)
    {
        if (PrinterPage->objectName().isEmpty())
            PrinterPage->setObjectName(QStringLiteral("PrinterPage"));
        PrinterPage->resize(800, 550);
        groupBox = new QGroupBox(PrinterPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(410, 110, 301, 291));
        bed_fl = new QPushButton(groupBox);
        bed_fl->setObjectName(QStringLiteral("bed_fl"));
        bed_fl->setGeometry(QRect(30, 160, 111, 111));
        bed_fl->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        bed_fl->setCheckable(true);
        bed_bl = new QPushButton(groupBox);
        bed_bl->setObjectName(QStringLiteral("bed_bl"));
        bed_bl->setGeometry(QRect(30, 40, 111, 111));
        bed_bl->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        bed_bl->setCheckable(true);
        bed_fr = new QPushButton(groupBox);
        bed_fr->setObjectName(QStringLiteral("bed_fr"));
        bed_fr->setGeometry(QRect(160, 160, 111, 111));
        bed_fr->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        bed_fr->setCheckable(true);
        bed_fr->setFlat(false);
        bed_br = new QPushButton(groupBox);
        bed_br->setObjectName(QStringLiteral("bed_br"));
        bed_br->setGeometry(QRect(160, 40, 111, 111));
        bed_br->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        bed_br->setCheckable(true);
        bedBox = new QGroupBox(PrinterPage);
        bedBox->setObjectName(QStringLiteral("bedBox"));
        bedBox->setGeometry(QRect(10, 110, 361, 131));
        layoutWidget = new QWidget(bedBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 331, 25));
        bedTempSelectorLayer = new QHBoxLayout(layoutWidget);
        bedTempSelectorLayer->setObjectName(QStringLiteral("bedTempSelectorLayer"));
        bedTempSelectorLayer->setContentsMargins(0, 0, 0, 0);
        inactifBed = new QRadioButton(layoutWidget);
        inactifBed->setObjectName(QStringLiteral("inactifBed"));

        bedTempSelectorLayer->addWidget(inactifBed);

        plaBed = new QRadioButton(layoutWidget);
        plaBed->setObjectName(QStringLiteral("plaBed"));
        plaBed->setChecked(true);

        bedTempSelectorLayer->addWidget(plaBed);

        absBed = new QRadioButton(layoutWidget);
        absBed->setObjectName(QStringLiteral("absBed"));

        bedTempSelectorLayer->addWidget(absBed);

        nylonBed = new QRadioButton(layoutWidget);
        nylonBed->setObjectName(QStringLiteral("nylonBed"));

        bedTempSelectorLayer->addWidget(nylonBed);

        customBed = new QRadioButton(layoutWidget);
        customBed->setObjectName(QStringLiteral("customBed"));

        bedTempSelectorLayer->addWidget(customBed);

        widget = new QWidget(bedBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 80, 331, 31));
        bedtempSliderLayer = new QHBoxLayout(widget);
        bedtempSliderLayer->setObjectName(QStringLiteral("bedtempSliderLayer"));
        bedtempSliderLayer->setContentsMargins(0, 0, 0, 0);
        bedTempSlider = new QSlider(widget);
        bedTempSlider->setObjectName(QStringLiteral("bedTempSlider"));
        bedTempSlider->setOrientation(Qt::Horizontal);

        bedtempSliderLayer->addWidget(bedTempSlider);

        bedtempSpin = new QSpinBox(widget);
        bedtempSpin->setObjectName(QStringLiteral("bedtempSpin"));
        bedtempSpin->setMinimum(40);
        bedtempSpin->setMaximum(90);

        bedtempSliderLayer->addWidget(bedtempSpin);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        bedtempSliderLayer->addWidget(label);

        printerboxBox = new QGroupBox(PrinterPage);
        printerboxBox->setObjectName(QStringLiteral("printerboxBox"));
        printerboxBox->setGeometry(QRect(10, 240, 361, 121));
        widget1 = new QWidget(printerboxBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 60, 331, 31));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        boxTempSlider = new QSlider(widget1);
        boxTempSlider->setObjectName(QStringLiteral("boxTempSlider"));
        boxTempSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(boxTempSlider);

        boxTempSpin = new QSpinBox(widget1);
        boxTempSpin->setObjectName(QStringLiteral("boxTempSpin"));
        boxTempSpin->setMaximum(100);

        horizontalLayout->addWidget(boxTempSpin);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        widget2 = new QWidget(printerboxBox);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 30, 331, 25));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        boxInactif = new QRadioButton(widget2);
        boxInactif->setObjectName(QStringLiteral("boxInactif"));

        horizontalLayout_2->addWidget(boxInactif);

        box60 = new QRadioButton(widget2);
        box60->setObjectName(QStringLiteral("box60"));
        box60->setChecked(true);

        horizontalLayout_2->addWidget(box60);

        box75 = new QRadioButton(widget2);
        box75->setObjectName(QStringLiteral("box75"));

        horizontalLayout_2->addWidget(box75);

        boxCustom = new QRadioButton(widget2);
        boxCustom->setObjectName(QStringLiteral("boxCustom"));

        horizontalLayout_2->addWidget(boxCustom);

        pushButton = new QPushButton(PrinterPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 420, 191, 41));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/play_green.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        backToHelp = new QPushButton(PrinterPage);
        backToHelp->setObjectName(QStringLiteral("backToHelp"));
        backToHelp->setGeometry(QRect(620, 420, 91, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        backToHelp->setIcon(icon1);

        retranslateUi(PrinterPage);

        QMetaObject::connectSlotsByName(PrinterPage);
    } // setupUi

    void retranslateUi(QWidget *PrinterPage)
    {
        PrinterPage->setWindowTitle(QApplication::translate("PrinterPage", "Form", 0));
        groupBox->setTitle(QApplication::translate("PrinterPage", "Selection des lits", 0));
        bed_fl->setText(QString());
        bed_bl->setText(QString());
        bed_fr->setText(QString());
        bed_br->setText(QString());
        bedBox->setTitle(QApplication::translate("PrinterPage", "Temperature des lits activ\303\251s ", 0));
        inactifBed->setText(QApplication::translate("PrinterPage", "Inactif", 0));
        plaBed->setText(QApplication::translate("PrinterPage", "PLA", 0));
        absBed->setText(QApplication::translate("PrinterPage", "ABS", 0));
        nylonBed->setText(QApplication::translate("PrinterPage", "Nylon", 0));
        customBed->setText(QApplication::translate("PrinterPage", "Custom", 0));
        label->setText(QApplication::translate("PrinterPage", "( \302\260C )", 0));
        printerboxBox->setTitle(QApplication::translate("PrinterPage", "Temperature du boitier", 0));
        label_2->setText(QApplication::translate("PrinterPage", "( \302\260C )", 0));
        boxInactif->setText(QApplication::translate("PrinterPage", "Inactif", 0));
        box60->setText(QApplication::translate("PrinterPage", "60\302\260C", 0));
        box75->setText(QApplication::translate("PrinterPage", "75\302\260C", 0));
        boxCustom->setText(QApplication::translate("PrinterPage", "Custom", 0));
        pushButton->setText(QApplication::translate("PrinterPage", "Lancer L'impression", 0));
        backToHelp->setText(QApplication::translate("PrinterPage", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class PrinterPage: public Ui_PrinterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTERPAGE_H
