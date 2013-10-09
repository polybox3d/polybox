/********************************************************************************
** Form generated from reading UI file 'DialogConfigSoft.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIGSOFT_H
#define UI_DIALOGCONFIGSOFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConfigSoft
{
public:
    QPushButton *close;
    QPushButton *validate;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *homeDirectory;
    QLabel *label_2;
    QLineEdit *linuxcncDirectory;
    QLabel *label_3;
    QLineEdit *linuxcncBin;
    QLabel *label_4;
    QLineEdit *pathDev;
    QLabel *label_6;
    QLineEdit *baudrate;
    QLabel *label_5;
    QLineEdit *webcamName;

    void setupUi(QDialog *DialogConfigSoft)
    {
        if (DialogConfigSoft->objectName().isEmpty())
            DialogConfigSoft->setObjectName(QStringLiteral("DialogConfigSoft"));
        DialogConfigSoft->resize(400, 300);
        close = new QPushButton(DialogConfigSoft);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(310, 260, 80, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon);
        validate = new QPushButton(DialogConfigSoft);
        validate->setObjectName(QStringLiteral("validate"));
        validate->setGeometry(QRect(200, 260, 101, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        validate->setIcon(icon1);
        widget = new QWidget(DialogConfigSoft);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 51, 371, 182));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        homeDirectory = new QLineEdit(widget);
        homeDirectory->setObjectName(QStringLiteral("homeDirectory"));

        gridLayout->addWidget(homeDirectory, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        linuxcncDirectory = new QLineEdit(widget);
        linuxcncDirectory->setObjectName(QStringLiteral("linuxcncDirectory"));

        gridLayout->addWidget(linuxcncDirectory, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        linuxcncBin = new QLineEdit(widget);
        linuxcncBin->setObjectName(QStringLiteral("linuxcncBin"));

        gridLayout->addWidget(linuxcncBin, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        pathDev = new QLineEdit(widget);
        pathDev->setObjectName(QStringLiteral("pathDev"));

        gridLayout->addWidget(pathDev, 3, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        baudrate = new QLineEdit(widget);
        baudrate->setObjectName(QStringLiteral("baudrate"));

        gridLayout->addWidget(baudrate, 4, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        webcamName = new QLineEdit(widget);
        webcamName->setObjectName(QStringLiteral("webcamName"));

        gridLayout->addWidget(webcamName, 5, 1, 1, 1);


        retranslateUi(DialogConfigSoft);

        QMetaObject::connectSlotsByName(DialogConfigSoft);
    } // setupUi

    void retranslateUi(QDialog *DialogConfigSoft)
    {
        DialogConfigSoft->setWindowTitle(QApplication::translate("DialogConfigSoft", "Dialog", 0));
        close->setText(QApplication::translate("DialogConfigSoft", "Fermer", 0));
        validate->setText(QApplication::translate("DialogConfigSoft", "Appliquer", 0));
        label->setText(QApplication::translate("DialogConfigSoft", "Repertoire Home :", 0));
        label_2->setText(QApplication::translate("DialogConfigSoft", "Repertoire LinuxCNC :", 0));
        label_3->setText(QApplication::translate("DialogConfigSoft", "Executable LinuxCNC :", 0));
        label_4->setText(QApplication::translate("DialogConfigSoft", "Repertoire P\303\251ripheriques :", 0));
        label_6->setText(QApplication::translate("DialogConfigSoft", "Baudrate : ", 0));
        label_5->setText(QApplication::translate("DialogConfigSoft", "Nom p\303\251ripherique webcam :", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogConfigSoft: public Ui_DialogConfigSoft {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIGSOFT_H
