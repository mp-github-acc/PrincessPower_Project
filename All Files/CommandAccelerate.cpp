#include "CommandAccelerate.h"
CommandAccelerate::CommandAccelerate(Rocket *r, Spacecraft *s) : Command(r, s) {}
CommandAccelerate::~CommandAccelerate(){}
void  CommandAccelerate::execute()
{
    getRocket()->accelerate();
}