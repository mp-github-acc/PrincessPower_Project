#ifndef COMMANDDECELERATE_H
#define COMMANDDECELERATE_H

#include "Command.h"

class CommandDecelerate : public Command{
    private:

    public:
        CommandDecelerate(Rocket* r, Spacecraft* s);
        ~CommandDecelerate();
        void execute();
};
#endif