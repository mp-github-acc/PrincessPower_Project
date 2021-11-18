#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;

class State{
    public:
        virtual void handle() = 0;
};
#endif