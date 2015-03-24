#ifndef CONTACTPOINTLEVELINGPAGE_H
#define CONTACTPOINTLEVELINGPAGE_H

#include <QWizardPage>

namespace Ui {
class ContactPointLevelingPage;
}

class ContactPointLevelingPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ContactPointLevelingPage(QWidget *parent = 0);
    ~ContactPointLevelingPage();

private:
    Ui::ContactPointLevelingPage *ui;
};

#endif // CONTACTPOINTLEVELINGPAGE_H
