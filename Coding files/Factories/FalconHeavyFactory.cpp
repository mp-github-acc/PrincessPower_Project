#include "FalconHeavyFactory.h"


Rocket* FalconHeavyFactory::createRocket(){
    return new Falcon9Core();
}