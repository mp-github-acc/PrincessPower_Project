#ifndef CONCRETEMISSIONCONTROL_h
#define CONCRETEMISSIONCONTROL_h

#include <iostream>
using namespace std;

#include "ObserverAbstractMissionControl.h"
#include "StarLinkCluster.h"

class ConcreteMissionControl : public AbstractMissionControl
{
private:
    bool observerState;
    StarLink *subject;
public:
    ConcreteMissionControl(StarLink *);
    ~ConcreteMissionControl();
    void update();
    void print();
};
#endif