#ifndef ABSTRACTCHECKER_H
#define ABSTRACTCHECKER_H

#include "AbstractModule.h"
#include "ScannerModule.h"
#include "CNCModule.h"
#include <iostream>

class AbstractChecker
{
public:
    AbstractChecker( AbstractModule* module=NULL ){ _currentModule = module; }
    virtual ~AbstractChecker(){}
    virtual void setModule( AbstractModule* module ){
        _currentModule = module;
    }

    void updateModuleValues(){

    }

protected:
    AbstractModule* _currentModule;
};

#endif // ABSTRACTCHECKER_H
