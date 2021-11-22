#ifndef CREWDRAGONFACTORY_H
#define CREWDRAGONFACTORY_H

#include "SpacecraftFactory.h"

class CrewDragonFactory : public SpacecraftFactory
{
private:
public:
    CrewDragonFactory();
    ~CrewDragonFactory();
    Spacecraft *createSpacecraft();
};
#endif
