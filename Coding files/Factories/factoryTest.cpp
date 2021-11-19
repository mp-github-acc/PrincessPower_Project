#include "FalconHeavyFactory.h"
#include "FalconNineFactory.h"
#include "RocketFactory.h"
#include "../Products/Rocket.h"
#include "../Products/FalconNine.h"
#include "../Products/FalconHeavy.h"
#include <iostream>

using namespace std;

int main(){

    RocketFactory** rFactory = new RocketFactory*[2];
    rFactory[0] = new FalconNineFactory();
    rFactory[1] = new FalconHeavyFactory();

    rFactory[0]->createRocket();
    rFactory[1]->createRocket();

    // EngineFactory** eFactory = new EngineFactory*[2];
    // eFactory[0] = new MerlinFactory();
    // eFactory[1] = new MerlinVacuumFactory();

    // SpacecraftFactory** sFactory = new SpacecraftFactory*[2];
    // sFactory[0] = new CrewDragonFactory();
    // sFactory[1] = new DragonFactory();
    return 0;
}