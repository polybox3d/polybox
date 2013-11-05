#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _polybox = new PolyboxModule( this );
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
        this->setCentralWidget( new OpenPage( _polybox, this ) );
        break;
    case Module :
        this->setCentralWidget( new ModulePage( _polybox, this ) );
        break;
    case Help :
        this->setCentralWidget( new HelpPage( this ) );
        break;
    case Warning :
        this->setCentralWidget( new WarningPage( _polybox, this ) );
        break;
    case LabView :
        this->setCentralWidget( new LabViewPage( _polybox->labViewModule(), this ) );
        break;
    case Printer :
        this->setCentralWidget( new PrinterPage( _polybox->printerModule(), this ) );
        break;
    case CNC :
        this->setCentralWidget( new CNCPage( this ) );
        break;
    case ConfigurCNC :
        this->setCentralWidget( new ConfigCNCPage( this ) );
        break;
    case DynamicTest :
        this->setCentralWidget( new DynamicTestPage( this ) );
        break;
    case ScannerLaser :
    {
        QProcess* laser = new QProcess(this);
        laser->start( Config::scannerLaserPath );
        break;
    }
    default:
        break;
        
    }
    
}

void MainWindow::backToModulePage()
{
    changeStatePage( Module );
}

void MainWindow::backToHelpPage()
{
    changeStatePage( Help );
}
