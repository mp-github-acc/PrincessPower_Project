#include "RocketFalconHeavyFactory.h"
#include "RocketFalconNineFactory.h"
#include "RocketFactory.h"
#include "Rocket.h"
#include "RocketFalconNine.h"
#include "RocketFalconHeavy.h"

#include "SpacecraftFactory.h"
#include "SpacecraftCrewDragonFactory.h"
#include "SpacecraftDragonFactory.h"
#include "Spacecraft.h"
#include "SpacecraftCrewDragon.h"
#include "SpacecraftDragon.h"

#include "CommandControlCenter.h"
#include <iostream>

using namespace std;

int main()
{

    RocketFactory **rFactory = new RocketFactory *[2];
    rFactory[0] = new FalconNineFactory();
    rFactory[1] = new FalconHeavyFactory();

    SpacecraftFactory **sFactory = new SpacecraftFactory *[2];
    sFactory[0] = new CrewDragonFactory();
    sFactory[1] = new DragonFactory();

    cout << " ---------------------- Construction ---------------------------- " << endl;
    int choice = 0;
    cout << "Welcome to Rocket construction" << endl;
    while (true)
    {

        cout << "Choose a Rocket: 1 = Falcon9, 2 = Falcon Heavy - ";
        cin >> choice;
        if (choice == 1)
        {
            break;
        }
        if (choice == 2)
        {
            break;
        }
    }

    // Rocket creation
    Rocket *newRocket = rFactory[choice - 1]->createRocket();
    while (true)
    {

        cout << "Choose a spacecraft: 1 = CrewDragon, 2 = Dragon - ";
        cin >> choice;
        if (choice == 1)
        {
            break;
        }
        if (choice == 2)
        {
            break;
        }
    }
    newRocket->addSpacecraft(sFactory[choice - 1]->createSpacecraft());
    // Satellites:
    if (newRocket->getRocketName() == "Falcon 9")
    {
        while (true)
        {

            cout << "Do you want satellites: 1 = yes, 0 = no - ";
            cin >> choice;
            if (choice == 1 || choice == 0)
            {
                break;
            }
        }

        newRocket->addSatellites(choice);
    }
    else
    {
        cout << newRocket->getRocketName() << " cannot take satellites." << endl;
    }
    // engines as well
    cout << endl;
    cout << " ---------------------- Static Fire ------------------------------- " << endl;
    bool canContinue;
    cout << "Rocket will now enter the Static Fire Test..." << endl;
    if (newRocket->staticFire())
    {
        canContinue = true;
        cout << "Rocket is complete" << endl;
    }
    else
    {
        canContinue = false;
        cout << "Rocket is incomplete" << endl;
    }
    cout << endl;
    if (!canContinue)
    {
        cout << "Rocket did not pass the satic fire test. Cannot proceed to simulation." << endl;
    }
    cout << " ---------------------- Simulation ------------------------------- " << endl;
    cout << "Simulation will start shortly." << endl;
    // random generator stuffs
    CommandControlCenter *controls = new CommandControlCenter(newRocket, newRocket->getSpacecraft());
    // Attach observers
    controls->liftOff();
    newRocket->implementObsever();
    newRocket->setCondition(true);
    return 0;
}