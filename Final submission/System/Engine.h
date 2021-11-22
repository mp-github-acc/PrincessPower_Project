#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
using namespace std;

class Engine
{// PROTOTYPE
    protected:
        string name;
    public:
        Engine();
        virtual ~Engine();
        Engine(Engine*);
        string getName();
        virtual Engine *clone() = 0;
};
#endif
