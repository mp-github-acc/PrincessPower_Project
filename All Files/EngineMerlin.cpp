#include "EngineMerlin.h"

Merlin::Merlin(Merlin* m)
{
    name = m->getName();
}

Merlin::Merlin()
{
    name = "Merlin";
}

Merlin::~Merlin()
{
}

Merlin* Merlin::clone(){
    return new Merlin(*this);
}