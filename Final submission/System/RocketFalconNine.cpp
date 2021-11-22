#include "RocketFalconNine.h"

FalconNine::FalconNine()
{
    setRocketName("Falcon 9");
    next = NULL;
}
FalconNine::~FalconNine()
{
    cout << "Falcon9Core grounded!" << endl;
}
void FalconNine::setRocketName(string n)
{
    this->rocketName = n;
}

void FalconNine::addEngine()
{

    cout << "Core 1: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9; i++)
    {
        this->engines.push_back(pm->createMerlinEngine());
    }

    cout << "Adding 1 merlin vacuum engines" << endl;
    this->engines.push_back(pm->createMerlinVacuumEngine());
}
void FalconNine::addSpacecraft(Spacecraft *s)
{
    this->spacecraft_ = s;
}
Spacecraft *FalconNine::getSpacecraft()
{
    return this->spacecraft_;
}
void FalconNine::setNext(Rocket *r)
{
    next = r;
}

void FalconNine::handleRequest(string n, bool change)
{
    // cout <<"F9" << endl;
    // cout << "Here" << endl;
    if (satelliteCluster == NULL)
    {
        cout << n << " has no satellites." << endl;
        return;
    }
    // cout << satelliteCluster->getNumber() << endl;
    // cout << satelliteCluster->getNumber() << endl;
    Rocket::implementObsever();
    setCondition(change);
    if (n == "Falcon 9")
    {
        satelliteCluster->setState(change);
        cout << "Now implementing required number of satellite observers" << endl;
    }
    else
    {
        cout << "There" << endl;
        next->handleRequest(n, change);
    }
}

// Command
void FalconNine::accelerate()
{
    cout << getRocketName() << " is now accelerating. Increasing fuel consumption." << endl;
}

void FalconNine::decelerate()
{
    cout << getRocketName() << " is now decelerating. Decreasing fuel consumption." << endl;
}

void FalconNine::ignite()
{
    cout << getRocketName() << " is now igniting. " << endl;
}

void FalconNine::attach()
{
    cout << getRocketName() << " is now attaching the spacecraft. " << endl;
}

void FalconNine::dock()
{
    cout << getRocketName() << "'s spacecraft is docking at the spacestation. " << endl;
}