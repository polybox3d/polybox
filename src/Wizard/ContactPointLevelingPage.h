#ifndef CONTACTPOINTLEVELINGPAGE_H
#define CONTACTPOINTLEVELINGPAGE_H

#include <iostream>
#include <QWizardPage>
#include <QByteArray>
#include <QTimer>

#include "Config.h"
#include "ComModule.h"


namespace Ui {
class ContactPointLevelingPage;
}

class ContactPointLevelingPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ContactPointLevelingPage(QWidget *parent = 0);
    ~ContactPointLevelingPage();
    void initializePage();
    void setupField();

public slots:
    void parseMCode(QByteArray stream);
    void getUpdates();
private slots:

    void on_startContactProcess_clicked();

private:
    void saveProbing(float x, float  y, float z);
    Ui::ContactPointLevelingPage *ui;
    int _id;
    static int next_id;
    bool _contactor;
    QTimer _getUpdateTimer;
};

#endif // CONTACTPOINTLEVELINGPAGE_H
