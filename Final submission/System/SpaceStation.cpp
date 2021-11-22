#include "SpaceStation.h"


SpaceStation::SpaceStation(){}
SpaceStation::~SpaceStation(){}

void SpaceStation::addSpacecraft(Spacecraft *s)
{

    // dockedSpacecraft->push_back(s);
    dockedSpacecraft.push_back(s);
    cout << "Space Station: Spacecraft successfully docked" << endl;
}

// Spacecraft *SpaceStation::removeSpacecraft(Spacecraft *s)
// {
//     // dockedSpacecraft->remove(s);
//     dockedSpacecraft.remove(s);
//     cout << "Space Station: Spacecraft successfully undocked" << endl;
// }

// bool SpaceStation::contains(Spacecraft *s)
// {
//     s;
//     return false;
//     //if not in the list, then add to list
// }