#include "State_Grounded.h"


State_Grounded::State_Grounded(){

}
State_Grounded::~State_Grounded(){

}
void State_Grounded::handle(){

}
State* State_Grounded::changeState(){
    return new State_StageOne();
}