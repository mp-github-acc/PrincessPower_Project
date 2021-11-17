#ifndef DECELERATE_H
#define DECELERATE_H

#include "Command.h"

class Decelerate : public Command{
    public:
        Decelerate(Rocket* r);
        ~Decelerate();
};
#endif