#include "ModulePage.h"
#include "ui_ModulePage.h"

ModulePage::ModulePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModulePage)
{
    _base_scaling_size = 10;
    ui->setupUi(this);
    ui->homeButton->installEventFilter( this );
}

ModulePage::~ModulePage()
{
    delete ui;
}

bool ModulePage::eventFilter(QObject *obj, QEvent *event)
{
    if ( obj == ui->homeButton )
    {
        if ( event->type() == QEvent::Enter )
        {
            ui->homeButton->setGeometry(ui->homeButton->x()-_base_scaling_size/2,
                                        ui->homeButton->y()-_base_scaling_size/2,
                                        ui->homeButton->width()+_base_scaling_size,
                                        ui->homeButton->height()+_base_scaling_size);
            return true;
        }
        else if ( event->type() == QEvent::MouseButtonRelease )
        {
            ((MainWindow*)this->parent())->changeStatePage( Start );
            return true;
        }
        else if ( event->type() == QEvent::Leave )
        {
            ui->homeButton->setGeometry(ui->homeButton->x()+_base_scaling_size/2,
                                        ui->homeButton->y()+_base_scaling_size/2,
                                        ui->homeButton->width()-_base_scaling_size,
                                        ui->homeButton->height()-_base_scaling_size);
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}


void ModulePage::on_labviewButton_clicked()
{
    CHANGE_PAGE( LabView );
}


void ModulePage::on_printerButton_clicked()
{
    CHANGE_PAGE( Printer );
}

void ModulePage::on_cncButton_clicked()
{
    DialogCNC dialog((QWidget*)this->parent());
    int value_ret = dialog.exec();
    if ( value_ret != 0 )
    {
        CHANGE_PAGE( static_cast<PageState>(value_ret) );
    }
}
