#ifndef STAGE_ORBIT_H
#define STAGE_ORBIT_H

#include "State.h"

class Stage_Orbit : public State
{
public:
    Stage_Orbit();
    ~Stage_Orbit();
    void handle();
    State *changeState();
};
#endif