#include "DragonFactory.h"
Spacecraft *DragonFactory::createSpacecraft()
{
    return new Dragon();
}