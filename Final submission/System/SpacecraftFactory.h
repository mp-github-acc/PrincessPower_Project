#ifndef SPACECRAFTFACTORY_H
#define SPACECRAFTFACTORY_H
#include "SpacecraftCrewDragon.h"
#include "SpacecraftDragon.h"

class SpacecraftFactory
{
private:
public:
    SpacecraftFactory();
    virtual ~SpacecraftFactory();
    virtual Spacecraft *createSpacecraft() = 0;
};
#endif