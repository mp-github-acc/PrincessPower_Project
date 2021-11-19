#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H
#include "Merlin.h"
#include "MerlinVacuum.h"

class EngineFactory{
    private:

    public:
        EngineFactory();
        virtual ~EngineFactory();
        virtual Engine* createEngine() = 0;
};
#endif