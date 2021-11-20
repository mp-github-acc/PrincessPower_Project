#ifndef CLUSTER_H
#define CLUSTER_H
#include "StarLink.h"
#include "StarLinkSatellite.h"
#include <list>
using namespace std;
class Cluster : public StarLink
{
// private:
//     bool workingState;
protected:
    list<StarLink*> cluster_;
public:
    Cluster();
    ~Cluster();
    void add(StarLink *satellite);
    void remove();
    void print();
    Satellite *getSatellite();
    
};
#endif
