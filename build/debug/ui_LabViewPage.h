/********************************************************************************
** Form generated from reading UI file 'LabViewPage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABVIEWPAGE_H
#define UI_LABVIEWPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabViewPage
{
public:
    QGroupBox *generalAmbBox;
    QComboBox *selectAmb;
    QPushButton *validAmb;
    QGroupBox *colorBox;
    QWidget *layoutWidget;
    QGridLayout *gridColorSelect;
    QSpinBox *bSpin;
    QSlider *g;
    QLabel *g_label;
    QLabel *r_label;
    QSlider *b;
    QSlider *r;
    QSpinBox *rSpin;
    QLabel *b_label;
    QSpinBox *gSpin;
    QLabel *intensite_label;
    QSlider *intensite;
    QSpinBox *intensiteSpin;
    QLabel *showColor;
    QGroupBox *lightBox;
    QWidget *layoutWidget1;
    QHBoxLayout *selectLightType;
    QRadioButton *globalLightRadio;
    QRadioButton *individualLightRadio;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *intensite_label_2;
    QSpinBox *intensiteSpin_2;
    QSlider *intensite_2;
    QLabel *intensite_label_3;
    QSpinBox *intensiteSpin_3;
    QSlider *intensite_3;
    QGroupBox *profilBox;
    QPushButton *saveProfil;
    QPushButton *loadProfil;
    QLabel *currentProfil;
    QGroupBox *groupBox;
    QPushButton *backFace;
    QPushButton *topFace;
    QPushButton *leftFace;
    QPushButton *rightFace;
    QPushButton *bottomFace;
    QPushButton *frontFace;
    QPushButton *startVisu;
    QPushButton *startRecording;
    QPushButton *backToHelp;

    void setupUi(QWidget *LabViewPage)
    {
        if (LabViewPage->objectName().isEmpty())
            LabViewPage->setObjectName(QStringLiteral("LabViewPage"));
        LabViewPage->resize(800, 550);
        generalAmbBox = new QGroupBox(LabViewPage);
        generalAmbBox->setObjectName(QStringLiteral("generalAmbBox"));
        generalAmbBox->setGeometry(QRect(20, 20, 341, 61));
        selectAmb = new QComboBox(generalAmbBox);
        selectAmb->setObjectName(QStringLiteral("selectAmb"));
        selectAmb->setGeometry(QRect(10, 30, 211, 25));
        validAmb = new QPushButton(generalAmbBox);
        validAmb->setObjectName(QStringLiteral("validAmb"));
        validAmb->setGeometry(QRect(240, 30, 80, 25));
        colorBox = new QGroupBox(LabViewPage);
        colorBox->setObjectName(QStringLiteral("colorBox"));
        colorBox->setGeometry(QRect(20, 90, 341, 231));
        layoutWidget = new QWidget(colorBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 311, 131));
        gridColorSelect = new QGridLayout(layoutWidget);
        gridColorSelect->setObjectName(QStringLiteral("gridColorSelect"));
        gridColorSelect->setContentsMargins(0, 0, 0, 0);
        bSpin = new QSpinBox(layoutWidget);
        bSpin->setObjectName(QStringLiteral("bSpin"));
        bSpin->setMaximum(255);

        gridColorSelect->addWidget(bSpin, 2, 2, 1, 1);

        g = new QSlider(layoutWidget);
        g->setObjectName(QStringLiteral("g"));
        g->setMaximum(255);
        g->setOrientation(Qt::Horizontal);

        gridColorSelect->addWidget(g, 1, 1, 1, 1);

        g_label = new QLabel(layoutWidget);
        g_label->setObjectName(QStringLiteral("g_label"));

        gridColorSelect->addWidget(g_label, 1, 0, 1, 1);

        r_label = new QLabel(layoutWidget);
        r_label->setObjectName(QStringLiteral("r_label"));

        gridColorSelect->addWidget(r_label, 0, 0, 1, 1);

        b = new QSlider(layoutWidget);
        b->setObjectName(QStringLiteral("b"));
        b->setMaximum(255);
        b->setOrientation(Qt::Horizontal);

        gridColorSelect->addWidget(b, 2, 1, 1, 1);

        r = new QSlider(layoutWidget);
        r->setObjectName(QStringLiteral("r"));
        r->setMaximum(255);
        r->setOrientation(Qt::Horizontal);

        gridColorSelect->addWidget(r, 0, 1, 1, 1);

        rSpin = new QSpinBox(layoutWidget);
        rSpin->setObjectName(QStringLiteral("rSpin"));
        rSpin->setMaximum(255);

        gridColorSelect->addWidget(rSpin, 0, 2, 1, 1);

        b_label = new QLabel(layoutWidget);
        b_label->setObjectName(QStringLiteral("b_label"));

        gridColorSelect->addWidget(b_label, 2, 0, 1, 1);

        gSpin = new QSpinBox(layoutWidget);
        gSpin->setObjectName(QStringLiteral("gSpin"));
        gSpin->setMaximum(255);

        gridColorSelect->addWidget(gSpin, 1, 2, 1, 1);

        intensite_label = new QLabel(layoutWidget);
        intensite_label->setObjectName(QStringLiteral("intensite_label"));

        gridColorSelect->addWidget(intensite_label, 3, 0, 1, 1);

        intensite = new QSlider(layoutWidget);
        intensite->setObjectName(QStringLiteral("intensite"));
        intensite->setMaximum(255);
        intensite->setOrientation(Qt::Horizontal);

        gridColorSelect->addWidget(intensite, 3, 1, 1, 1);

        intensiteSpin = new QSpinBox(layoutWidget);
        intensiteSpin->setObjectName(QStringLiteral("intensiteSpin"));
        intensiteSpin->setMaximum(255);

        gridColorSelect->addWidget(intensiteSpin, 3, 2, 1, 1);

        showColor = new QLabel(colorBox);
        showColor->setObjectName(QStringLiteral("showColor"));
        showColor->setGeometry(QRect(270, 180, 41, 41));
        showColor->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(170, 255, 127);\n"
"selection-color: rgb(255, 0, 4);"));
        lightBox = new QGroupBox(LabViewPage);
        lightBox->setObjectName(QStringLiteral("lightBox"));
        lightBox->setGeometry(QRect(20, 330, 341, 161));
        layoutWidget1 = new QWidget(lightBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 120, 181, 25));
        selectLightType = new QHBoxLayout(layoutWidget1);
        selectLightType->setObjectName(QStringLiteral("selectLightType"));
        selectLightType->setContentsMargins(0, 0, 0, 0);
        globalLightRadio = new QRadioButton(layoutWidget1);
        globalLightRadio->setObjectName(QStringLiteral("globalLightRadio"));
        globalLightRadio->setChecked(true);

        selectLightType->addWidget(globalLightRadio);

        individualLightRadio = new QRadioButton(layoutWidget1);
        individualLightRadio->setObjectName(QStringLiteral("individualLightRadio"));

        selectLightType->addWidget(individualLightRadio);

        layoutWidget2 = new QWidget(lightBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 25, 311, 84));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        intensite_label_2 = new QLabel(layoutWidget2);
        intensite_label_2->setObjectName(QStringLiteral("intensite_label_2"));

        gridLayout->addWidget(intensite_label_2, 0, 0, 1, 1);

        intensiteSpin_2 = new QSpinBox(layoutWidget2);
        intensiteSpin_2->setObjectName(QStringLiteral("intensiteSpin_2"));
        intensiteSpin_2->setMaximum(100);

        gridLayout->addWidget(intensiteSpin_2, 0, 1, 3, 1);

        intensite_2 = new QSlider(layoutWidget2);
        intensite_2->setObjectName(QStringLiteral("intensite_2"));
        intensite_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(intensite_2, 1, 0, 1, 1);

        intensite_label_3 = new QLabel(layoutWidget2);
        intensite_label_3->setObjectName(QStringLiteral("intensite_label_3"));

        gridLayout->addWidget(intensite_label_3, 2, 0, 2, 1);

        intensiteSpin_3 = new QSpinBox(layoutWidget2);
        intensiteSpin_3->setObjectName(QStringLiteral("intensiteSpin_3"));
        intensiteSpin_3->setMaximum(100);

        gridLayout->addWidget(intensiteSpin_3, 3, 1, 2, 1);

        intensite_3 = new QSlider(layoutWidget2);
        intensite_3->setObjectName(QStringLiteral("intensite_3"));
        intensite_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(intensite_3, 4, 0, 1, 1);

        profilBox = new QGroupBox(LabViewPage);
        profilBox->setObjectName(QStringLiteral("profilBox"));
        profilBox->setGeometry(QRect(380, 20, 341, 61));
        saveProfil = new QPushButton(profilBox);
        saveProfil->setObjectName(QStringLiteral("saveProfil"));
        saveProfil->setGeometry(QRect(240, 30, 80, 25));
        loadProfil = new QPushButton(profilBox);
        loadProfil->setObjectName(QStringLiteral("loadProfil"));
        loadProfil->setGeometry(QRect(140, 30, 80, 25));
        currentProfil = new QLabel(profilBox);
        currentProfil->setObjectName(QStringLiteral("currentProfil"));
        currentProfil->setGeometry(QRect(20, 30, 101, 21));
        groupBox = new QGroupBox(LabViewPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(380, 90, 361, 401));
        backFace = new QPushButton(groupBox);
        backFace->setObjectName(QStringLiteral("backFace"));
        backFace->setGeometry(QRect(120, 120, 125, 125));
        backFace->setStyleSheet(QStringLiteral("background-image: url(:/img/img/pattern_back.png);"));
        backFace->setIconSize(QSize(100, 100));
        backFace->setAutoRepeat(false);
        backFace->setAutoDefault(false);
        backFace->setFlat(true);
        topFace = new QPushButton(groupBox);
        topFace->setObjectName(QStringLiteral("topFace"));
        topFace->setGeometry(QRect(80, 30, 201, 81));
        topFace->setStyleSheet(QStringLiteral("background-image: url(:/img/img/pattern_t.png);"));
        topFace->setFlat(true);
        leftFace = new QPushButton(groupBox);
        leftFace->setObjectName(QStringLiteral("leftFace"));
        leftFace->setGeometry(QRect(30, 80, 81, 201));
        leftFace->setStyleSheet(QStringLiteral("background-image: url(:/img/img/pattern_l.png);"));
        leftFace->setFlat(true);
        rightFace = new QPushButton(groupBox);
        rightFace->setObjectName(QStringLiteral("rightFace"));
        rightFace->setGeometry(QRect(255, 80, 81, 201));
        rightFace->setStyleSheet(QStringLiteral("background-image: url(:/img/img/pattern_r.png);"));
        rightFace->setFlat(true);
        bottomFace = new QPushButton(groupBox);
        bottomFace->setObjectName(QStringLiteral("bottomFace"));
        bottomFace->setGeometry(QRect(80, 253, 201, 81));
        bottomFace->setStyleSheet(QStringLiteral("background-image: url(:/img/img/pattern_b.png);"));
        bottomFace->setFlat(true);
        frontFace = new QPushButton(groupBox);
        frontFace->setObjectName(QStringLiteral("frontFace"));
        frontFace->setGeometry(QRect(50, 340, 261, 51));
        frontFace->setStyleSheet(QStringLiteral("background-image: url(:/img/img/pattern_f.png);"));
        frontFace->setFlat(true);
        startVisu = new QPushButton(LabViewPage);
        startVisu->setObjectName(QStringLiteral("startVisu"));
        startVisu->setGeometry(QRect(380, 500, 101, 41));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/play_green.png"), QSize(), QIcon::Normal, QIcon::Off);
        startVisu->setIcon(icon);
        startRecording = new QPushButton(LabViewPage);
        startRecording->setObjectName(QStringLiteral("startRecording"));
        startRecording->setGeometry(QRect(490, 500, 141, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        startRecording->setIcon(icon1);
        backToHelp = new QPushButton(LabViewPage);
        backToHelp->setObjectName(QStringLiteral("backToHelp"));
        backToHelp->setGeometry(QRect(640, 500, 91, 41));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        backToHelp->setIcon(icon2);

        retranslateUi(LabViewPage);

        QMetaObject::connectSlotsByName(LabViewPage);
    } // setupUi

    void retranslateUi(QWidget *LabViewPage)
    {
        LabViewPage->setWindowTitle(QApplication::translate("LabViewPage", "Form", 0));
        generalAmbBox->setTitle(QApplication::translate("LabViewPage", "Ambiance G\303\251n\303\251rale", 0));
        validAmb->setText(QApplication::translate("LabViewPage", "S\303\251lectionner", 0));
        colorBox->setTitle(QApplication::translate("LabViewPage", "Couleur G\303\251n\303\251rale", 0));
        g_label->setText(QApplication::translate("LabViewPage", "G :", 0));
        r_label->setText(QApplication::translate("LabViewPage", "R :", 0));
        b_label->setText(QApplication::translate("LabViewPage", "B :", 0));
        intensite_label->setText(QApplication::translate("LabViewPage", "Int. :", 0));
        showColor->setText(QString());
        lightBox->setTitle(QApplication::translate("LabViewPage", "Lumi\303\250re blanche", 0));
        globalLightRadio->setText(QApplication::translate("LabViewPage", "G\303\251n\303\251rale", 0));
        individualLightRadio->setText(QApplication::translate("LabViewPage", "Individuelle", 0));
        intensite_label_2->setText(QApplication::translate("LabViewPage", "Verticale :", 0));
        intensite_label_3->setText(QApplication::translate("LabViewPage", "Horizontale :", 0));
        profilBox->setTitle(QApplication::translate("LabViewPage", "Profile", 0));
        saveProfil->setText(QApplication::translate("LabViewPage", "Enregistrer", 0));
        loadProfil->setText(QApplication::translate("LabViewPage", "Charger", 0));
        currentProfil->setText(QApplication::translate("LabViewPage", "Profile par defaut", 0));
        groupBox->setTitle(QApplication::translate("LabViewPage", "Selection des faces", 0));
        backFace->setText(QApplication::translate("LabViewPage", "Fond", 0));
        topFace->setText(QApplication::translate("LabViewPage", "Haut", 0));
        leftFace->setText(QApplication::translate("LabViewPage", "Gauche", 0));
        rightFace->setText(QApplication::translate("LabViewPage", "Droite", 0));
        bottomFace->setText(QApplication::translate("LabViewPage", "Dessous", 0));
        frontFace->setText(QApplication::translate("LabViewPage", "Face avant", 0));
        startVisu->setText(QApplication::translate("LabViewPage", "Visualiser", 0));
        startRecording->setText(QApplication::translate("LabViewPage", "Enregistrer la vid\303\251o", 0));
        backToHelp->setText(QApplication::translate("LabViewPage", "Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class LabViewPage: public Ui_LabViewPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABVIEWPAGE_H
