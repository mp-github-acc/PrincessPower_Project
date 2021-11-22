#include "StarLink.h"

StarLink::StarLink() {
    // cout << "StarLink constructor" << endl;
}
StarLink::~StarLink() {
    // cout << "StarLink destructor" << endl;
}
void StarLink::setParent(StarLink *p)
{
    this->parent = p;
}
StarLink *StarLink::getParent()
{
    return this->parent;
}
void StarLink::setNumber(int i)
{
    number = i;
}
int StarLink::getNumber()
{
    return this->number;
}
int StarLink::getTotal()
{
    return total;
}
void StarLink::add(StarLink *satellite) {}
void StarLink::remove() {}


// Observers
void StarLink::attach(AbstractMissionControl *o)
{
    cout << "Attaching obsever" << endl;
    observerList.push_back(o);
}
void StarLink::detach(AbstractMissionControl *o)
{
    observerList.remove(o);
}

void StarLink::notify()
{
    // notify all the observers
    cout <<"Going to notify " << observerList.size() << "observers" << endl;
    list<AbstractMissionControl *>::iterator it = observerList.begin();
    for (it = observerList.begin(); it != observerList.end(); ++it)
    {
        (*it)->update();
    }
}


bool StarLink::getState(){
    return workingState;
}

void StarLink::setState(bool b){
    cout << "Satellite working state change from: " << workingState << " to " << b << endl;
    workingState = b;
}