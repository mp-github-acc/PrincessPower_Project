#include "Command.h"

Command::Command(Rocket *r, Spacecraft *s)
{
    rocket_ = r;
    spacecraft_ = s;
}
Command::~Command()
{
    delete rocket_;
    delete spacecraft_;
}
Rocket *Command::getRocket()
{
    return this->rocket_;
}
Spacecraft *Command::getSpacecraft()
{
    return this->spacecraft_;
}