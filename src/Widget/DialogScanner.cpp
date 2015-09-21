#include "DialogScanner.h"
#include "ui_DialogScanner.h"

DialogScanner::DialogScanner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogScanner)
{
    ui->setupUi(this);
}

DialogScanner::~DialogScanner()
{
    delete ui;
}

/*void DialogScanner::on_laser_clicked()
{
    this->done( ScannerLaser );
}

void DialogScanner::on_primesense_clicked()
{
    this->done( ScannerPrimesense );
}*/

void DialogScanner::on_close_clicked()
{
    this->reject();
}

void DialogScanner::on_goBackHelp_clicked()
{
    this->done( Help );
}

void DialogScanner::on_horus_clicked()
{
    this->done( Horus );
}

void DialogScanner::on_fabscan_clicked()
{
    this->done( FabScan );
}
