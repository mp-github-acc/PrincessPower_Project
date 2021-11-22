#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"

class Context{
    private:
        State* state_;
    public:
        Context(State* s);
        ~Context();
        void request();
};
#endif