#include "CommandDock.h"
CommandDock::CommandDock(Rocket *r, Spacecraft *s) : Command(r, s) {}
CommandDock::~CommandDock(){}
void CommandDock::execute()
{
    getRocket()->dock();
}