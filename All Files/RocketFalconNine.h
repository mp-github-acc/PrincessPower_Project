#ifndef FALCONNINE_H
#define FALCONNINE_H

#include "Rocket.h"

class FalconNine : public Rocket
{
private:
    Rocket *next;

public:
    FalconNine();
    ~FalconNine();
    // void addSatellites(int c);
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