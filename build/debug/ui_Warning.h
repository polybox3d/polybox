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
    QWidget *generalWidget;
    QWidget *scannerWidget;
    QWidget *printerWidget;
    QWidget *cncWidget;

    void setupUi(QWidget *Warning)
    {
        if (Warning->objectName().isEmpty())
            Warning->setObjectName(QStringLiteral("Warning"));
        Warning->resize(800, 550);
        generalWidget = new QWidget(Warning);
        generalWidget->setObjectName(QStringLiteral("generalWidget"));
        generalWidget->setGeometry(QRect(0, 0, 400, 250));
        scannerWidget = new QWidget(Warning);
        scannerWidget->setObjectName(QStringLiteral("scannerWidget"));
        scannerWidget->setGeometry(QRect(400, 0, 400, 250));
        printerWidget = new QWidget(Warning);
        printerWidget->setObjectName(QStringLiteral("printerWidget"));
        printerWidget->setGeometry(QRect(0, 250, 400, 250));
        cncWidget = new QWidget(Warning);
        cncWidget->setObjectName(QStringLiteral("cncWidget"));
        cncWidget->setGeometry(QRect(400, 250, 400, 250));

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
