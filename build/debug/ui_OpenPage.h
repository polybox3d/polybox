/********************************************************************************
** Form generated from reading UI file 'OpenPage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENPAGE_H
#define UI_OPENPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenPage
{
public:
    QLabel *label;
    QPushButton *warning;
    QPushButton *module;
    QPushButton *help;
    QLabel *logo;

    void setupUi(QWidget *OpenPage)
    {
        if (OpenPage->objectName().isEmpty())
            OpenPage->setObjectName(QStringLiteral("OpenPage"));
        OpenPage->resize(800, 550);
        label = new QLabel(OpenPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 771, 231));
        label->setScaledContents(true);
        label->setWordWrap(true);
        warning = new QPushButton(OpenPage);
        warning->setObjectName(QStringLiteral("warning"));
        warning->setGeometry(QRect(610, 450, 111, 71));
        module = new QPushButton(OpenPage);
        module->setObjectName(QStringLiteral("module"));
        module->setGeometry(QRect(330, 430, 181, 101));
        help = new QPushButton(OpenPage);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(100, 450, 111, 71));
        logo = new QLabel(OpenPage);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(300, 200, 231, 211));
        logo->setPixmap(QPixmap(QString::fromUtf8("logo_400.png")));
        logo->setScaledContents(true);

        retranslateUi(OpenPage);

        QMetaObject::connectSlotsByName(OpenPage);
    } // setupUi

    void retranslateUi(QWidget *OpenPage)
    {
        OpenPage->setWindowTitle(QApplication::translate("OpenPage", "Form", 0));
        label->setText(QApplication::translate("OpenPage", "<html><head/><body><p><span style=\" font-size:xx-large; font-weight:600;\">Bienvenue !</span></p><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent convallis porttitor orci ut tincidunt. Sed lorem urna, convallis vel tincidunt non, pretium in risus. Donec ac erat semper, eleifend sem vel, ornare mauris. Integer quis est nisi. Curabitur volutpat nulla sed vestibulum tincidunt. </p></body></html>", 0));
        warning->setText(QApplication::translate("OpenPage", "Mentions L\303\251gale", 0));
        module->setText(QApplication::translate("OpenPage", "Commencez", 0));
        help->setText(QApplication::translate("OpenPage", "Aide", 0));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenPage: public Ui_OpenPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENPAGE_H
