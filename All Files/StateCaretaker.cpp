#include "StateCaretaker.h"

StateCaretaker::StateCaretaker()
{
    cout << "Created StateCaretaker" << endl;
}
StateCaretaker::~StateCaretaker()
{
    cout << "Deleted StateCaretaker" << endl;
}

void StateCaretaker::setStateCaretaker(State *s)
{
    this->state = s;
}
State *StateCaretaker::getStateCaretaker()
{
    return this->state;
}