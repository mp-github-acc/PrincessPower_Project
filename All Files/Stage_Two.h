#include "State.h"

#ifndef STAGETWO_H
#define STAGETWO_H
#include "State.h"
#include "State_Orbit.h"
#include "State_Grounded.h"
#include "State_StageOne.h"

class State_StageTwo : public State{

    public:
    State_StageTwo();
    ~State_StageTwo();
    void handle();
    State* changeState();
    
};

#endif 