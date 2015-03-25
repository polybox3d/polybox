#ifndef CONTACTPOINTLEVELINGPAGE_H
#define CONTACTPOINTLEVELINGPAGE_H

#include <iostream>
#include <QWizardPage>
#include <QByteArray>

#include "Config.h"
#include "PolyboxModule.h"


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
private slots:

    void on_startContactProcess_clicked();

private:
    Ui::ContactPointLevelingPage *ui;
    int _id;
    static int next_id;
    bool _contactor;
};

#endif // CONTACTPOINTLEVELINGPAGE_H
