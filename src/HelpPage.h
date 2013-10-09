#ifndef HELPPAGE_H
#define HELPPAGE_H

#include <QWidget>

#include "HomeButton.h"
#include "MainWindow.h"

namespace Ui {
class HelpPage;
}
/**
 * @brief The HelpPage class QWidget page showing help for user. Links, text, video, etc..
 */
class HelpPage : public QWidget
{
    Q_OBJECT

public:
    explicit HelpPage(QWidget *parent = 0);
    ~HelpPage();
public slots:
    void backPage();
private:
    /**
     * @brief ui Graphical layer.
     */
    Ui::HelpPage *ui;
};

#endif // HELPPAGE_H
