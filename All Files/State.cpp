#include "State.h"

void State::handle(){
    cout<<"wrong handle func"<<endl;
}

State* changeCurrentState(string cs);
string getCurrentState();

State(string cs);
~State();