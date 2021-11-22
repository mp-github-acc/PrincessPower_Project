#include "SpacecraftCrewDragonFactory.h"
CrewDragonFactory::CrewDragonFactory(){}
CrewDragonFactory::~CrewDragonFactory(){}
Spacecraft *CrewDragonFactory::createSpacecraft()
{
    return new CrewDragon();
}