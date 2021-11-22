#ifndef ENGINEFACTORY_H
#define ENGINEFACTORY_H

#include "Engine.h"

class EngineFactory{
    private:

    public:
        EngineFactory();
        virtual ~EngineFactory();
        virtual Engine* createEngine() = 0;
};
#endif