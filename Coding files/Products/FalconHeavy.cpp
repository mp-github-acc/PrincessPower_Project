#include "FalconHeavy.h"

FalconHeavy::FalconHeavy(){
    cout << "FalconHeavy created!" << endl;
    setRocketName("Falcon Heavy");
    this->cluster_ = nullptr;
}
FalconHeavy::~FalconHeavy(){
    cout << "FalconHeavy grounded!" << endl;
}
void FalconHeavy::addEngines(){
    cout << "Create engines for FalconHeavy..." << endl;
}