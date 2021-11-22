#include "RocketAdapter.h"

RocketAdapter::RocketAdapter(Spacecraft *adpt)
{
    adaptee = adpt;
    docked = false;
    attached = true;
}
RocketAdapter::~RocketAdapter()
{
    delete adaptee;
}

void RocketAdapter::accelerate()
{
    // do some sht here
    if (isAttached())
    {
        cout << "Cannot accelerate. Spacecraft still on rocket." << endl;
    }
    else
    {
        cout << "Increasing speed to get to space station" << endl;
    }
}
void RocketAdapter::decelerate()
{
    if(isAttached()){
        cout << "Cannot decelerate. Spacecraft still on rocket."<<endl;
    }
    else{
        cout << "Approaching space station, slowing down" << endl;
    }
}
void RocketAdapter::ignite()
{
    if(isAttached()){
        cout << "Cannot ignite. Spacecraft still on rocket."<<endl;
    }
    else{
        cout << "Igniting nitrogen" << endl;
    }
    
}

void RocketAdapter::attach()
{
    if (attached)
    {
        // Still on rocket
        cout << adaptee->getName() << " is attached to the rocket." << endl;
        attached = false; // to detatch it
    }
    else
    {
        // not on rocket
        cout << adaptee->getName() << " has detached from rocket." << endl;
    }
}
void RocketAdapter::dock()
{
    if (docked)
    {
        // Docked to station
        cout << adaptee->getName() << " is successfully docked on to the station." << endl;
    }
    else
    {
        // Not docket to station
        cout << adaptee->getName() << " is not currently docked on space station" << endl;
        docked=true;
    }
}





bool RocketAdapter::isDocked()
{
    return docked;
}

bool RocketAdapter::isAttached()
{
    return attached;
}

void RocketAdapter::setDocked(bool b)
{
    docked = b;
}

void RocketAdapter::setAttached(bool b)
{
    attached = b;
}


void RocketAdapter::addEngine(){
    //niks
}
void RocketAdapter::handleRequest(string n, bool c){
    //niks
}

void RocketAdapter::setNext(Rocket *r){
    //niks
}

