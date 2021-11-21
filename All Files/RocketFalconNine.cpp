#include "RocketFalconNine.h"

FalconNine::FalconNine(){
    cout << "Falcon 9 created!" << endl;
    setRocketName("Falcon 9");
    // this->satelliteCluster = nullptr;
}
FalconNine::~FalconNine(){
    cout << "Falcon9Core grounded!" << endl;
}

void FalconNine::addEngine(){
    // int choice;
    // cout << "What engine would you like to add? 1 for blah blah 2 for blah" << endl;
    // cin >> choice;
    // if (choice == 1){
    //     //this->engines.push_back();//how many and what 
    // }else if (choice == 2){
    //     //this->engines.push_back();
    // }else{
    // cout<< "That is not a valid choice" << endl;
    MerlinFactory* mf;
    MerlinVacuumFactory* mvf;
    
    cout << "Core 1: Adding 9 merlin engines" << endl;
    for (int i = 0; i < 9 ; i++){
        this->engines.push_back(mf->createEngine());
    }

    cout<<"Adding 1 merlin vacuum engines"<<endl;
    this->engines.push_back(mvf->createEngine());
}
