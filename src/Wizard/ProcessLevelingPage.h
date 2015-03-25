#ifndef PROCESSLEVELINGPAGE_H
#define PROCESSLEVELINGPAGE_H

#include <QWizardPage>

namespace Ui {
class ProcessLevelingPage;
}

class ProcessLevelingPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ProcessLevelingPage(QWidget *parent = 0);
    ~ProcessLevelingPage();
    bool generateRotationMatrix();
    void initializePage();

private:
    Ui::ProcessLevelingPage *ui;
};

#endif // PROCESSLEVELINGPAGE_H
