#include "DialogConfigSoft.h"
#include "ui_DialogConfigSoft.h"

DialogConfigSoft::DialogConfigSoft(PolyboxModule* poly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfigSoft)
{
    _poly = poly;
    ui->setupUi(this);
    updateValues();
}

DialogConfigSoft::~DialogConfigSoft()
{
    delete ui;
}

void DialogConfigSoft::updateValues()
{
    ui->linuxcncBin->setText( Config::linuxCNCCommand);
    ui->linuxcncDirectory->setText( Config::pathToLinuxCNC);
    ui->pathDev->setText( Config::pathToWebcamDevice);
    ui->homeDirectory->setText( Config::pathToHomeDirectory);
    ui->webcamName->setText( Config::webcamName);
    ui->baudrate->setText( QString::number(Config::motherboardBaudrate) );
    ui->serialDeviceCombo->addItems(SerialPort::getDevicesNames(Config::pathToSerialDevice));
    int index = -1;
    if ( (index = ui->serialDeviceCombo->findText(Config::serialPortName)) != -1)
    {
        ui->serialDeviceCombo->setCurrentIndex( index );
    }
    ui->serialPortPath->setText( Config::pathToSerialDevice );
}

void DialogConfigSoft::on_close_clicked()
{
    this->reject();
}

void DialogConfigSoft::saveValue()
{
    Config::linuxCNCCommand = ui->linuxcncBin->text() ;
    Config::pathToLinuxCNC = ui->linuxcncDirectory->text() ;
    Config::pathToWebcamDevice = ui->pathDev->text();
    Config::pathToHomeDirectory = ui->homeDirectory->text() ;
    Config::webcamName = ui->webcamName->text();
    Config::motherboardBaudrate =  ui->baudrate->text().toInt() ;
    Config::pathToSerialDevice = ui->serialPortPath->text() ;
    Config::serialPortName = ui->serialDeviceCombo->currentText() ;
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
