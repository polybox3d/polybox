#include "DialogConfigSoft.h"
#include "ui_DialogConfigSoft.h"

DialogConfigSoft::DialogConfigSoft(PolyboxModule* poly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfigSoft)
{
    _poly = poly;
    ui->setupUi(this);
    updateValues();
    /** Connect signal/slot button for FOLDER **/
    ui->folderExeCNC->setOpenFile();
    connect(ui->folderExeCNC,SIGNAL(opened(QString)),ui->linuxcncBin,SLOT(setText(QString)));
    connect(ui->folderCNC,SIGNAL(opened(QString)),ui->linuxcncDirectory,SLOT(setText(QString)));

    ui->folderExePrinter->setOpenFile();
    connect(ui->folderExePrinter,SIGNAL(opened(QString)),ui->printersoftBin,SLOT(setText(QString)));
    connect(ui->folderPrinterWorkin,SIGNAL(opened(QString)),ui->printerworkingdir,SLOT(setText(QString)));

    connect(ui->folderHome,SIGNAL(opened(QString)),ui->homeDirectory,SLOT(setText(QString)));
    connect(ui->folderDevices,SIGNAL(opened(QString)),ui->serialPortPath,SLOT(setText(QString)));

    ui->folderVirtDevice->setOpenFile();
    connect(ui->folderVirtDevice,SIGNAL(opened(QString)),ui->virtualDevice,SLOT(setText(QString)));
    ui->folderExePolyPlexer->setOpenFile();
    connect(ui->folderExePolyPlexer,SIGNAL(opened(QString)),ui->polyplexerBin,SLOT(setText(QString)));

}

DialogConfigSoft::~DialogConfigSoft()
{
    delete ui;
}

void DialogConfigSoft::updateValues()
{
    ui->linuxcncBin->setText( Config::linuxCNCCommand);
    ui->linuxcncDirectory->setText( Config::pathToLinuxCNC);
    ui->homeDirectory->setText( Config::pathToHomeDirectory);
    ui->baudrate->setText( QString::number(Config::motherboardBaudrate) );
    ui->serialDeviceCombo->addItems(SerialPort::getDevicesNames(Config::pathToSerialDevice));
    int index = -1;
    if ( (index = ui->serialDeviceCombo->findText(Config::serialPortName)) != -1)
    {
        ui->serialDeviceCombo->setCurrentIndex( index );
    }
    ui->serialPortPath->setText( Config::pathToSerialDevice );

    ui->printersoftBin->setText( Config::pathToPrinterSoftware );
    ui->printerworkingdir->setText( Config::pathToPrinterWorkingDir );

    ui->activateByPass->setChecked( Config::bypassCheck );

    ui->virtualDevice->setText( Config::pathToVirtualPolySerialDevice );
    ui->polyplexerBin->setText( Config::pathToPolyplexerDaemon );

    ui->disablePolyplexer->setChecked( Config::disablePolyplexer );
}

void DialogConfigSoft::on_close_clicked()
{
    this->reject();
}

void DialogConfigSoft::saveValue()
{
    Config::linuxCNCCommand = ui->linuxcncBin->text() ;
    Config::pathToLinuxCNC = ui->linuxcncDirectory->text() ;
    Config::pathToHomeDirectory = ui->homeDirectory->text() ;
    Config::motherboardBaudrate =  ui->baudrate->text().toInt() ;
    Config::pathToSerialDevice = ui->serialPortPath->text() ;
    Config::serialPortName = ui->serialDeviceCombo->currentText() ;

    Config::pathToPrinterSoftware = ui->printersoftBin->text();
    Config::pathToPrinterWorkingDir = ui->printerworkingdir->text();

    Config::bypassCheck = ui->activateByPass->isChecked();

    Config::pathToVirtualPolySerialDevice = ui->virtualDevice->text();
    Config::pathToPolyplexerDaemon = ui->polyplexerBin->text();

    Config::disablePolyplexer = ui->disablePolyplexer->isChecked();
}

void DialogConfigSoft::on_validate_clicked()
{
    saveValue();
    this->done( QDialog::Accepted );
}


void DialogConfigSoft::on_pushButton_clicked()
{
    saveValue();
    QString fileName = QFileDialog::getSaveFileName(this,
                                                     tr("Enregistrer la configuration"),
                                                     "./SavedConfig.xml",
                                                     tr("Config File (*.xml)"));
     if ( fileName != NULL && ! fileName.isEmpty() )
     {
         Config::saveToXmlFile( fileName );
     }
}

void DialogConfigSoft::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Selectionner une configuration"), ".", tr("Config Files (*.xml)"));
    if ( fileName != NULL && ! fileName.isEmpty() )
    {
       Config::importFromXmlFile( fileName );
    }
    updateValues();
}

void DialogConfigSoft::on_saveAsDefault_clicked()
{
    saveValue();
    Config::saveToXmlFile( Config::defaultConfigFileName );
}

void DialogConfigSoft::on_loadFactoryValue_clicked()
{
    Config::importFromXmlFile( INITIAL_CONFIG_FILE );
    updateValues();
}

void DialogConfigSoft::on_disablePolyplexer_clicked()
{

}
