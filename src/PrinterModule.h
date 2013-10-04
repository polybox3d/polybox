#ifndef PRINTERMODULE_H
#define PRINTERMODULE_H

#include <QObject>

#include "AbstractModule.h"

class PrinterModule : public QObject, AbstractModule
{
    Q_OBJECT
public:
    explicit PrinterModule(QObject *parent = 0);
    virtual bool isReady() const;
    virtual void updateValues();

signals:

public slots:
private:
    virtual void initAll();

};

#endif // PRINTERMODULE_H
