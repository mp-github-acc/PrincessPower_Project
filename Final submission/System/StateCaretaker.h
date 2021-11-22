#ifndef STATECARETAKER_H
#define STATECARETAKER_H

#include <iostream>
using namespace std;
#include "Rocket.h"
#include "SimulationState.h"

class StateCaretaker
{
protected:
    SimulationState* simState;

public:
    StateCaretaker();
    ~StateCaretaker();

    void store(SimulationState* s);
    SimulationState* retrieveState();

};
#endif