#ifndef SATELLITE_H
#define SATELLITE_H

#include "StarLink.h"

class Satellite : public StarLink
{
public:
    Satellite();
    ~Satellite();
    void print();
    void deploy();
};
#endif
