#ifndef MERLINFACTORY_H
#define MERLINFACTORY_H

#include "EngineFactory.h"

class MerlinFactory : public EngineFactory
{
private:
public:
        MerlinFactory();
        ~MerlinFactory();
        Engine *createEngine();
};
#endif
