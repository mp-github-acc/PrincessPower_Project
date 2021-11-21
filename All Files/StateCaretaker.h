#ifndef STATECARETAKER_H
#define STATECARETAKER_H

#include <iostream>
using namespace std;
#include "State.h"

class StateCaretaker
{
protected:
    State *state;

public:
    StateCaretaker();
    ~StateCaretaker();

    void setStateCaretaker(State *s);
    State *getStateCaretaker();
};
#endif