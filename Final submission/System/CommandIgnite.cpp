#include "CommandIgnite.h"
CommandIgnite::CommandIgnite(Rocket *r, Spacecraft *s) : Command(r, s) {}
CommandIgnite::~CommandIgnite(){}
void CommandIgnite::execute()
{
    getRocket()->ignite();
}