#include "SpacecraftDragonFactory.h"


DragonFactory::DragonFactory(){}
DragonFactory::~DragonFactory(){}

Spacecraft *DragonFactory::createSpacecraft()
{
    return new Dragon();
}