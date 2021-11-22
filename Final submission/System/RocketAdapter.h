#ifndef ROCKETADAPTER_H
#define ROCKETADAPTER_H
#include "Spacecraft.h"
#include "Rocket.h"

using namespace std;

class RocketAdapter : public Rocket
{
private:
    Spacecraft *adaptee;
    bool docked;
    bool attached;
public:
    RocketAdapter(Spacecraft *adpt);
    ~RocketAdapter();

    // Command
    void accelerate();
    void decelerate();
    void ignite();
    void attach();
    void dock();
    void addSpacecraft(Spacecraft* s);
    void setRocketName(string n);
    Spacecraft *getSpacecraft();
    // Adapter
    bool isDocked();
    bool isAttached();
    void setDocked(bool b);
    void setAttached(bool b);

    // Not relevant
    void addEngine();
    void handleRequest(string n, bool c);
    void setNext(Rocket *r);
};
#endif