#ifndef PROTOTYPEMANAGER_H
#define PROTOTYPEMANAGER_H

#include <iostream>
#include "EngineMerlinFactory.h"
#include "EngineMerlinVacuumFactory.h"
using namespace std;

class PrototypeManager
{
private:
    EngineFactory** prototypes;
    Engine** engines;
public:
    PrototypeManager();
    ~PrototypeManager();

    Engine* createMerlinEngine();
    Engine* createMerlinVacuumEngine();

};
#endif
