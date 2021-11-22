#ifndef STATEROCKET_H
#define STATEROCKET_H

#include <iostream>
using namespace std;


class StateRocket
{
protected:
    string name;
    string spacecraft;
    bool hasSatellites;
    string stage;


public:
    StateRocket(string n, string s, bool b, string st);
    ~StateRocket();

    string getName();
    string getSpacecraft();
    bool getBool();
    string getStage();




//ROCKET STUFF
// private:
//     AbstractMissionControl *observer;

// protected:
//     Spacecraft *spacecraft_;
//     string rocketName;
//     StarLink *satelliteCluster;
//     list<Engine *> engines;
//     State *currentStage; // rename this to be more specific
//     EngineFactory **engineFactory;

//     Rocket *succesor;

// public:
//     Rocket();
//     virtual ~Rocket();
//     void setRocketName(string s);
//     string getRocketName();
//     void addSpacecraft(Spacecraft *s);
//     void addSatellites(int c);
//     virtual void addEngine()=0;
//     bool staticFire();
//     // Command
//     void accelerate();
//     void decelerate();
//     void ignite();
//     void attach();
//     void dock();
//     Spacecraft *getSpacecraft();
//     // Observer
//     void implementObsever();
//     void setCondition(bool b);

//     // State
//     void addState(State *s);
//     void changeStage();

//     // Chain of Responsibility
//     virtual void handleRequest(string n) = 0;
//     virtual void setNext(Rocket* r) = 0;


//     SimulationState *createMemento();
//     void makeMemento(SimulationState *m);


};
#endif