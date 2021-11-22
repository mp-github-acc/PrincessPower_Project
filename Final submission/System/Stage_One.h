#ifndef STAGE_ONE_H
#define STAGE_ONE_H

#include "State.h"
#include "Stage_Two.h"

class Stage_One : public State
{
public:
    Stage_One();
    ~Stage_One();
    void handle();
    State *changeState();
};
#endif