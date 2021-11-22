#include "RocketFalconHeavyFactory.h"
FalconHeavyFactory::FalconHeavyFactory(){}
FalconHeavyFactory::~FalconHeavyFactory(){}
Rocket* FalconHeavyFactory::createRocket(){
    return new FalconHeavy();
}