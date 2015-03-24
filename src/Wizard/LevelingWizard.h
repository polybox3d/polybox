#ifndef LEVELINGWIZARD_H
#define LEVELINGWIZARD_H

#include <QWizard>

#include "IntroLevelingPage.h"
#include "ContactPointLevelingPage.h"

namespace Ui {
class LevelingWizard;
}

class LevelingWizard : public QWizard
{
    Q_OBJECT

public:
    explicit LevelingWizard(QWidget *parent = 0);
    void accept() Q_DECL_OVERRIDE;
    ~LevelingWizard();

private:
};

#endif // LEVELINGWIZARD_H
