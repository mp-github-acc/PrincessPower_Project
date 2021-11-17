#include "FalconNine.h"

Falcon9Core::Falcon9Core(){
    cout << "Falcon 9 created!" << endl;
    setRocketName("Falcon 9");
    this->cluster_ = nullptr;
}
Falcon9Core::~Falcon9Core(){
    cout << "Falcon9Core grounded!" << endl;
}
void Falcon9Core::addEngines(){
    cout << "Create engines for Falcon9Core..." << endl;
}