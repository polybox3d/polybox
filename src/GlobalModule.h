#ifndef GLOBALMODULE_H
#define GLOBALMODULE_H

#include <QObject>

#include "MainWindow.h"
#include "AbstractModule.h"
#include "Temperature.h"

class GlobalModule : public QObject, public AbstractModule
{
    Q_OBJECT
public:
    explicit GlobalModule(PolyboxModule* polybox, QObject *parent = 0);

    virtual bool isReady() const ;
    virtual void updateComponents() const;


    bool boxOpen() const;
    bool ATUok() const;
    bool arduino1() const;
    bool arduino2() const;
    bool arduino3() const;
    bool arduino4() const;
    bool command() const;
    bool power() const;
    bool webcamPlugged() const;

    Temperature tempIC();

signals:

public slots:

protected:
    void initAll();
private:
    bool _boxOpen;
    bool _ATUok;
    bool _arduino1;
    bool _arduino2;
    bool _arduino3;
    bool _arduino4;
    bool _command;
    bool _power;
    bool _webcamPlugged;

    Temperature _tempIC;
    ///tempIC
};

#endif // GLOBALMODULE_H
