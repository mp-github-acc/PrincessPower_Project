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
    StarLink() {}
    virtual ~StarLink() {}
    void setParent(StarLink *p);
    StarLink *getParent();
    void setNumber(int i);
    int getNumber();
    int getTotal();
    virtual void add(StarLink *satellite);
    virtual void remove();
    virtual void print() = 0;
};

class Satellite : public StarLink
{
public:
    Satellite(){};
    void print();
};

class Cluster : public StarLink
{
protected:
    list<StarLink *> cluster_;

public:
    Cluster();
    ~Cluster();
    void add(StarLink *satellite);
    void remove();
    void print();
};
