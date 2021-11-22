#include "FalconHeavyFactory.h"
FalconHeavyFactory::FalconHeavyFactory(){}
FalconHeavyFactory::~FalconHeavyFactory(){}

// void FalconHeavyFactory::createRocket(){
//     cout << "Heavy created!" << endl;
// }
Rocket* FalconHeavyFactory::createRocket(){
    return new FalconHeavy();
}