#include "Spacecraft.h"

Spacecraft::Spacecraft(){}

Spacecraft::~Spacecraft(){}

string Spacecraft::getName(){
    return this->name;
}

void Spacecraft::setName(string n){
    this->name = n;
}






// int main(){
//     Spacecraft* newS = new CrewDragon();
//     Spacecraft* newSA = new Dragon();
//     cout << newS->getName() << endl;    // Crew Dragon
//     cout << newSA->getName() << endl;   // Dragon
//     // You do not need to delete newS and newSA - C++ can handle the clean up by itself
//     return 0;
// }