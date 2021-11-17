#ifndef DRAGON_H
#define DRAGON_H
#include "Spacecraft.h"
class Dragon : public Spacecraft{
    public:
        Dragon();
        ~Dragon(){};
        void sendCargo();
};
#endif