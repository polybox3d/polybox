#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow* MainWindow::mainwindow=NULL;

MainWindow* MainWindow::getMainWindow(){
    return mainwindow;
}

void MainWindow::errorWindow(QString errorText)
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error",errorText);
    messageBox.setFixedSize(500,200);
}

void MainWindow::textWindow(QString text)
{    
    QMessageBox messageBox;
    messageBox.information(0,"Information",text);
    messageBox.setFixedSize(500,200);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainwindow = this;

    _polybox = new PolyboxModule( this );
    connect(_polybox, SIGNAL(updateHardware()),this,SLOT(updateHardware()));

    ui->setupUi(this);

    setupLanguage();
    _joypadActivated = false;
    _webcam = NULL;
    _dockLV = NULL;

    /**             ATU BUTTON              **/
    _atuON = true;
    _atu = new ATUButton( 60, 30, this );
    _atu->setGeometry( this->width()-_atu->width()-10,
                     ui->menuBar->height()+2,
                     _atu->width(), _atu->height());
    connect ( _atu, SIGNAL(released()), this, SLOT(toggleATU()));


    changeStatePage( Start );
    

    setupWebcamMenu();
    setupSerialMenu();
}
void MainWindow::startConsoleWindow()
{
    if ( SerialPort::getSerial()->isConnected() )
    {
        Console* c = new Console();
        c->setWindowTitle("Console");
        c->show();
    }
}

void MainWindow::restartApp()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
}

void MainWindow::translateApp()
{
    if ( QAction* act = dynamic_cast<QAction*>(sender()) )
    {
        QSettings().setValue("lang",act->text());
        this->restartApp();
    }
}

void MainWindow::setupLanguage()
{
    QDir directory( Config::translationPath );
    QStringList ts_files = directory.entryList(QStringList("*.ts")) ;
    QString lang;
    QAction* act;

    foreach( QString file, ts_files)
    {
        lang = file.split(".").first().split("_").last();
        act = ui->menuLangage->addAction( lang );
        connect(act,SIGNAL(triggered()),this, SLOT(translateApp()));
    }

}

void MainWindow::toggleATU()
{
    _atuON = !_atuON;
    this->centralWidget()->setEnabled( _atuON );
    if ( _dockLV != NULL )
    {
        _dockLV->setEnabled( _atuON );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupSerialMenu()
{
    ui->menuConnexion->clear();
    QAction* act;
    foreach ( QString serial, SerialPort::getDevicesNames(Config::pathToSerialDevice, "tty*"))
    {
        if ( serial.startsWith("tty"))
        {
            if ( ! serial.startsWith( "ttyS" ))
            {
                if ( serial.startsWith("ttyACM") || serial.startsWith("ttyUSB") )
                {
                    act = ui->menuConnexion->addAction( serial );
                    act->setCheckable( true );
                    connect( act, SIGNAL(triggered()),this,SLOT(startConnexion()) );
                    if ( ! serial.compare(Polyplexer::getInstance()->portMachine() ) && SerialPort::getSerial()->isConnected() ) // We are already connected to this serial !
                    {
                        act->setChecked( true );
                    }
                }
            }
        }
    }
}


void MainWindow::startConnexion()
{
    if ( QAction* act = dynamic_cast<QAction*>(sender()) )
    {
        Polyplexer* poly = Polyplexer::getInstance();

        if ( ! poly->portMachine().compare( act->text().split('/').last() ) && SerialPort::getSerial()->isConnected() ) //already connected
        {
            poly->stop();
            act->setChecked(false);
        }
        else
        {
            bool connected = _polybox->connectToPrinter( Config::pathToSerialDevice, act->text().split('/').last() );
            act->setChecked( connected ) ;


        }
    }
}

void MainWindow::setupWebcamMenu()
{
    // We add all camera available
    ui->menuVisualiser->clear();
    QAction* act;
    foreach ( QString camera, LabViewModule::getAllCamera( Config::pathToWebcamDevice ))
    {
        act = ui->menuVisualiser->addAction( camera );
        connect( act, SIGNAL(triggered()),this,SLOT(startCamera()) );
    }
}

void MainWindow::startCamera()
{
    if ( QAction* act = dynamic_cast<QAction*>(sender()) )
    {
        _webcam = LabViewModule::startCamera( _webcam, act->text());
    }
}
void MainWindow::updateHardware()
{
    setupSerialMenu();
    setupWebcamMenu();
}

void MainWindow::changeStatePage(PageState new_state)
{
    _previousState = _currentState;
    _currentState = new_state;
    updateStatePage();
}

void MainWindow::updateStatePage()
{

    // @todo thing about delete the widget....
    qApp->processEvents();

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
        this->setCentralWidget( new LabViewPage( _polybox->labViewModule(), this, false ) );
        connect(this,SIGNAL(joypadOff()),this->centralWidget(),SLOT(disableJoypad()));
        connect(this,SIGNAL(joypadOn(QJoystick*)),this->centralWidget(),SLOT(setJoypad(QJoystick*)));
        if ( _joypadActivated )
        {
            emit joypadOn( PolyboxModule::getJoypad() );
        }
        break;
    case LabViewDock :
    {
        if (_polybox->isCommonReady() || Config::bypassCheck )
        {
            _dockLV = new QDockWidget("LabView (dock) ",this);
            _dockLV->setWidget( new LabViewPage( _polybox->labViewModule(), this, true ) );
            _dockLV->setFloating( true );
            _dockLV->show();
            _dockLV->setEnabled( _atuON );
        }
        else
        {
            CheckerModele* checker = new CheckerModele((QWidget*)this->parent());


            checker->setWindowTitle("Etat de la machine");
            checker->setContentWidget( new GlobalChecker( _polybox->globalModule(),  checker));
            _polybox->globalModule()->updateComponents();
            int value_ret = checker->exec();
            if ( value_ret != 0 )
            {
                CHANGE_PAGE( static_cast<PageState>(value_ret) );
            }

        }
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
                CHANGE_PAGE( static_cast<PageState>(value_ret) );
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
    case ConfigureCNC :
        this->setCentralWidget( new ConfigCNCPage( this ) );
        break;
    case DynamicTest :
        this->setCentralWidget( new DynamicTestPage( this ) );
        break;
    case ScannerLaser :
    {
#if !defined NO_SCAN
 this->setCentralWidget( new FsMainWindow( _polybox->port(), this ) );
#endif
        /*QProcess* laser = new QProcess(this);
        laser->start( Config::scannerLaserPath );*/
        break;
    }
    default:
        break;
        
    }

    _atu->raise();
    _atu->show();
    _atu->activateWindow();
    this->centralWidget()->setEnabled( _atuON );
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
        if ( _polybox->loadJoypad() )
        {
            ui->actionActiver_Manette->setText(tr("Désactiver manette"));
            emit joypadOn( PolyboxModule::getJoypad() );
        }
        else
        {
            return;
        }
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


void MainWindow::on_actionLabView_dock_triggered()
{
    changeStatePage( LabViewDock );
}

void MainWindow::on_actionConsole_triggered()
{
    this->startConsoleWindow();
}

void MainWindow::on_actionParametres_triggered()
{
    DialogConfigSoft dialog( _polybox, (QWidget*)this->parent());
    int value_ret = dialog.exec();
    if ( value_ret != 0 )
    {

    }
}
