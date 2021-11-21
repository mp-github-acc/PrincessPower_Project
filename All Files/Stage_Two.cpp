#include "State_StageTwo.h"


State_StageTwo::State_StageTwo(){

}
State_StageTwo::~State_StageTwo(){

}
void State_StageTwo::handle(){

}
State* State_StageTwo::changeState(){
    return new State_Orbit();
}