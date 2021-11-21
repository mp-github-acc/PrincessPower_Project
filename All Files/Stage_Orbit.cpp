#include "Stage_Orbit.h"

Stage_Orbit::Stage_Orbit()
{
    this->currentState = "High Orbit";
}
Stage_Orbit::~Stage_Orbit()
{
}
void Stage_Orbit::handle()
{
    cout << "Rocket has reached high orbit" << endl;
}

State *Stage_Orbit::changeState(){
    return NULL;
}