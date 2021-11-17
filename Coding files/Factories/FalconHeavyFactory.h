#ifndef FALCONHEAVYFACTORY_H
#define FALCONHEAVYFACTORY_H
#include "RocketFactory.h"

class FalconHeavyFactory : public RocketFacorty{
    public:
        Rocket* creatRocket();
};
#endif