#include "Rocket.h"

Rocket::Rocket(){
    cout << "Constructing rocket" << endl;
}
Rocket::~Rocket(){
    // Clean up
    delete spacecraft_;
    delete cluster_;
}

void Rocket::setRocketName(string n){
    this->rocketName = n;
}
string Rocket::getRocketName(){
    return this->rocketName;
}
void Rocket::addSpacecraft(){
    int choice;
    cout << "Choose a spacecraft, Crew Dragon[0] or Dragon[1] : ";
    cin >> choice;
    bool invalid = true;
    while(invalid){
        if(choice == 0){
            invalid = false;
            this->spacecraft_ = new CrewDragon();
            cout << this->rocketName << " has a " << this->spacecraft_->getName() << " spacecraft." << endl;
        }
        else if(choice == 1){
            invalid = false;
            this->spacecraft_ = new Dragon();
            cout << this->rocketName << " has a " << this->spacecraft_->getName() << " spacecraft." << endl;
        }
        else{
            cout << "Choose a spacecraft, Crew Dragon[0] or Dragon[1] : ";
            cin >> choice;
        }
    }
}

void Rocket::addEngines(){
    cout << "Still need to implement this" << endl;
}

void Rocket::addSatellites(){
    string choice;
    cout << "Add Satellites: Yes or No - "; cin >> choice;
    if(choice == "yes" || choice == "Yes"){
        // add satellites
        cluster_ = new Cluster();
    }
    else{
        //  no satellites
        cluster_ = nullptr;
    }
}
// could be a template method
bool Rocket::buildComplete(){
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
        if(hasSatellite == 1 && this->cluster_ != nullptr){    // yes and cluster exists
            cout << "\tLooking if satellites are present: " << endl;
            cout << "\t\tNumber of satellites: " << this->cluster_->getTotal() << endl;
        }
        else if(hasSatellite == 1 && this->cluster_ == nullptr){     // yes but no satellites
            cout << "\t\tRocket missing satellites!" << endl;
            return false;       // build incomplete
        }
        else if(hasSatellite == 0 && this->cluster_ != nullptr){ // no but there are
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

// // --------------------- Testing Purposes ------------------------ //
// int main(){
//     Rocket* newR = new Falcon9Core();
//     cout << "Rocket Name: " << newR->getRocketName() << endl;
//     cout << "-----------------------------------------------" << endl;
//     newR->addSpacecraft();
//     cout << "-----------------------------------------------" << endl;
//     newR->addSatellites();
//     cout << "-----------------------------------------------" << endl;
//     if(newR->buildComplete()){
//         cout << "Rocket is complete!" << endl;
//     }
//     else{
//         cout << "Rocket is incomplete!" << endl;
//     }
//     return 0;
// }