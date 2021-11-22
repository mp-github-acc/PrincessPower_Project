#include "Stage_Grounded.h"

Stage_Grounded::Stage_Grounded()
{
    this->currentState = "Grounded";
}
Stage_Grounded::~Stage_Grounded()
{
}
void Stage_Grounded::handle()
{
    cout << "Rocket is Grounded" << endl;
}
State *Stage_Grounded::changeState()
{
   State* nextStage = new Stage_One();
   return nextStage;
}

