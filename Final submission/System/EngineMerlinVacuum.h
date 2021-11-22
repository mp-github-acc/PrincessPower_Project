#ifndef MERLINVACUUM_H
#define MERLINVACUUM_H
#include "Engine.h"
class MerlinVacuum : public Engine{
  //PROTOTYPE
  private:
  
  public:
    MerlinVacuum();
    MerlinVacuum(MerlinVacuum* mv);
    ~MerlinVacuum();
    MerlinVacuum* clone();
};
#endif
