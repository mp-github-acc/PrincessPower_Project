#include "FalconNineFactory.h"

Rocket* FalconNineFactory::creatRocket(){
    return new Falcon9Core();
}