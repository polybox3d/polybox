#ifndef CNCMODULE_H
#define CNCMODULE_H

#include <QObject>

#include "AbstractModule.h"

enum CNCType
{
    Noone, Proxxon, Manuel, Unknowed
};


#define DEFAULT_LEVEL_LUB -42.42

class CNCModule : public QObject, AbstractModule
{
    Q_OBJECT
public:
    explicit CNCModule(QObject *parent = 0);
    ~CNCModule();

    virtual bool isReady() const;
    virtual void updateValues();

    bool cncPlugged();
    bool motorLubPlugged();
    float levelLub();
    bool vacuumPlugged();
    CNCType cncType();

signals:

public slots:


private:

    virtual void initAll();

    bool _cncPlugged;
    bool _motorLubPlugged;
    float _levelLub;
    bool _vacuumPlugged;
    CNCType _cncType;

};

#endif // CNCMODULE_H
