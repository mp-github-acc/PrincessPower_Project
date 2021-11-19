#ifndef CLUSTER_H
#define CLUSTER_H
#include "StarLink.h"
#include "StarLinkSatellite.h"
class Cluster : public StarLink
{
protected:
    list<StarLink *> cluster_;

public:
    Cluster();
    ~Cluster();
    void add(StarLink *satellite);
    void remove();
    void print();
};
#endif