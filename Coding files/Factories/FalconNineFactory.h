#ifndef FALCONNINEFACTORY_H
#define FALCONNINEFACTORY_H
#include "RocketFactory.h"
class FalconNineFactory : public RocketFactory{
    public:
        Rocket* createRocket();
};
#endif