#include "SpaceStation.h"


void SpaceStation::addSpacecraft(Spacecraft* s){

    dockedSpacecraft->push_back(s);    
    cout<<"Space Station: Spacecraft successfully docked"<<endl;
}

Spacecraft* SpaceStation::removeSpacecraft(Spacecraft* s){
    dockedSpacecraft->remove(s);
    
    cout<<"Space Station: Spacecraft successfully undocked"<<endl;    
}