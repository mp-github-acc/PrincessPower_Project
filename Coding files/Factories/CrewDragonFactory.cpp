#include "CrewDragonFactory.h"

Spacecraft *CrewDragonFactory::createSpacecraft()
{
    return new CrewDragon();
}