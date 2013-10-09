/********************************************************************************
** Form generated from reading UI file 'DialogDynamicTest.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDYNAMICTEST_H
#define UI_DIALOGDYNAMICTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogDynamicTest
{
public:
    QPushButton *close;

    void setupUi(QDialog *DialogDynamicTest)
    {
        if (DialogDynamicTest->objectName().isEmpty())
            DialogDynamicTest->setObjectName(QStringLiteral("DialogDynamicTest"));
        DialogDynamicTest->resize(400, 300);
        close = new QPushButton(DialogDynamicTest);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(310, 270, 80, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon);

        retranslateUi(DialogDynamicTest);

        QMetaObject::connectSlotsByName(DialogDynamicTest);
    } // setupUi

    void retranslateUi(QDialog *DialogDynamicTest)
    {
        DialogDynamicTest->setWindowTitle(QApplication::translate("DialogDynamicTest", "Dialog", 0));
        close->setText(QApplication::translate("DialogDynamicTest", "Fermer", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogDynamicTest: public Ui_DialogDynamicTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDYNAMICTEST_H
