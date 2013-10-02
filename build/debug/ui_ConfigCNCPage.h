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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "Led.h"

QT_BEGIN_NAMESPACE

class Ui_ConfigCNCPage
{
public:
    Led *label;

    void setupUi(QWidget *ConfigCNCPage)
    {
        if (ConfigCNCPage->objectName().isEmpty())
            ConfigCNCPage->setObjectName(QStringLiteral("ConfigCNCPage"));
        ConfigCNCPage->resize(800, 550);
        label = new Led(ConfigCNCPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 130, 20, 20));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/led_off_red.png")));

        retranslateUi(ConfigCNCPage);

        QMetaObject::connectSlotsByName(ConfigCNCPage);
    } // setupUi

    void retranslateUi(QWidget *ConfigCNCPage)
    {
        ConfigCNCPage->setWindowTitle(QApplication::translate("ConfigCNCPage", "Form", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConfigCNCPage: public Ui_ConfigCNCPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGCNCPAGE_H
