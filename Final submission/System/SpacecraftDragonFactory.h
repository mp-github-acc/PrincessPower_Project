#ifndef DRAGONFACTORY_H
#define DRAGONFACTORY_H

#include "SpacecraftFactory.h"

class DragonFactory : public SpacecraftFactory{
    private:

    public:
        DragonFactory();
        ~DragonFactory();
        Spacecraft* createSpacecraft();
};
#endif
