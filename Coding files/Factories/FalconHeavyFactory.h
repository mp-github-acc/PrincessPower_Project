#ifndef FALCONHEAVYFACTORY_H
#define FALCONHEAVYFACTORY_H
#include "RocketFactory.h"

class FalconHeavyFactory : public RocketFactory{
    public:
        Rocket* createRocket();
};
#endif