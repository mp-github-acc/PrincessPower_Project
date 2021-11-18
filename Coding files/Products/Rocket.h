#ifndef ROCKET_H
#define ROCKET_H
#include <iostream>
// #include "Satellite.h"
// #include "../Factories/SpacecraftFactory.h"
// #include "Engine.h"
#include <list>
using namespace std;

class Rocket
{
protected:
    // Spacecraft* spacecraft_;
    string rocketName;
    // StarLink* satelliteCluster;
    // list<Engine*> engines;
public:
    Rocket();
    virtual ~Rocket();
    // void setRocketName(string s);
    // string getRocketName();
    // // void addSpacecraft();
    // void addSatellites();
    // virtual void addEngines();
    // bool buildComplete();
};
#endif

