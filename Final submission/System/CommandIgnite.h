#ifndef COMMANDIGNITE_H
#define COMMANDIGNITE_H

#include "Command.h"

class CommandIgnite : public Command{
    private:

    public:
        CommandIgnite(Rocket* r, Spacecraft* s);
        ~CommandIgnite();
        void execute();
};
#endif