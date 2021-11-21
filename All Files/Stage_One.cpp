#include "Stage_One.h"

Stage_One::Stage_One()
{
    this->currentState = "Lift Off";
}
Stage_One::~Stage_One()
{
}
void Stage_One::handle()
{
    cout << "Rocket is taking off" << endl;
}
State *Stage_One::changeState()
{
    State* nextStage = new Stage_Two();
    return nextStage;
}
