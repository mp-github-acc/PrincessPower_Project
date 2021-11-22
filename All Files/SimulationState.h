#ifndef SIMULATIONSTATE_H
#define SIMULATIONSTATE_H
//MEMENTO
#include <iostream>
using namespace std;
#include "StateRocket.h"


class SimulationState
{
protected:
    StateRocket *Rstate;
    // friend class Rocket();
    // SimulationState(string n);

public:
    SimulationState();
    SimulationState(string n, string s, bool b, string st);
    virtual ~SimulationState();

    StateRocket *getRState();
    void setRState(StateRocket *s);
    // void beginSimulation();
};
#endif