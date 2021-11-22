#include "SpacecraftCrewDragon.h"

CrewDragon::CrewDragon(){
    setName("Crew Dragon");
}
CrewDragon::~CrewDragon(){}

void CrewDragon::sendCargo(){
    cout << "Sending people to space" << endl;
}