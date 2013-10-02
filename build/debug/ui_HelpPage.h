/********************************************************************************
** Form generated from reading UI file 'HelpPage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPPAGE_H
#define UI_HELPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpPage
{
public:

    void setupUi(QWidget *HelpPage)
    {
        if (HelpPage->objectName().isEmpty())
            HelpPage->setObjectName(QStringLiteral("HelpPage"));
        HelpPage->resize(800, 550);

        retranslateUi(HelpPage);

        QMetaObject::connectSlotsByName(HelpPage);
    } // setupUi

    void retranslateUi(QWidget *HelpPage)
    {
        HelpPage->setWindowTitle(QApplication::translate("HelpPage", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpPage: public Ui_HelpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPPAGE_H
