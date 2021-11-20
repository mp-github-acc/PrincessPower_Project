#ifndef CLUSTER_H
#define CLUSTER_H
#include "StarLink.h"
#include "StarLinkSatellite.h"
#include "ObserverAbstractMissionControl.h"
#include <list>
class Cluster : public StarLink
{
private:
    list<AbstractMissionControl*> observerList;
    bool workingState;
protected:
    list<StarLink *> cluster_;
public:
    Cluster();
    ~Cluster();
    void add(StarLink *satellite);
    void remove();
    void print();
    Satellite* getSatellite();
    // Observer
    void attach(AbstractMissionControl* o);
    void detach(AbstractMissionControl* o);
    void notify();
};
#endif

