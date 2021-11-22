#include "RocketFalconNineFactory.h"

FalconNineFactory::FalconNineFactory(){}
FalconNineFactory::~FalconNineFactory(){}
// void FalconNineFactory::createRocket(){
//     cout << "Nine created!" << endl;
// }
Rocket* FalconNineFactory::createRocket(){
    return new FalconNine();
}