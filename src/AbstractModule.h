#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

//#include "PolyboxModule.h"

#include <iostream>
using namespace std;

class AbstractModule
{
public:
    AbstractModule(){ initAll();}
    virtual ~AbstractModule(){ }

    virtual bool isReady() const = 0;
    virtual void updateValues()=0;

protected:
    virtual void initAll(){ }
private:
 //   PolyboxModule* _polybox;
};

#endif // ABSTRACTMODULE_H
