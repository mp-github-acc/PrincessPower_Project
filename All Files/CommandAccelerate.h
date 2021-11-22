#ifndef COMMANDACCELERATE_H
#define COMMANDACCELERATE_H

#include "Command.h"

class CommandAccelerate : public Command{
    private:

    public:
        CommandAccelerate(Rocket* r, Spacecraft* s);
        ~CommandAccelerate();
        void execute();
};
#endif