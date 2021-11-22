#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
using namespace std;

class Engine
{
    protected:
        string name;
    public:
        Engine();
        ~Engine();
        string getName();
        
};
#endif
