#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>
#include <string>
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

static const string Falcon9Engines[] = {"Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin Vacuum"};
static const string FalconHeavyEngines[] = {"Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin", "Merlin Vacuum"};
//Prototype
#include "PrototypeManager.h"
// #include <list>
using namespace std;

class Rocket
{
private:
    AbstractMissionControl *observer;

protected:
    Spacecraft *spacecraft_;
    string rocketName;
    StarLink *satelliteCluster;
    list<Engine *> engines;
    State *currentStage; // rename this to be more specific
    // EngineFactory **engineFactory; // not sure we need this anymore...
    Rocket *succesor; //Chain of repsonsibility

    PrototypeManager *pm; //engines
    // engine checklist
public:
    Rocket();
    virtual ~Rocket();
    string getRocketName();
    void addSatellites(int c);
    virtual void addSpacecraft(Spacecraft *s) = 0;
    virtual void setRocketName(string s) = 0;
    virtual void addEngine() = 0;
    virtual Spacecraft *getSpacecraft() = 0;
    StarLink *getSatellite();
    bool staticFire();

    // Command
    virtual void accelerate() = 0;
    virtual void decelerate() = 0;
    virtual void ignite() = 0;
    virtual void attach() = 0;
    virtual void dock() = 0;

    // Observer
    void implementObsever();
    void setCondition(bool b);
    // bool setCondition(bool b);
    // bool hasSatellites(){
    //     if(satelliteCluster != NULL){
    //         return true;
    //     }
    //     return false;
    // }

    // State
    void addState(State *s);
    void changeStage();

    // Chain of Responsibility
    virtual void handleRequest(string n, bool c) = 0;
    virtual void setNext(Rocket *r) = 0;
    // void checkOne();
    // void checkTwo();

    // void handleRequest();
    // void startEngine();
    // void staticFire();

    SimulationState *createMemento();
    void makeMemento(SimulationState *m);

    void printInformation();
};
#endif
