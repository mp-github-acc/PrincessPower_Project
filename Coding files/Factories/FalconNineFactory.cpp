#include "FalconNineFactory.h"

Rocket* FalconNineFactory::createRocket(){
    return new Falcon9Core();
}