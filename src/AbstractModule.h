#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include <iostream>
using namespace std;

#include "PolyboxModule.h"


class AbstractModule
{
public:
    AbstractModule(PolyboxModule* polybox){ _polybox = polybox; initAll();}
    virtual ~AbstractModule(){ }

    virtual bool isReady() const = 0;
    virtual void updateComponents() =0;


protected:
    virtual void initAll(){ }
    PolyboxModule* _polybox;
private:

};

#endif // ABSTRACTMODULE_H
