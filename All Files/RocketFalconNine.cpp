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
    // cout <<"F9" << endl;
    // cout << "Here" << endl;
    if(satelliteCluster == NULL){
        cout << n << " has no satellites." << endl;
        return;
    }
    // cout << satelliteCluster->getNumber() << endl;
    // cout << satelliteCluster->getNumber() << endl;
    Rocket::implementObsever();
    setCondition(change);
    if(n == "Falcon 9"){
        satelliteCluster->setState(change);
        cout << "Now implementing required number of satellite observers" << endl;
    }
    else{
        cout << "There" << endl;
        next->handleRequest(n, change);
    }
}