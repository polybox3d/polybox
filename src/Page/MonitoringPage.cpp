#include "MonitoringPage.h"
#include "ui_MonitoringPage.h"

MonitoringPage::MonitoringPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitoringPage)
{
    _currentComputerTick = 0;
    _currentSelfTick = 0;
    ui->setupUi(this);
    connect(ComputerMonitoring::getInstance(),SIGNAL(updateUI()),this, SLOT(updateComputer()));
    connect(SelfMonitoring::getInstance(),SIGNAL(updateUI()),this, SLOT(updateSelf()));

    ui->ramBar->setMaximum(ComputerMonitoring::getInstance()->ramMax());
    ui->ramBar->setValue(0);
    ui->cpuBar->setMaximum(100.0);

    ui->cpuInfo->setText(ComputerMonitoring::getInstance()->getCPUInfo());

    initializeComputerGraphs();
    initializeSelfGraphs();
    initializeSelfInfos();

    /*foreach (QString label, ComputerMonitoring::getInstance()->diskLabel())
    {
        ui->diskBox->addItem(label);
    }*/

}

void MonitoringPage::initializeComputerGraphs()
{

    /** generate graphs **/
    /** RAM **/
    QVector<double> ramY = ComputerMonitoring::getInstance()->ramHistory;
    _currentComputerTick = ramY.count();
    for( int i = 0 ; i < _currentComputerTick ; ++i )
    {
        ramY[i] = (double)ramY[i] / (double) ComputerMonitoring::getInstance()->ramMax() *100.0 ;
    }
    QVector<double> xAxis = generateXAxis( _currentComputerTick );

    ui->ramPlot->addGraph();

    ui->ramPlot->graph(0)->setData( xAxis, ramY );
    ui->ramPlot->xAxis->setLabel("m");
    ui->ramPlot->yAxis->setLabel("%");
    ui->ramPlot->graph(0)->setBrush(QBrush(QColor(130,160,255,128) ));
    ui->ramPlot->yAxis->setRange(0,100);


    ui->ramPlot->replot();
    /** CPU **/
    ui->cpuPlot->addGraph();
    QVector<double> cpuY = ComputerMonitoring::getInstance()->cpuHistory;
    ui->cpuPlot->graph(0)->setData( xAxis, cpuY );

    ui->cpuPlot->xAxis->setLabel("m");
    ui->cpuPlot->yAxis->setLabel("%");
    ui->cpuPlot->graph(0)->setBrush(QBrush(QColor(255,90,90,128) ));
    ui->cpuPlot->graph(0)->setPen(QPen(QColor(255,90,90) ));
    ui->cpuPlot->yAxis->setRange(0,100);

    ui->cpuPlot->replot();
}
void MonitoringPage::initializeSelfInfos()
{
    ui->softwareVersion->setText( QCoreApplication::applicationVersion() );
    ui->frameworkVersion->setText( QT_VERSION_STR );
}

void MonitoringPage::initializeSelfGraphs()
{

    /** generate graphs **/
    /** RAM **/
    QVector<double> ramY = SelfMonitoring::getInstance()->ramHistory;
    _currentSelfTick = ramY.count();
    QVector<double> xAxis = generateXAxis( _currentSelfTick );

    ui->ramSelfPlot->addGraph();
    ui->ramSelfPlot->graph(0)->setData( xAxis, ramY );

    ui->ramSelfPlot->xAxis->setLabel("m");
    ui->ramSelfPlot->yAxis->setLabel("%");
    ui->ramSelfPlot->graph(0)->setBrush(QBrush(QColor(95,255,135,128) ));
    ui->ramSelfPlot->graph(0)->setPen(QPen(QColor(95,255,135)  ));
    ui->ramSelfPlot->yAxis->setRange(0,100);

    ui->ramSelfPlot->replot();
    /** CPU **/
    ui->cpuSelfPlot->addGraph();
    QVector<double> cpuY = SelfMonitoring::getInstance()->cpuHistory;
    ui->cpuSelfPlot->graph(0)->setData( xAxis, cpuY );

    ui->cpuSelfPlot->xAxis->setLabel("m");
    ui->cpuSelfPlot->yAxis->setLabel("%");
    ui->cpuSelfPlot->graph(0)->setBrush(QBrush(QColor(255,90,90,128) ));
    ui->cpuSelfPlot->graph(0)->setPen(QPen(QColor(255,90,90) ));
    ui->cpuSelfPlot->yAxis->setRange(0,100);

    ui->cpuSelfPlot->replot();
}

QVector<double> MonitoringPage::generateXAxis(int items)
{
    QVector<double> data;
    for( int i=0 ; i < items ; i++ )
    {
        data.append( i/60.0 );
    }
    return data;
}

void MonitoringPage::updateComputer()
{
    _currentComputerTick++;
    ui->ramBar->setValue(ComputerMonitoring::getInstance()->ramCurrent());
    ui->ramDisplay->setText( QString::number(ComputerMonitoring::getInstance()->ramCurrent()/(1000.0*1000.0),'g',2)
                             +" GB / "
                             + QString::number(ComputerMonitoring::getInstance()->ramMax()/(1000.0*1000.0),'g',2)
                             +" GB"
                             );
    ui->ramPlot->graph(0)->addData( _currentComputerTick/60.0, ((double)ComputerMonitoring::getInstance()->ramCurrent()/(double)ComputerMonitoring::getInstance()->ramMax() *100.0) );
    ui->ramPlot->xAxis->rescale(true);
    ui->ramPlot->replot();

    ui->cpuPlot->graph(0)->addData( _currentComputerTick/60.0, (double)ComputerMonitoring::getInstance()->cpu());
    ui->cpuPlot->xAxis->rescale(true);
    ui->cpuPlot->replot();

    ui->cpuBar->setValue(ComputerMonitoring::getInstance()->cpu());

    _currentComputerTick++;
}

void MonitoringPage::updateSelf()
{
    _currentSelfTick++;
    ui->ramSelfDisplay->setText( QString::number(SelfMonitoring::getInstance()->ramUsed() * (double)ComputerMonitoring::getInstance()->ramMax()/(100.0*(1000.0*1000.0)),'g',3)
                             +" GB / "
                             + QString::number(ComputerMonitoring::getInstance()->ramMax()/(1000.0*1000.0),'g',4)
                             +" GB"
                             );
    ui->ramSelfBar->setValue(SelfMonitoring::getInstance()->ramUsed());

    ui->ramSelfPlot->graph(0)->addData( _currentSelfTick/60.0, (double)SelfMonitoring::getInstance()->ramUsed() );
    ui->ramSelfPlot->xAxis->rescale(true);
    ui->ramSelfPlot->replot();

    ui->cpuSelfPlot->graph(0)->addData( _currentSelfTick/60.0, (double)SelfMonitoring::getInstance()->cpuUsed());
    ui->cpuSelfPlot->xAxis->rescale(true);
    ui->cpuSelfPlot->replot();

    ui->cpuSelfBar->setValue(SelfMonitoring::getInstance()->cpuUsed());

    _currentSelfTick++;
}

MonitoringPage::~MonitoringPage()
{
    delete ui;
}
