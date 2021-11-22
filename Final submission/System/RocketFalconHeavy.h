#ifndef FALCONHEAVY_H
#define FALCONHEAVY_H

#include "Rocket.h"

class FalconHeavy : public Rocket
{
private:
    Rocket* next;
public:
    FalconHeavy();
    ~FalconHeavy();
   void setRocketName(string s);
    void addEngine();
    void addSpacecraft(Spacecraft *s);
    Spacecraft *getSpacecraft();

    void handleRequest(string n, bool r);
    void setNext(Rocket *r);

    void accelerate();
    void decelerate();
    void ignite();
    void attach();
    void dock();
};
#endif