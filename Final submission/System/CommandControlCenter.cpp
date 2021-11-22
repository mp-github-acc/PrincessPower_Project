#include "CommandControlCenter.h"
CommandControlCenter::CommandControlCenter(Rocket *r, Spacecraft *s){
    commands = new Command *[5];    // increase size to 5
    commands[0] = new CommandIgnite(r, s);
    commands[1] = new CommandAccelerate(r, s);
    commands[2] = new CommandDecelerate(r, s);
    commands[3] = new CommandDock(r, s);
    commands[4] = new CommandAttach(r, s);
}
CommandControlCenter::~CommandControlCenter() noexcept{
    delete commands[0];
    delete commands[1];
    delete commands[2];
    delete commands[3];
    delete commands[4];
}
void CommandControlCenter::liftOff(){
    commands[0]->execute();     // ignite 
    commands[1]->execute();     // accelerate
}
