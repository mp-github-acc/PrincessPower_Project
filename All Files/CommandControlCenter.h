#ifndef COMMANDCONTROLCENTER_H
#define COMMANDCONTROLCENTER_H

#include "CommandAccelerate.h"
#include "CommandIgnite.h"
#include "CommandDecelerate.h"

class CommandControlCenter
{
private:
    Command **commands;

public:
    CommandControlCenter(Rocket *r, Spacecraft *s)
    {
        commands = new Command *[3];
        commands[0] = new CommandIgnite(r, s);
        commands[1] = new CommandAccelerate(r, s);
        commands[2] = new CommandDecelerate(r, s);
    }
    ~CommandControlCenter(){
        delete commands[0];
        delete commands[1];
        delete commands[2];
    }
    void liftOff(){
        commands[0]->execute();     // ignite 
        commands[1]->execute();     // accelerate
    }
};
#endif