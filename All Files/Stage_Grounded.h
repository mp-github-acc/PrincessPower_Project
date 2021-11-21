#ifndef STAGE_GROUNDED_H
#define STAGE_GROUNDED_H

#include "State.h"
#include "Stage_One.h"

class Stage_Grounded : public State
{
public:
    Stage_Grounded();
    ~Stage_Grounded();
    void handle();
    State *changeState();
};
#endif