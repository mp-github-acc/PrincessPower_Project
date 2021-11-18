#include <iostream>
#include <list> // store the Component
using namespace std;
//USE STATIC VAR INSTEAD OF NUMBER??

class StarLink{ //Component  ------> Abstract Satellite (not supposed to be)
    protected:
        StarLink *parent;
        int total;
        int number;

    public:
        StarLink(){}
        virtual ~StarLink(){}
        void setParent(StarLink *p);
        StarLink *getParent();
        void setNumber(int i);
        int getNumber();
        int getTotal();
        virtual void add(StarLink *satellite);
        virtual void remove();
        virtual void print() = 0;
};

class Satellite : public StarLink{ //Leaf   ------->
    public:
        Satellite(){};
        void print();
};

class Cluster : public StarLink{ //Leaf
    protected:
        list<StarLink *> cluster_;

    public:
        Cluster();
        ~Cluster();
        void add(StarLink *satellite);
        void remove() ;
        void print();
};

