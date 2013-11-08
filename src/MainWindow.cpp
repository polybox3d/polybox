#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _polybox = new PolyboxModule( this );
    ui->setupUi(this);
    _joypadActivated = false;

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
        connect(this,SIGNAL(joypadOff()),this->centralWidget(),SLOT(disableJoypad()));
        connect(this,SIGNAL(joypadOn(QJoystick*)),this->centralWidget(),SLOT(setJoypad(QJoystick*)));
        if ( _joypadActivated )
        {
            emit joypadOn( PolyboxModule::getJoypad() );
        }
        break;
    case Module :
        this->setCentralWidget( new ModulePage( _polybox, this ) );

        connect(this,SIGNAL(joypadOff()),this->centralWidget(),SLOT(disableJoypad()));
        connect(this,SIGNAL(joypadOn(QJoystick*)),this->centralWidget(),SLOT(setJoypad(QJoystick*)));
        if ( _joypadActivated )
        {
            emit joypadOn( PolyboxModule::getJoypad() );
        }
        break;
    case Help :
        this->setCentralWidget( new HelpPage( this ) );
        break;
    case Warning :
        this->setCentralWidget( new WarningPage( _polybox, this ) );
        break;
    case LabView :
        this->setCentralWidget( new LabViewPage( _polybox->labViewModule(), this ) );
        connect(this,SIGNAL(joypadOff()),this->centralWidget(),SLOT(disableJoypad()));
        connect(this,SIGNAL(joypadOn(QJoystick*)),this->centralWidget(),SLOT(setJoypad(QJoystick*)));
        if ( _joypadActivated )
        {
            emit joypadOn( PolyboxModule::getJoypad() );
        }
        break;
    case Scanner:
    {
        bool scanner_ok = _polybox->isScannerReady();
        if ( scanner_ok || Config::bypassCheck )
        {
            DialogScanner dialog((QWidget*)this->parent());
            int value_ret = dialog.exec();
            if ( value_ret != 0 )
            {
                CHANGE_PAGE( static_cast<PageState>(value_ret) );
            }
        }
        else
        {
            CheckerModele* checker = new CheckerModele((QWidget*)this->parent());

            checker->setWindowTitle("Etat du Scanner");
            checker->setContentWidget( new SCannerChecker( _polybox->scannerModule(), checker));
            int value_ret = checker->exec();
            if ( value_ret != 0 )
            {
                CHANGE_PAGE( static_cast<PageState>(value_ret) );
            }
        }

    }
        break;
    case Printer :
    {
        bool printer_ok = _polybox->isPrinterReady();
        if ( printer_ok || Config::bypassCheck )
        {
            this->setCentralWidget( new PrinterPage( _polybox->printerModule(), this ) );
        }
        else
        {
            CheckerModele* checker = new CheckerModele((QWidget*)this->parent());

            checker->setWindowTitle("Etat de l'imprimante");
            checker->setContentWidget( new PrinterChecker( _polybox->printerModule(), checker));
            int value_ret = checker->exec();
            if ( value_ret != 0 )
            {
                CHANGE_PAGE( static_cast<PageState>(value_ret) );
            }
        }
    }
        break;
    case CNC :
    {
        bool cnc_ok = _polybox->isCncReady();
        if ( cnc_ok || Config::bypassCheck )
        {
            DialogCNC dialog((QWidget*)this->parent());
            int value_ret = dialog.exec();
            if ( value_ret != 0 )
            {
                this->setCentralWidget( new CNCPage( this ) );
            }
        }
        else
        {
            CheckerModele* checker = new CheckerModele((QWidget*)this->parent());


            checker->setWindowTitle("Etat de la CN");
            checker->setContentWidget( new CNCChecker( _polybox->cncModule(), checker));
            int value_ret = checker->exec();
            if ( value_ret != 0 )
            {
                CHANGE_PAGE( static_cast<PageState>(value_ret) );
            }

        }
    }
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

void MainWindow::on_actionActiver_Manette_triggered()
{
    if ( _joypadActivated )
    {
        ui->actionActiver_Manette->setText(tr("Activer manette"));
        _polybox->unloadJoypad();
        emit joypadOff();
    }
    else
    {
        _polybox->loadJoypad();
        ui->actionActiver_Manette->setText(tr("Désactiver manette"));
        emit joypadOn( PolyboxModule::getJoypad() );
    }
    _joypadActivated = !_joypadActivated;
}

void MainWindow::backToModulePage()
{
    changeStatePage( Module );
}

void MainWindow::backToHelpPage()
{
    changeStatePage( Help );
}

void MainWindow::on_actionCNC_triggered()
{
    changeStatePage( CNC );
}

void MainWindow::on_actionImprimante_triggered()
{
    changeStatePage( Printer );
}

void MainWindow::on_actionScanner_triggered()
{
    changeStatePage( Scanner );
}

void MainWindow::on_actionLabView_triggered()
{
    changeStatePage( LabView );
}

