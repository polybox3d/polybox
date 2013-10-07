#ifndef ABSTRACTCHECKER_H
#define ABSTRACTCHECKER_H

#include "AbstractModule.h"
#include "ScannerModule.h"
#include "CNCModule.h"
#include <iostream>
#include <QWidget>

class AbstractChecker : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractChecker(  QWidget* parent=0): QWidget(parent) { _currentModule = NULL; }
    virtual ~AbstractChecker(){}
    virtual void setModule( AbstractModule* module ){
        _currentModule = module;
    }

    virtual void updateModuleValues() {}

protected:
    AbstractModule* _currentModule;
};

#endif // ABSTRACTCHECKER_H
