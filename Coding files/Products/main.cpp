#include "../Factories/FalconNineFactory.h"
// #include "../Factories/RocketFactory.h"
#include "Rocket.h"
#include <iostream>
using namespace std;

int main(){
    RocketFactory** newR = new RocketFactory*[1];
    newR[0] = new FalconNineFactory();
    Rocket* rocket = newR[0]->createRocket();
    cout << rocket->getRocketName() << endl;
    return 0;
}