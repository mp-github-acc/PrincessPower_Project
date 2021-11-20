#include "ObserverAbstractMIssionControl.h"

AbstractMissionControl::AbstractMissionControl(){
    subject = new Cluster();
}

AbstractMissionControl::~AbstractMissionControl(){
    delete subject;
}
void AbstractMissionControl::registerSatellites(Cluster *c){
    subject = c;
}