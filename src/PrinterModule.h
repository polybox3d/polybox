#ifndef PRINTERMODULE_H
#define PRINTERMODULE_H

#include <QObject>

#include "AbstractModule.h"
#include "Temperature.h"

#include "PolyboxModule.h"
#include "mcode.h"

class PrinterModule : public QObject, public AbstractModule
{
    Q_OBJECT
public:
#define BED_1 1
#define BED_2 2
#define BED_3 4
#define BED_4 8
    explicit PrinterModule(PolyboxModule* polybox, QObject *parent = 0);
    virtual bool isReady() const;
    virtual void updateComponents();

    void setTargetBedTemp( const Temperature &temp);
    Temperature getTargetBedTemp();

    void setTargetChamberTemp( const Temperature &temp );
    Temperature getTargetChamberTemp();
    int getSelectedBed();
    void addSupprBed( int bed_mask );
    void activateAllBed( bool activated );

    Temperature tempTopBuse1();
    Temperature tempBotBuse1();
    Temperature tempTopBuse2();
    Temperature tempBotBuse2();

    Temperature tempBoxTop();
    Temperature tempBoxMiddle();
    Temperature tempBoxBot();

    Temperature tempBedMid();
    Temperature tempBedExt();

    Temperature coldBox1();
    Temperature coldBox2();
    Temperature coldBox3();
    Temperature coldBox4();

    Temperature coldBuse1();
    Temperature coldBuse2();

    bool printerPlugged() const;
    bool wireClogged() const;
    bool detectPlastic() const;
    bool bedPlugged() const;

    PolyboxModule* getPolybox(){ return _polybox; }

    virtual void parseMCode(QByteArray stream);

signals:
    void updateUI();

public slots:
private:
    virtual void initAll();
    Temperature _targetBedTemp;
    Temperature _targetChamberTemp;

    Temperature _tempTopBuse1;
    Temperature _tempBotBuse1;
    Temperature _tempTopBuse2;
    Temperature _tempBotBuse2;

    Temperature _tempBoxTop;
    Temperature _tempBoxMiddle;
    Temperature _tempBoxBot;

    Temperature _tempBedMid;
    Temperature _tempBedExt;

    Temperature _coldBox1;
    Temperature _coldBox2;
    Temperature _coldBox3;
    Temperature _coldBox4;

    Temperature _coldBuse1;
    Temperature _coldBuse2;

    bool _wireClogged;
    bool _printerPlugged;
    bool _detectPlastic;
    bool _bedPlugged;
    int _selectedBed;

};

#endif // PRINTERMODULE_H
