#include "CommandDecelerate.h"

CommandDecelerate::CommandDecelerate(Rocket *r, Spacecraft *s) : Command(r, s) {}
CommandDecelerate::~CommandDecelerate(){}
void CommandDecelerate::execute()
{
    getRocket()->decelerate();
}