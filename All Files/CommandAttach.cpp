#include "CommandAttach.h"
CommandAttach::CommandAttach(Rocket *r, Spacecraft *s) : Command(r, s) {}
CommandAttach::~CommandAttach(){}
void CommandAttach::execute()
{
    getRocket()->attach();
}