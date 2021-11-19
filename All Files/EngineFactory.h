#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H
#include "EngineMerlin.h"
#include "EngineMerlinVacuum.h"

class EngineFactory{
    private:

    public:
        EngineFactory();
        virtual ~EngineFactory();
        virtual Engine* createEngine() = 0;
};
#endif