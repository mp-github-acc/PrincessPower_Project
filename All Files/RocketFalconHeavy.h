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
    void addEngine();
    void handleRequest(string n, bool c);
    void setNext(Rocket* r);

    void accelerate();
    void decelerate();
    void ignite();
    void attach();
    void dock();
};
#endif