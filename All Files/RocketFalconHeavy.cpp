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
    // int choice;
    // cout << "What engine would you like to add? 1 for blah blah 2 for blah" << endl;
    // cin >> choice;
    // if (choice == 1){
    //     //this->engines.push_back();//how many and what
    // }else if (choice == 2){
    //     //this->engines.push_back();
    // }else{
    // cout<< "That is not a valid choice" << endl;

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

void FalconHeavy::handleRequest(string n){
    if(n == "Falcon Heavy"){
        cout << "Falcon cannot observe satellites" << endl;
    }
    else{
        next->handleRequest(n);
    }
}