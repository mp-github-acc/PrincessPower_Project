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
    void handleRequest(string n);
    void setNext(Rocket* r);
};
#endif