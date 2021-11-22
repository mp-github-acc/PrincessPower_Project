#include "RocketFalconNine.h"

FalconNine::FalconNine(){
    cout << "Falcon 9 created!" << endl;
    setRocketName("Falcon 9");
    // this->satelliteCluster = nullptr;
    next = NULL;
}
FalconNine::~FalconNine(){
    cout << "Falcon9Core grounded!" << endl;
}

void FalconNine::addEngine(){   
    
    cout << "Core 1: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9 ; i++){
        this->engines.push_back(engineFactory[0]->createEngine());
    }

    cout<<"Adding 1 merlin vacuum engines"<<endl;
    this->engines.push_back(engineFactory[1]->createEngine());
}

void FalconNine::setNext(Rocket *r){
    next = r;
}

void FalconNine::handleRequest(string n, bool change){
    satelliteCluster->setState(change);
    if(n == "Falcon 9"){
        cout << "Now implementing required number of satellite observers" << endl;
        Rocket::implementObsever();
    }
    else{
        next->handleRequest(n, change);
    }
}