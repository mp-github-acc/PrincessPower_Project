#include "StateRocket.h"

StateRocket::StateRocket(string n, string s, bool b, string st)
{
    name=n;
    spacecraft=s;
    hasSatellites=b;
    stage=st;

    // cout<<name<<endl;
    // cout<<spacecraft<<endl;
    // cout<<hasSatellites<<endl;
    // cout<<stage<<endl;

}

StateRocket::~StateRocket()
{
    
}


string StateRocket::getName(){
    return name;
}
string StateRocket::getSpacecraft(){
    return spacecraft;
}
bool StateRocket::getBool(){
    return hasSatellites;
}
string StateRocket::getStage(){
    return stage;
}