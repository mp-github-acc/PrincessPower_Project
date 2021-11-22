#include "Spacecraft.h"

Spacecraft::Spacecraft(){}

Spacecraft::~Spacecraft(){}

string Spacecraft::getName(){
    return this->name;
}

void Spacecraft::setName(string n){
    this->name = n;
}