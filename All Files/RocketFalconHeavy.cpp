#include "RocketFalconHeavy.h"

FalconHeavy::FalconHeavy()
{
    cout << "FalconHeavy created!" << endl;
    setRocketName("Falcon Heavy");
    // this->satelliteCluster = nullptr;
}

FalconHeavy::~FalconHeavy()
{
    cout << "FalconHeavy grounded!" << endl;
}

void FalconHeavy::addEngine()
{
    cout << "Core 1: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9; i++)
    {
        this->engines.push_back(engineFactory[0]->createEngine());
    }

    cout << "Core 2: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9; i++)
    {
        this->engines.push_back(engineFactory[0]->createEngine());
    }

    cout << "Core 3: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9; i++)
    {
        this->engines.push_back(engineFactory[0]->createEngine());
    }

    cout << "Adding 1 merlin vacuum engines" << endl;
    this->engines.push_back(engineFactory[1]->createEngine());
}

void FalconHeavy::setNext(Rocket* r){
    next = r;
}

void FalconHeavy::handleRequest(string n, bool change){
    if(n == "Falcon Heavy"){
        cout << "Falcon cannot observe satellites" << endl;
    }
    else{
        next->handleRequest(n, change);
    }
}