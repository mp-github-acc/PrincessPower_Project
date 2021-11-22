#ifndef ACCELERATE_H
#define ACCELERATE_H

#include "Command.h"

class Accelerate : public Command{
    public:
        Accelerate(Rocket* r);
        ~Accelerate();
};
#endif