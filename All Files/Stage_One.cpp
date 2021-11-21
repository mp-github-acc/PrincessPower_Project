#include "State_StageOne.h"


State_StageOne::State_StageOne(){

}
State_StageOne::~State_StageOne(){

}
void State_StageOne::handle(){

}
State* State_StageOne::changeState(){
    return new State_StageTwo();
}