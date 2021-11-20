#ifndef ABSTRACTMISSIONCONTROL_H
#define ABSTRACTMISSIONCONTROL_H

#include "StarLinkCluster.h"
#include <iostream>

class AbstractMissionControl{
    protected:
        Cluster* subject;
    public:
        AbstractMissionControl();
        ~AbstractMissionControl();
        void registerSatellites(Cluster* c);
        virtual void update() = 0;
};
#endif

