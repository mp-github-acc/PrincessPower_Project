#include "ObserverConcreteMissionControl.h"

ConcreteMissionControl::ConcreteMissionControl(StarLink *c)
{
    subject = c;
    subject->setState(false);
    subject->attach(this);
}

ConcreteMissionControl::~ConcreteMissionControl()
{
    delete subject;
}

void ConcreteMissionControl::update()
{
    cout << "Observer is being updated from: " << observerState << " to " << subject->getState() << endl;
    observerState = subject->getState();
}

void ConcreteMissionControl::print(){
    string known = (observerState == false) ? "Satellites are not working" : "Satellites are working";
    cout << known << endl;
}