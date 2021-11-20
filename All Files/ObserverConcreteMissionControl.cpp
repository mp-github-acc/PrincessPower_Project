#include "ObserverConcreteMissionControl.h"

ConcreteMissionControl::ConcreteMissionControl(StarLink *c)
{
    subject = c;
    subject->setState(false);
}

ConcreteMissionControl::~ConcreteMissionControl()
{
    delete subject;
}

void ConcreteMissionControl::update()
{
    observerState = subject->getState();
}

void ConcreteMissionControl::print(){
    string known = (observerState == false) ? "Satellites are not working" : "Satellites are working";
    cout << known << endl;
}