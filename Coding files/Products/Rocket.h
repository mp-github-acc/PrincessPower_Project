#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>

#include "../Satellite.cpp"
#include "../Factories/SpacecraftFactory.h"
// #include "Engine.h"
#include <list>
using namespace std;
#include "../State/State.h"
#include "../SimulationState.h"


class Rocket
{
protected:
    // Spacecraft* spacecraft_;
    string rocketName;
    // StarLink* satelliteCluster;
    // list<Engine*> engines;

    // 
    State* state;
    Satellite* satellite;


public:
    Rocket();
    virtual ~Rocket();

    void setRocketName(string s);
    string getRocketName();
    void addSpacecraft();
    void addSatellites();
    virtual void addEngines();
    bool buildComplete();

    // 
    
    void checkOne();
    void checkTwo();
    SimulationState* createSimState();
    SimulationState* getSimState();
    void handleRequest();
    void startEngine();
    void accelerate();
    void decelerate();
    void staticFire();

};
#endif

