#ifndef MERLINVACUUMFACTORY_H
#define MERLINVACUUMFACTORY_H

#include "EngineFactory.h"

class MerlinVacuumFactory : public EngineFactory
{
private:
public:
        MerlinVacuumFactory();
        ~MerlinVacuumFactory();
        Engine *createEngine();
};
#endif
