#ifndef STAGE_TWO_H
#define STAGE_TWO_H

#include "State.h"
#include "Stage_Orbit.h"

class Stage_Two : public State
{
public:
    Stage_Two();
    ~Stage_Two();
    void handle();
    State *changeState();
};
#endif