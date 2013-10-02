/********************************************************************************
** Form generated from reading UI file 'DialogScanner.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSCANNER_H
#define UI_DIALOGSCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogScanner
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *goBackHelp;
    QPushButton *close;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *laser;
    QPushButton *primesense;

    void setupUi(QDialog *DialogScanner)
    {
        if (DialogScanner->objectName().isEmpty())
            DialogScanner->setObjectName(QStringLiteral("DialogScanner"));
        DialogScanner->resize(365, 267);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/laser.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogScanner->setWindowIcon(icon);
        label = new QLabel(DialogScanner);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 341, 71));
        label->setWordWrap(true);
        widget = new QWidget(DialogScanner);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 210, 261, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        goBackHelp = new QPushButton(widget);
        goBackHelp->setObjectName(QStringLiteral("goBackHelp"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        goBackHelp->setIcon(icon1);

        horizontalLayout->addWidget(goBackHelp);

        close = new QPushButton(widget);
        close->setObjectName(QStringLiteral("close"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon2);

        horizontalLayout->addWidget(close);

        widget1 = new QWidget(DialogScanner);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(100, 80, 181, 131));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        laser = new QPushButton(widget1);
        laser->setObjectName(QStringLiteral("laser"));
        laser->setIcon(icon);
        laser->setIconSize(QSize(36, 36));

        verticalLayout->addWidget(laser);

        primesense = new QPushButton(widget1);
        primesense->setObjectName(QStringLiteral("primesense"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/img/primesense.png"), QSize(), QIcon::Normal, QIcon::Off);
        primesense->setIcon(icon3);
        primesense->setIconSize(QSize(36, 36));

        verticalLayout->addWidget(primesense);


        retranslateUi(DialogScanner);

        QMetaObject::connectSlotsByName(DialogScanner);
    } // setupUi

    void retranslateUi(QDialog *DialogScanner)
    {
        DialogScanner->setWindowTitle(QApplication::translate("DialogScanner", "S\303\251lection du mode Scanner", 0));
        label->setText(QApplication::translate("DialogScanner", "<html><head/><body><p align=\"center\">S\303\251lectionner le type de scanner que vous souhaitez utiliser.</p><p align=\"center\"><br/>Pour plus d'information, R\303\251f\303\251rez-vous \303\240 l'aide.<br/></p></body></html>", 0));
        goBackHelp->setText(QApplication::translate("DialogScanner", "Aide", 0));
        close->setText(QApplication::translate("DialogScanner", "Fermer", 0));
        laser->setText(QApplication::translate("DialogScanner", "Scanner Laser", 0));
        primesense->setText(QApplication::translate("DialogScanner", "Capteur PrimeSense", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogScanner: public Ui_DialogScanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSCANNER_H
