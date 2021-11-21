#ifndef STATE_H
#define STATE_H
using namespace std;
#include <iostream>
#include <string>

class State{
    protected:
    string currentState;

    public:
        virtual void handle();//=0

        State* changeCurrentState(string cs);
        string getCurrentState();

        State(string cs);
        ~State();
        
};
#endif