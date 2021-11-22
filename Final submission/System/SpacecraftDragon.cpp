#include "SpacecraftDragon.h"

Dragon::Dragon()
{
    setName("Dragon");
}
Dragon::~Dragon(){}
void Dragon::sendCargo(){
    cout << "Sending cargo to space" << endl;
}