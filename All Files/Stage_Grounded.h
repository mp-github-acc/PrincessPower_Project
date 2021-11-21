#include "State.h"

#ifndef GROUNDED_H
#define GROUNDED_H
#include "State.h"
#include "State_Orbit.h"
#include "State_StageOne.h"
#include "State_StageTwo.h"

class State_Grounded : public State{

    public:
    State_Grounded();
    ~State_Grounded();
    void handle();
    State* changeState();
    
};

#endif 