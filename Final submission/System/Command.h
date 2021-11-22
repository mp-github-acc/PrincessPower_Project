#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include "Rocket.h"
#include "Spacecraft.h"
using namespace std;

class Command{
    protected:
        Rocket* rocket_;            // to control a rocket
        Spacecraft* spacecraft_;    // to control a spacecraft
    public:
        Command(Rocket* r, Spacecraft* s);
        virtual ~Command();
        Rocket* getRocket();
        Spacecraft* getSpacecraft();
        virtual void execute() = 0;
};
#endif