#ifndef STARLINK_H
#define STARLINK_H

#include <iostream>
#include <list>
using namespace std;

class StarLink
{
protected:
    StarLink *parent;
    int total;
    int number;

public:
    StarLink();
    virtual ~StarLink();
    void setParent(StarLink *p);
    StarLink *getParent();
    void setNumber(int i);
    int getNumber();
    int getTotal();
    virtual void add(StarLink *satellite);
    virtual void remove();
    virtual void print() = 0;
};
#endif