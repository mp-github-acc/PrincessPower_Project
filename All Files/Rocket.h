#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>

// Satellites
#include "StarLinkSatellite.h"
#include "StarLinkCluster.h"
#include "StarLink.h"

// // Spacecraft
#include "Spacecraft.h"
#include "SpacecraftCrewDragon.h"
#include "SpacecraftDragon.h"
// #include "../Factories/SpacecraftFactory.h"
// #include "../State/State.h"
// #include "../SimulationState.h"
// #include "Engine.h"

// Observer
#include "ObserverAbstractMissionControl.h"
#include "ObserverConcreteMissionControl.h"
// Memento
#include "State.h"
#include "SimulationState.h" 

// #include <list>
using namespace std;

class Rocket
{
private:
    AbstractMissionControl* observer;
protected:
    Spacecraft *spacecraft_;
    string rocketName;
    StarLink *satelliteCluster;
    // list<Engine*> engines;
    State *currentState; // rename this to be more specific
public:
    Rocket();
    virtual ~Rocket();
    void setRocketName(string s);
    string getRocketName();
    void addSpacecraft(Spacecraft *s);
    void addSatellites(int c);
    // // virtual void addEngines();
    bool staticFire();
    // Command
    void accelerate();
    void decelerate();
    void ignite();
    void attach();
    void dock();
    Spacecraft *getSpacecraft();
    // Observer
    void implementObsever();
    void setCondition(bool b);
    // void checkOne();
    // void checkTwo();
    // // SimulationState* createSimState();
    // // SimulationState* getSimState();
    // void handleRequest();
    // void startEngine();
    // void staticFire();

    SimulationState *createMemento();
    void setMemento(SimulationState *memento);
};
#endif
