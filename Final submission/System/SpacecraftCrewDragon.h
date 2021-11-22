#ifndef CREWDRAGON_H
#define CREWDRAGON_H
#include "Spacecraft.h"

class CrewDragon : public Spacecraft{
    public:
        CrewDragon();
        ~CrewDragon();
        void sendCargo();
};
#endif
