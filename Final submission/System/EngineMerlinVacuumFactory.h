#ifndef MERLINVACUUMFACTORY_H
#define MERLINVACUUMFACTORY_H

#include "EngineFactory.h"
#include "EngineMerlinVacuum.h"

class MerlinVacuumFactory : public EngineFactory
{
private:
public:
        MerlinVacuumFactory();
        ~MerlinVacuumFactory();
        Engine *createEngine();
};
#endif
