#ifndef FALCONNINE_H
#define FALCONNINE_H

#include "Rocket.h"

class FalconNine : public Rocket
{
private:
    Rocket* next;
public:
    FalconNine();
    ~FalconNine();
    void addEngine();
    void handleRequest(string n, bool r);
    void setNext(Rocket* r);

    void accelerate();
    void decelerate();
    void ignite();
    void attach();
    void dock();
};
#endif