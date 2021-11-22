#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include "../Products/Rocket.h"
using namespace std;

class Command{
    protected:
        Rocket* rocket_;
    public:
        Command(Rocket* r);
        virtual ~Command();
        Rocket* getRocket();
        virtual void execute() = 0;
};
#endif