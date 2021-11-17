#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H
#include "../Products/FalconHeavy.h"
#include "../Products/FalconNine.h"

class RocketFacorty{
    public:
        virtual Rocket* creatRocket() = 0;
};
#endif
