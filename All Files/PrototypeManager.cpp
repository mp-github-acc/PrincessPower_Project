#include "PrototypeManager.h"

PrototypeManager::PrototypeManager(){
    prototypes = new EngineFactory*[2];
    prototypes[0] = new MerlinFactory();
    prototypes[1] = new MerlinVacuumFactory();
    engines = new Engine*[2];
    engines[0] = prototypes[0]->createEngine();
    engines[1] = prototypes[1]->createEngine();
}

PrototypeManager::~PrototypeManager(){
    delete prototypes[0];
    delete prototypes[1];
    delete engines[0];
    delete engines[1];
}


Engine* PrototypeManager::createMerlinEngine()
{
    return engines[0]->clone();
}
Engine* PrototypeManager::createMerlinVacuumEngine()
{
    return engines[1]->clone();
}