#ifndef FALCONNINEFACTORY_H
#define FALCONNINEFACTORY_H
#include "RocketFactory.h"
class FalconNineFactory : public RocketFacorty{
    public:
        Rocket* creatRocket();
};
#endif