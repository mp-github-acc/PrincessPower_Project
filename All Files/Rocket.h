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

//Engine
#include "EngineMerlinFactory.h"
#include "EngineMerlinVacuumFactory.h"

// Observer
#include "ObserverAbstractMissionControl.h"
#include "ObserverConcreteMissionControl.h"
// Memento
#include "SimulationState.h" 

// State
#include "State.h"
#include "Stage_Grounded.h"
#include "Stage_One.h"
#include "Stage_Two.h"
#include "Stage_Orbit.h"
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
    list<Engine*> engines;
    State *currentStage; // rename this to be more specific
public:
    Rocket();
    virtual ~Rocket();
    void setRocketName(string s);
    string getRocketName();
    void addSpacecraft(Spacecraft *s);
    void addSatellites(int c);
    virtual void addEngine();
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

    // State
    void addState(State* s);
    void changeStage();
    // void checkOne();
    // void checkTwo();
    // // SimulationState* createSimState();
    // // SimulationState* getSimState();
    // void handleRequest();
    // void startEngine();
    // void staticFire();

    // SimulationState *createMemento();
    // void setMemento(SimulationState *memento);
};
#endif
