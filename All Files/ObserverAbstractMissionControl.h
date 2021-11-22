#ifndef ABSTRACTMISSIONCONTROL_H
#define ABSTRACTMISSIONCONTROL_H

#include <iostream>

class AbstractMissionControl{
    // protected:
    //     Cluster* subject;
    public:
        AbstractMissionControl();
        virtual ~AbstractMissionControl();
        // void registerSatellites(Cluster* c);
        virtual void update() = 0;
        virtual void print() = 0;
};
#endif

