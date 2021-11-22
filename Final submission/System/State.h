#ifndef STATE_H
#define STATE_H
// #include <string>
#include <iostream>
using namespace std;

class State
{
protected:
    string currentState;

public:
    State();
    virtual ~State();
    virtual void handle() = 0;
    virtual State *changeState() = 0;
    string getCurrentState();
    
};
#endif