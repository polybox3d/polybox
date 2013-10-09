/********************************************************************************
** Form generated from reading UI file 'DynamicTestPage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYNAMICTESTPAGE_H
#define UI_DYNAMICTESTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DynamicTestPage
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *DynamicTestPage)
    {
        if (DynamicTestPage->objectName().isEmpty())
            DynamicTestPage->setObjectName(QStringLiteral("DynamicTestPage"));
        DynamicTestPage->resize(800, 550);
        pushButton = new QPushButton(DynamicTestPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 100, 80, 25));
        label = new QLabel(DynamicTestPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 100, 57, 17));
        label_2 = new QLabel(DynamicTestPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 741, 71));

        retranslateUi(DynamicTestPage);

        QMetaObject::connectSlotsByName(DynamicTestPage);
    } // setupUi

    void retranslateUi(QWidget *DynamicTestPage)
    {
        DynamicTestPage->setWindowTitle(QApplication::translate("DynamicTestPage", "Form", 0));
        pushButton->setText(QApplication::translate("DynamicTestPage", "carot", 0));
        label->setText(QApplication::translate("DynamicTestPage", "test1", 0));
        label_2->setText(QApplication::translate("DynamicTestPage", "Cette page vous permet de lancer des tests dynamiques pour v\303\251rifier le bon fonctionnement de votre machine.", 0));
    } // retranslateUi

};

namespace Ui {
    class DynamicTestPage: public Ui_DynamicTestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYNAMICTESTPAGE_H
