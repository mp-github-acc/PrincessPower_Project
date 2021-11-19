#include "Rocket.h"

Rocket::Rocket(){
    cout << "Constructing rocket" << endl;
    // spacecraft_ = nullptr;
    satelliteCluster = nullptr;
}
Rocket::~Rocket(){
    // Clean up
    delete spacecraft_;
    delete satelliteCluster;
}
void Rocket::setRocketName(string n){
    this->rocketName = n;
}
string Rocket::getRocketName(){
    return this->rocketName;
}
void Rocket::addSpacecraft(Spacecraft* s){
    cout << "Added spacecraft: " << s->getName() << endl;
    this->spacecraft_ = s;
}

void Rocket::addSatellites(int c){

    if(c == 1){
        // add satellites
        cout << this->getRocketName() << " has satellites" << endl;
        satelliteCluster = new Cluster();
    }
    else{
        //  no satellites
         cout << this->getRocketName() << " has no satellites" << endl;
        satelliteCluster = nullptr;
    }
}
// // // could be a template method
bool Rocket::staticFire(){
    // Get name of rocket
    // Check if satellite depending on name
    cout << "Inspecting rocket: " << this->rocketName << "..." << endl;
    if(this->rocketName == "Falcon 9"){
        cout << "\tShould rocket have satellites? 1 for Yes or 0 for No : ";
        int hasSatellite; cin >> hasSatellite;
        while(hasSatellite < 0 && hasSatellite > 1){
            cout << "\tShould rocket have satellites? 1 for Yes or 0 for No : ";
            cin >> hasSatellite;
        }
        if(hasSatellite == 1 && this->satelliteCluster != nullptr){    // yes and cluster exists
            cout << "\tLooking if satellites are present: " << endl;
            cout << "\t\tNumber of satellites: " << this->satelliteCluster->getTotal() << endl;
        }
        else if(hasSatellite == 1 && this->satelliteCluster == nullptr){     // yes but no satellites
            cout << "\t\tRocket missing satellites!" << endl;
            return false;       // build incomplete
        }
        else if(hasSatellite == 0 && this->satelliteCluster != nullptr){ // no but there are
            cout << "\t\tRocket has unwanted satellites.\n Cannot continue build as satellites need to be removed!\n";
            return false;
        }
        else{
            cout << "\t\tRocket is not required satellites and does not have." << endl;
        } 
    }
    cout << "\tIdentifying spacecraft on rocket..." << endl;
    if(this->spacecraft_){
        cout << "\t\tRocket has spacecraft: " << this->spacecraft_->getName() << endl;
    }
    else{
        cout << "\tBuild incomplete. Rocket has no spacecraft.";
    }
    cout << "\tExamining the engines..." << endl;
    // check if the F9 has 9 Merlin engines and the Heavy has the other amount
    return true;
}
