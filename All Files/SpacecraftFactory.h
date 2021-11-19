#ifndef SPACECRAFTFACTORY_H
#define SPACECRAFTFACTORY_H
#include "CrewDragon.h"
#include "Dragon.h"

class SpacecraftFactory
{
private:
public:
    SpacecraftFactory();
    virtual ~SpacecraftFactory();
    virtual Spacecraft *createSpacecraft() = 0;
};
#endif