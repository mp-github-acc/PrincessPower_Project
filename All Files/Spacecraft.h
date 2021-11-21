#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <iostream>
using namespace std;

#include "State.h"
#include "SimulationState.h" 

//Crew Dragon - humans and cargo
//Dragon - cargo only

class Spacecraft
{
protected:
    string name;
    State* currentState;


public:
    Spacecraft();
    virtual ~Spacecraft();
    virtual string getName();
    virtual void sendCargo() = 0;
    void setName(string n);
    // Memento
    // SimulationState* createMemento();
    // void setMemento(SimulationState* memento);
    
};
#endif