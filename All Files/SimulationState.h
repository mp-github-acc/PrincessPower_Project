#ifndef SIMULATIONSTATE_H
#define SIMULATIONSTATE_H
//MEMENTO
#include <iostream>
using namespace std;
// #include "State.h"
#include "StateCaretaker.h"

class SimulationState
{
protected:
    State* state;
    StateCaretaker* caretaker;

    void setStateCaretaker(State* s);
    State* getStateCaretaker();

public:
    SimulationState();
    ~SimulationState();

    State* getState();
    void setState(State* s);
    void beginSimulation();

    


};
#endif