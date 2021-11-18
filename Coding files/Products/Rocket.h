#include <iostream>
#include "../Satellites.cpp"
#include "../Factories/SpacecraftFactory.h"
#include "Engine.h"
#include <list>
using namespace std;


class Rocket
{
protected:
    Spacecraft* spacecraft_;
    string rocketName;
    StarLink* cluster_;
    list<Engine*> engines;
public:
    Rocket();
    virtual ~Rocket();
    void setRocketName(string s);
    string getRocketName();
    void addSpacecraft();
    void addSatellites();
    virtual void addEngines();
    bool buildComplete();
};

