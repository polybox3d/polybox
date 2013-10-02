/********************************************************************************
** Form generated from reading UI file 'DialogCNC.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCNC_H
#define UI_DIALOGCNC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogCNC
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *configuration;
    QPushButton *startCnc;
    QPushButton *help;
    QPushButton *close;

    void setupUi(QDialog *DialogCNC)
    {
        if (DialogCNC->objectName().isEmpty())
            DialogCNC->setObjectName(QStringLiteral("DialogCNC"));
        DialogCNC->resize(390, 213);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/conf.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogCNC->setWindowIcon(icon);
        DialogCNC->setStyleSheet(QStringLiteral(""));
        label = new QLabel(DialogCNC);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 331, 151));
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(true);
        layoutWidget = new QWidget(DialogCNC);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 170, 371, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        configuration = new QPushButton(layoutWidget);
        configuration->setObjectName(QStringLiteral("configuration"));
        configuration->setIcon(icon);

        horizontalLayout->addWidget(configuration);

        startCnc = new QPushButton(layoutWidget);
        startCnc->setObjectName(QStringLiteral("startCnc"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/play_green.png"), QSize(), QIcon::Normal, QIcon::Off);
        startCnc->setIcon(icon1);

        horizontalLayout->addWidget(startCnc);

        help = new QPushButton(layoutWidget);
        help->setObjectName(QStringLiteral("help"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon2);

        horizontalLayout->addWidget(help);

        close = new QPushButton(layoutWidget);
        close->setObjectName(QStringLiteral("close"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/img/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon3);

        horizontalLayout->addWidget(close);


        retranslateUi(DialogCNC);

        QMetaObject::connectSlotsByName(DialogCNC);
    } // setupUi

    void retranslateUi(QDialog *DialogCNC)
    {
        DialogCNC->setWindowTitle(QApplication::translate("DialogCNC", "Information sur le module CNC", 0));
        label->setText(QApplication::translate("DialogCNC", "<html><head/><body><p>Diff\303\251rentes actions sont possibles sur le module CNC.</p><p>Il est tr\303\250s fortement conseill\303\251 de v\303\251rifier le param\303\251trage de votre machine et son bon fonctionnement avant sa premi\303\250re utilisation. Diff\303\251rent outils et aides vous sont disponibles pour une meilleur prise en main du module</p></body></html>", 0));
        configuration->setText(QApplication::translate("DialogCNC", "Configuration", 0));
        startCnc->setText(QApplication::translate("DialogCNC", "Lancer ", 0));
        help->setText(QApplication::translate("DialogCNC", "Aide", 0));
        close->setText(QApplication::translate("DialogCNC", "Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogCNC: public Ui_DialogCNC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCNC_H
