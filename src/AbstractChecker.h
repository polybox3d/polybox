#ifndef ABSTRACTCHECKER_H
#define ABSTRACTCHECKER_H

#include "AbstractModule.h"
#include "ScannerModule.h"
#include "CNCModule.h"
#include <iostream>

class AbstractChecker
{
public:
    AbstractChecker(){ _currentModule = NULL;}
    virtual ~AbstractChecker(){}

    void updateModuleValues(){
    }

protected:
    AbstractModule* _currentModule;
};

#endif // ABSTRACTCHECKER_H
