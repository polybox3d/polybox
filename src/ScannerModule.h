#ifndef SCANNERMODULE_H
#define SCANNERMODULE_H

#include <QObject>


#include "AbstractModule.h"
#include "PolyboxModule.h"
#include "mcode.h"

class ScannerModule : public QObject, public AbstractModule
{
    Q_OBJECT
public:
    explicit ScannerModule(PolyboxModule* polybox, QObject *parent = 0);

    virtual bool isReady() const ;
    virtual void updateComponents();

    bool webcamPlugged() const ;
    bool primesensePlugged() const;
    bool turntablePlugged() const;

protected:
    virtual void initAll();

private:

    bool _webcamPlugged;
    bool _primesencePlugged;
    bool _turntablePlugged;


};

#endif // SCANNERMODULE_H

