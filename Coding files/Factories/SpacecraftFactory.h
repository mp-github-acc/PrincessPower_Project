#ifndef SPACECRAFTFACTORY_H
#define SPACECRAFTFACTORY_H
#include "../Products/CrewDragon.h"
#include "../Products/Dragon.h"

class SpacecraftFactory{
    private:

    public:
        SpacecraftFactory(){};
        virtual ~SpacecraftFactory(){};
        virtual Spacecraft* createSpacecraft() = 0;
};
#endif