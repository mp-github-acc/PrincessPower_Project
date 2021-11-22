#include "EngineMerlinFactory.h"

MerlinFactory::MerlinFactory() {}
MerlinFactory::~MerlinFactory() {}
Engine *MerlinFactory::createEngine()
{
    return new Merlin();
}
