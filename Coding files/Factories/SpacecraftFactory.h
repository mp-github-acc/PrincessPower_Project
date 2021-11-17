#ifndef SPACECRAFTFACTORY_H
#define SPACECRAFTFACTORY_H
#include "Dragon.h"
#include "CrewDragon.h"

class SpacecraftFactory{
    private:

    public:
        SpacecraftFactory(){};
        virtual ~SpacecraftFactory(){};
        virtual Spacecraft* createSpacecraft() = 0;
};
#endif