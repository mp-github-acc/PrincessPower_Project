#ifndef COMMANDCONTROLCENTER_H
#define COMMANDCONTROLCENTER_H

#include "CommandAccelerate.h"
#include "CommandIgnite.h"
#include "CommandDecelerate.h"
#include "CommandDock.h"
#include "CommandAttach.h"

class CommandControlCenter
{
private:
    Command **commands;

public:
// need to create the two NEW commands like CommandAccelerate
// add dock() and attach() to Rocket.h and implement them in rocket.cpp
    CommandControlCenter(Rocket *r, Spacecraft *s);
    ~CommandControlCenter();
    void liftOff();
};
#endif