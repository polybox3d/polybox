/********************************************************************************
** Form generated from reading UI file 'ConfigCNCPage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGCNCPAGE_H
#define UI_CONFIGCNCPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigCNCPage
{
public:
    QGroupBox *groupBox_2;
    QPushButton *latencyHisto;
    QPushButton *latencyPlot;
    QPushButton *latencyTab;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QPushButton *configStepper;
    QPushButton *stressCNC;
    QLabel *label_3;

    void setupUi(QWidget *ConfigCNCPage)
    {
        if (ConfigCNCPage->objectName().isEmpty())
            ConfigCNCPage->setObjectName(QStringLiteral("ConfigCNCPage"));
        ConfigCNCPage->resize(800, 550);
        groupBox_2 = new QGroupBox(ConfigCNCPage);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 20, 571, 191));
        latencyHisto = new QPushButton(groupBox_2);
        latencyHisto->setObjectName(QStringLiteral("latencyHisto"));
        latencyHisto->setGeometry(QRect(50, 150, 101, 25));
        latencyPlot = new QPushButton(groupBox_2);
        latencyPlot->setObjectName(QStringLiteral("latencyPlot"));
        latencyPlot->setGeometry(QRect(220, 150, 101, 25));
        latencyTab = new QPushButton(groupBox_2);
        latencyTab->setObjectName(QStringLiteral("latencyTab"));
        latencyTab->setGeometry(QRect(370, 150, 101, 25));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 531, 101));
        label->setWordWrap(true);
        groupBox = new QGroupBox(ConfigCNCPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 220, 361, 161));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 331, 61));
        label_2->setWordWrap(true);
        configStepper = new QPushButton(groupBox);
        configStepper->setObjectName(QStringLiteral("configStepper"));
        configStepper->setGeometry(QRect(90, 110, 141, 25));
        stressCNC = new QPushButton(ConfigCNCPage);
        stressCNC->setObjectName(QStringLiteral("stressCNC"));
        stressCNC->setGeometry(QRect(420, 300, 131, 25));
        label_3 = new QLabel(ConfigCNCPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 240, 171, 51));
        label_3->setWordWrap(true);

        retranslateUi(ConfigCNCPage);

        QMetaObject::connectSlotsByName(ConfigCNCPage);
    } // setupUi

    void retranslateUi(QWidget *ConfigCNCPage)
    {
        ConfigCNCPage->setWindowTitle(QApplication::translate("ConfigCNCPage", "Form", 0));
        groupBox_2->setTitle(QApplication::translate("ConfigCNCPage", "Latence", 0));
        latencyHisto->setText(QApplication::translate("ConfigCNCPage", "Histogramme", 0));
        latencyPlot->setText(QApplication::translate("ConfigCNCPage", "Courbe", 0));
        latencyTab->setText(QApplication::translate("ConfigCNCPage", "Tableau", 0));
        label->setText(QApplication::translate("ConfigCNCPage", "<html><head/><body><p>Ces outils vous permettent de v\303\251rifier le bon fonctionnement temsp r\303\251el de votre machine.Plus particuli\303\250rement la latence dans l'execution du code. Une latence trop grande (&gt;50-60uS) peut devenir probl\303\250matique pour un contr\303\264le fluide de la CN. Pour effectuer un test repr\303\251sentatif, il est important de &quot;stresser&quot; ma machine en lan\303\247ant des programmes lourd, comem OpenGL, une copie sur disque ou m\303\252me lire une vid\303\251o HD. Le test doit durer le maximum de temps possible (&gt;5min).<br/></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("ConfigCNCPage", "Configurations avanc\303\251es", 0));
        label_2->setText(QApplication::translate("ConfigCNCPage", "<html><head/><body><p>Outils pour utilisateur avertis uniquement. Il permet de configurer l'ensemble de votre CN. Des pas moteur \303\240 l'affectations des pins pour la communication. </p><p><br/></p></body></html>", 0));
        configStepper->setText(QApplication::translate("ConfigCNCPage", "Configuration Stepper", 0));
        stressCNC->setText(QApplication::translate("ConfigCNCPage", "Torturer la machine", 0));
        label_3->setText(QApplication::translate("ConfigCNCPage", "Lance une s\303\251rie d'instruction G-Code \303\240 la machine ", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigCNCPage: public Ui_ConfigCNCPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGCNCPAGE_H
