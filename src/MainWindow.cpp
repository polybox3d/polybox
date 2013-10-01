#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    changeStatePage( Start );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeStatePage(PageState new_state)
{
    _currentState = new_state;
    updateStatePage();
}

void MainWindow::updateStatePage()
{
    // @todo thing about delete the widget....
    switch ( _currentState )
    {
    case Start:
        this->setCentralWidget( new OpenPage( this ) );
        break;
    case Module :
        this->setCentralWidget( new ModulePage( this ) );
        break;
    case Help :
        this->setCentralWidget( new HelpPage( this ) );
        break;
    case LabView :
        this->setCentralWidget( new LabViewPage( this ) );
        break;
    default:
        break;

    }

}

void MainWindow::backToModulePage()
{
    changeStatePage( Module );
}
