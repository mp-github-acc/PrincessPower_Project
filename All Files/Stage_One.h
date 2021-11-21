#include "State.h"

#ifndef STAGEONE_H
#define STAGEONE_H
#include "State.h"
#include "State_Orbit.h"
#include "State_Grounded.h"
#include "State_StageTwo.h"

class State_StageOne : public State{

    public:
    State_StageOne();
    ~State_StageOne();
    void handle();
    State* changeState();
    
};

#endif 