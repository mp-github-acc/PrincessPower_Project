#include "StateCaretaker.h"

StateCaretaker::StateCaretaker()
{
    cout << "Created StateCaretaker" << endl;
}
StateCaretaker::~StateCaretaker()
{
    cout << "Deleted StateCaretaker" << endl;
}

void StateCaretaker::store(SimulationState* s){
    simState=s;
}


SimulationState* StateCaretaker::retrieveState(){
    return simState;
}
