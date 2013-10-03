#include "OpenPage.h"
#include "ui_OpenPage.h"

OpenPage::OpenPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenPage)
{
    ui->setupUi(this);
}

OpenPage::~OpenPage()
{
    delete ui;
}


void OpenPage::on_module_clicked()
{
    ((MainWindow*)this->parent())->changeStatePage( Module );
}


void OpenPage::on_help_clicked()
{
    ((MainWindow*)this->parent())->changeStatePage( Help );
}

void OpenPage::on_warning_clicked()
{
    ((MainWindow*)this->parent())->changeStatePage( Warning );
}
