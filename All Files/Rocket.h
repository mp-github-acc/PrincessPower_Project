#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>

// // Satellites
#include "Satellite.h"
#include "Cluster.h"
#include "StarLink.h"

// // Spacecraft
#include "Spacecraft.h"
#include "CrewDragon.h"
#include "Dragon.h"
// #include "../Factories/SpacecraftFactory.h"
// #include "../State/State.h"
// #include "../SimulationState.h"
// #include "Engine.h"
#include <list>
using namespace std;

class Rocket
{
protected:
    Spacecraft* spacecraft_;
    string rocketName;
    StarLink *satelliteCluster;
    // list<Engine*> engines;
    // State* state;
public:
    Rocket();
    virtual ~Rocket();
    void setRocketName(string s);
    string getRocketName();
    void addSpacecraft(Spacecraft* s);
    void addSatellites(int c);
    // // virtual void addEngines();
    bool staticFire();

    // void checkOne();
    // void checkTwo();
    // // SimulationState* createSimState();
    // // SimulationState* getSimState();
    // void handleRequest();
    // void startEngine();
    // void accelerate();
    // void decelerate();
    // void staticFire();
};
#endif
