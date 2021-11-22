#include "SimulationState.h"

SimulationState::SimulationState(){
    // cout<<"Created SimulationState"<<endl;
}
SimulationState::~SimulationState(){
    // cout<<"Deleted SimulationState"<<endl;
}

// SimulationState::SimulationState(string n){

// }

StateRocket* SimulationState::getRState(){
    return Rstate;
}

void SimulationState::setRState(StateRocket *s){
    Rstate=s;
}

SimulationState::SimulationState(string n, string s, bool b, string st){
    Rstate=new StateRocket(n,s,b, st);
}