#include "RocketFalconHeavy.h"

FalconHeavy::FalconHeavy()
{
    setRocketName("Falcon Heavy");
    next = NULL;
}

FalconHeavy::~FalconHeavy()
{
    cout << "FalconHeavy grounded!" << endl;
}
void FalconHeavy::setRocketName(string n)
{
    this->rocketName = "Falcon 9";
}
void FalconHeavy::addEngine()
{
    cout << "Core 1: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9; i++)
    {
        this->engines.push_back(pm->createMerlinEngine());
    }

    cout << "Core 2: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9; i++)
    {
        this->engines.push_back(pm->createMerlinEngine());
    }

    cout << "Core 3: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9; i++)
    {
        this->engines.push_back(pm->createMerlinEngine());
    }

    cout << "Adding 1 merlin vacuum engines" << endl;
    this->engines.push_back(pm->createMerlinVacuumEngine());
}

void FalconHeavy::addSpacecraft(Spacecraft *s)
{
    this->spacecraft_ = s;
}
Spacecraft *FalconHeavy::getSpacecraft(){
    return this->spacecraft_;
}
void FalconHeavy::setNext(Rocket *r)
{
    next = r;
}

void FalconHeavy::handleRequest(string n, bool change)
{
    cout << "FH" << endl;
    // cout << satelliteCluster->getNumber() << endl;
    if (n == "Falcon Heavy")
    {
        cout << "Falcon cannot observe satellites" << endl;
    }
    else
    {
        next->handleRequest(n, change);
    }
}

// Command
void FalconHeavy::accelerate()
{
    cout << getRocketName() << " is now accelerating. Increasing fuel consumption." << endl;
}

void FalconHeavy::decelerate()
{
    cout << getRocketName() << " is now decelerating. Decreasing fuel consumption." << endl;
}

void FalconHeavy::ignite()
{
    cout << getRocketName() << " is now igniting. " << endl;
}

void FalconHeavy::attach()
{
    cout << getRocketName() << " is now attaching the spacecraft. " << endl;
}

void FalconHeavy::dock()
{
    cout << getRocketName() << "'s spacecraft is docking at the spacestation. " << endl;
}