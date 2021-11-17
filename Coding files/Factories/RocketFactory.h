#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H
#include "Rocket.h"

class RocketFacorty{
    public:
        virtual Rocket* creatRocket() = 0;
};
#endif
