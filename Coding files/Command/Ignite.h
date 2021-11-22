#ifndef IGNITE_H
#define IGNITE_H

#include "Command.h"

class Ignite : public Command{
    public:
        Ignite(Rocket* r);
        ~Ignite();
};
#endif