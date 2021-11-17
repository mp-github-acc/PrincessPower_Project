#ifndef FALCONNINE_H
#define FALCONNINE_H
#include "Rocket.h"
class Falcon9Core : public Rocket
{
private:
public:
    Falcon9Core();
    ~Falcon9Core();
    void addEngines();
};
#endif