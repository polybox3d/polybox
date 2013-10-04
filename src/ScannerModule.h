#ifndef SCANNERMODULE_H
#define SCANNERMODULE_H

#include <QObject>


#include "AbstractModule.h"

class ScannerModule : public QObject, AbstractModule
{
    Q_OBJECT
public:
    explicit ScannerModule(QObject *parent = 0);

    virtual bool isReady() const ;
    virtual void updateValues();

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

