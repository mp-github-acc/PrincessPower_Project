#include "Stage_Two.h"

Stage_Two::Stage_Two()
{
    this->currentState = "Low Orbit";
}
Stage_Two::~Stage_Two()
{
}
void Stage_Two::handle()
{
    cout << "Rocket has reached low orbit" << endl;
}
State *Stage_Two::changeState()
{
    State* nextStage = new Stage_Orbit();
    return nextStage;
}
