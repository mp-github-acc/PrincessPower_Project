#ifndef CONCRETEMISSIONCONTROL_h
#define CONCRETEMISSIONCONTROL_h

#include "ObserverAbstractMissionControl.h"
#include "StarLinkCluster.h"

class ConcreteMissionControl : public AbstractMissionControl{
    private:
        bool observerState;
        Cluster* subject;
    public:
        void update();
};
#endif