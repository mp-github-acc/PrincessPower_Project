#include "EngineMerlinVacuumFactory.h"

MerlinVacuumFactory::MerlinVacuumFactory() {}
MerlinVacuumFactory::~MerlinVacuumFactory() {}
Engine *MerlinVacuumFactory::createEngine()
{
    return new MerlinVacuum();
}
