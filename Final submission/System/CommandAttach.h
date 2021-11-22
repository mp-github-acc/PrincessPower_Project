#ifndef COMMANDATTACH_H
#define COMMANDATTACH_H

#include "Command.h"

class CommandAttach : public Command{
    private:

    public:
        CommandAttach(Rocket* r, Spacecraft* s);
        ~CommandAttach();
        void execute();
};
#endif