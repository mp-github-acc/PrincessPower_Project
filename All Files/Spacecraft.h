#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <iostream>
using namespace std;

class Spacecraft
{
protected:
    string name;

public:
    Spacecraft();
    virtual ~Spacecraft();
    virtual string getName();
    virtual void sendCargo() = 0;
    void setName(string n);
};
#endif