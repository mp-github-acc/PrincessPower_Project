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
    void handleRequest(string n);
    void setNext(Rocket* r);
};
#endif