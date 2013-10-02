/********************************************************************************
** Form generated from reading UI file 'CheckerModele.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKERMODELE_H
#define UI_CHECKERMODELE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckerModele
{
public:
    QWidget *contentWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *help;
    QPushButton *pushButton;
    QPushButton *close;

    void setupUi(QWidget *CheckerModele)
    {
        if (CheckerModele->objectName().isEmpty())
            CheckerModele->setObjectName(QStringLiteral("CheckerModele"));
        CheckerModele->resize(400, 275);
        contentWidget = new QWidget(CheckerModele);
        contentWidget->setObjectName(QStringLiteral("contentWidget"));
        contentWidget->setGeometry(QRect(0, 0, 400, 230));
        contentWidget->setAutoFillBackground(false);
        layoutWidget = new QWidget(CheckerModele);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 240, 331, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        help = new QPushButton(layoutWidget);
        help->setObjectName(QStringLiteral("help"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon);

        horizontalLayout->addWidget(help);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        horizontalLayout->addWidget(pushButton);

        close = new QPushButton(layoutWidget);
        close->setObjectName(QStringLiteral("close"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon2);

        horizontalLayout->addWidget(close);


        retranslateUi(CheckerModele);

        QMetaObject::connectSlotsByName(CheckerModele);
    } // setupUi

    void retranslateUi(QWidget *CheckerModele)
    {
        CheckerModele->setWindowTitle(QApplication::translate("CheckerModele", "Form", 0));
        help->setText(QApplication::translate("CheckerModele", "Aide", 0));
        pushButton->setText(QApplication::translate("CheckerModele", "Mettre \303\240 jour", 0));
        close->setText(QApplication::translate("CheckerModele", "Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class CheckerModele: public Ui_CheckerModele {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKERMODELE_H
