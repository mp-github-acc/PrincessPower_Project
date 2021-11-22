#ifndef ROCKETFACTORY_H
#define ROCKETFACTORY_H
#include "RocketFalconHeavy.h"
#include "RocketFalconNine.h"
#include "Rocket.h"
#include <iostream>
using namespace std;
class RocketFactory
{
public:
    RocketFactory();
    virtual ~RocketFactory();
    virtual Rocket* createRocket() = 0;
    // virtual void createRocket() = 0;
};
#endif
