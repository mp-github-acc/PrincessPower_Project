#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H
#include "../Products/FalconHeavy.h"
#include "../Products/FalconNine.h"

class RocketFactory{
    public:
        RocketFactory();
        virtual Rocket* createRocket() = 0;
};
#endif
