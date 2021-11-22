#ifndef COMMANDDOCK_H
#define COMMANDDOCK_H

#include "Command.h"

class CommandDock : public Command{
    private:

    public:
        CommandDock(Rocket* r, Spacecraft* s);
        ~CommandDock();
        void execute();
};
#endif