/********************************************************************************
** Form generated from reading UI file 'Warning.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Warning
{
public:

    void setupUi(QWidget *Warning)
    {
        if (Warning->objectName().isEmpty())
            Warning->setObjectName(QStringLiteral("Warning"));
        Warning->resize(400, 300);

        retranslateUi(Warning);

        QMetaObject::connectSlotsByName(Warning);
    } // setupUi

    void retranslateUi(QWidget *Warning)
    {
        Warning->setWindowTitle(QApplication::translate("Warning", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Warning: public Ui_Warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H
