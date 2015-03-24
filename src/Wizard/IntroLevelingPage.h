#ifndef INTROLEVELINGPAGE_H
#define INTROLEVELINGPAGE_H

#include <QWizardPage>

namespace Ui {
class IntroLevelingPage;
}

class IntroLevelingPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit IntroLevelingPage(QWidget *parent = 0);
    ~IntroLevelingPage();

private:
    Ui::IntroLevelingPage *ui;
};

#endif // INTROLEVELINGPAGE_H
