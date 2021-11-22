#ifndef MERLIN_H
#define MERLIN_H
#include "Engine.h"
class Merlin : public Engine
{
  //CONCRETE PROTOTYPE
private:
public:
  Merlin();
  Merlin(Merlin * m);
  ~Merlin();
  Merlin *clone();
};
#endif
