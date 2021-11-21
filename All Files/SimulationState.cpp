#include "SimulationState.h"

SimulationState::SimulationState(){
    cout<<"Created SimulationState"<<endl;
}
SimulationState::~SimulationState(){
    cout<<"Deleted SimulationState"<<endl;
}

// State* SimulationState::getState(){
//     return this->state;
// }
// void SimulationState::setState(State* s){
//     this->state=s;
// }
// void SimulationState::beginSimulation(){
//     cout<<"Beginning simulation"<<endl;
// }

// void SimulationState::setStateCaretaker(State* s){
//     this->caretaker->setStateCaretaker(s);
// }
// State* SimulationState::getStateCaretaker(){
//     return this->caretaker->getStateCaretaker();
// }