#ifndef SPACESTATION_H
#define SPACESTATION_H
#include <iostream>
using namespace std;
#include <list>//ur mom
#include "Spacecraft.h"
//Adapter SpaceStation.h
//Target Rocket.h
//Adaptee SpaceCraft.h


class SpaceStation{
    protected:
        list<Spacecraft*> dockedSpacecraft;
    public:
        SpaceStation();
        ~SpaceStation();

        void addSpacecraft(Spacecraft* s);
        Spacecraft* removeSpacecraft(Spacecraft* s);
};
#endif