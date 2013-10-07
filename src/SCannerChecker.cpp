#include "SCannerChecker.h"
#include "ui_SCannerChecker.h"

SCannerChecker::SCannerChecker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SCannerChecker)
{
    _scanner = NULL;
    ui->setupUi(this);
}

SCannerChecker::SCannerChecker(ScannerModule* scanner, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SCannerChecker)
{
    _scanner = scanner;
    _currentModule = scanner;
    ui->setupUi(this);
}


void SCannerChecker::paintEvent(QPaintEvent *)
{
    if ( _scanner == NULL )
    {
        return;
    }
    else
    {
        ui->webcamPlugLed->setActivated( _scanner->webcamPlugged() );
        ui->turntableLed->setActivated( _scanner->turntablePlugged() );
        ui->turntableLed_2->setActivated( _scanner->turntablePlugged() );
        ui->primesencePlugLed->setActivated( _scanner->primesensePlugged() );
    }
}

SCannerChecker::~SCannerChecker()
{
    delete ui;
}
