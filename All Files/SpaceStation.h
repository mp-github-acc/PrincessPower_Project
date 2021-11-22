#ifndef SPACESTATION_H
#define SPACESTATION_H
#include <iostream>
using namespace std;

#include <list>
#include "Spacecraft.h"

//Target Rocket.h
//Adaptee SpaceCraft.h


class SpaceStation{
    protected:
        list<Spacecraft*> dockedSpacecraft;
    public:
        SpaceStation();
        ~SpaceStation();

        bool contains(Spacecraft* s);

        void addSpacecraft(Spacecraft* s);
        Spacecraft* removeSpacecraft(Spacecraft* s);
};
#endif