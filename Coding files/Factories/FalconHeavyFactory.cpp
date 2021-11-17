#include "FalconHeavyFactory.h"


Rocket* FalconHeavyFactory::creatRocket(){
    return new Falcon9Core();
}