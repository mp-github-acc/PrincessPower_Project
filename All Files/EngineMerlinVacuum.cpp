#include "EngineMerlinVacuum.h"

MerlinVacuum::MerlinVacuum()
{
    name = "Merlin Vacuum";
}

MerlinVacuum::MerlinVacuum(MerlinVacuum* mv)
{
    name = mv->getName();
}

MerlinVacuum::~MerlinVacuum(){}


MerlinVacuum* MerlinVacuum::clone(){
    return new MerlinVacuum(*this);
}