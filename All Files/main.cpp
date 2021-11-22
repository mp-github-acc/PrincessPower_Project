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

#include "StateCaretaker.h"
#include "SimulationState.h"
#include "StateRocket.h"

#include "SpaceStation.h"
#include "RocketAdapter.h"
//Princess power!
#include <iostream>
#include <list>

using namespace std;


int main()
{
    cout << "\n================ WELCOME TO THE PRINCESS POWER ROCKET SIMULATION ================\n " << endl;
    RocketFactory **rFactory = new RocketFactory *[2];
    rFactory[0] = new FalconNineFactory();
    rFactory[1] = new FalconHeavyFactory();

    SpacecraftFactory **sFactory = new SpacecraftFactory *[2];
    sFactory[0] = new CrewDragonFactory();
    sFactory[1] = new DragonFactory();

    bool canContinue = false;
    Rocket *newRocket;

    list<Rocket *> batch;

    while (!canContinue)
    {
        cout << "\n ---------------------- Construction ---------------------------- " << endl;
        int choice = 0;
        cout << "Welcome to Rocket construction" << endl;
        while (true)
        {
            cout << "Choose a Rocket: 0 = Falcon9, 1 = Falcon Heavy - ";
            cin >> choice;
            if (choice == 0)
            {
                break;
            }
            if (choice == 1)
            {
                break;
            }
        }
        /*
    choice = 0; [0] 
    other = 1 - choice = 1; [1]

    choice = 1; [1]
    other = 1 - choice = 0 [0]
*/
        // Rocket creation
        newRocket = rFactory[choice]->createRocket();
        newRocket->setNext(rFactory[1 - choice]->createRocket());
        while (true)
        {
            cout << "Choose a spacecraft: 0 = CrewDragon, 1 = Dragon - ";
            cin >> choice;
            if (choice == 0)
            {
                break;
            }
            if (choice == 1)
            {
                break;
            }
        }
        newRocket->addSpacecraft(sFactory[choice]->createSpacecraft());
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

        cout << "Adding engines to " << newRocket->getRocketName() << endl;
        newRocket->addEngine();

        cout << endl;
        cout << " ---------------------- Static Fire ------------------------------- " << endl;
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
    }
    if (!canContinue)
    {
        cout << "Rocket did not pass the static fire test. Cannot proceed to simulation." << endl;
    }
    else
    {
        cout << " ---------------------- Simulation ------------------------------- " << endl;
        cout << "Simulation will start shortly." << endl;
        cout << "Require observers:\t";

        SimulationState *memento = newRocket->createMemento();
        StateCaretaker care;
        care.store(memento);

        newRocket->printInformation();

        CommandControlCenter *controls = new CommandControlCenter(newRocket, newRocket->getSpacecraft());
        cout << "--------------------" << endl;
        newRocket->changeStage();
        cout << "--------------------" << endl;
        controls->liftOff();
        cout << "--------------------" << endl;
        cout << "--------------------" << endl;
        newRocket->changeStage();
        cout << "--------------------" << endl;

        // Memento
        newRocket->printInformation();

        

        SpaceStation *spacestation = new SpaceStation();

        cout << "--------------------" << endl;
        newRocket->changeStage();
        // Attach observers
        newRocket->handleRequest(newRocket->getRocketName(), true);
        newRocket->deploySatellites();
        cout << endl;
        cout << "--------------------" << endl;
        cout << "--------------------" << endl;
        newRocket->changeStage();
        cout << "--------------------" << endl;
        cout << "Attempting to deploy spacecraft..." << endl;
        RocketAdapter *adp = new RocketAdapter(newRocket->getSpacecraft());
        cout << "\t";
        adp->attach();
        cout << "\t";
        adp->attach();
        cout << "\t";
        adp->ignite();
        cout << "\t";
        adp->accelerate();
        cout << "\t";
        adp->decelerate();
        cout << "\t";
        adp->dock();
        cout << endl;
        adp->dock();

        cout << "--------------------" << endl;

        spacestation->addSpacecraft(newRocket->getSpacecraft());
        adp->dock();

        // Memento
        SimulationState *temp = care.retrieveState();
        newRocket->makeMemento(temp);
        // newRocket->printInformation();

        newRocket->printInformation();

        batch.push_back(newRocket);


    }

    if (!batch.empty())
    {
        //can launch
        cout << "\n\n\n\n---LAUNCH SEQUENCE---" << endl;
        Rocket *launchRocket;
        launchRocket = batch.front();
        batch.pop_front();

        launchRocket->printInformation();

        CommandControlCenter *contr = new CommandControlCenter(launchRocket, launchRocket->getSpacecraft());
        cout << "--------------------" << endl;
        launchRocket->changeStage();
        cout << "--------------------" << endl;
        contr->liftOff();
        cout << "--------------------" << endl;
        cout << "--------------------" << endl;
        launchRocket->changeStage();
        cout << "--------------------" << endl;
        // Memento
        launchRocket->printInformation();

        SimulationState *memento = launchRocket->createMemento();
        StateCaretaker care;
        care.store(memento);
        launchRocket->printInformation();

        SpaceStation *spacestation = new SpaceStation();

        cout << "--------------------" << endl;
        launchRocket->changeStage();
        // Attach observers
        launchRocket->handleRequest(launchRocket->getRocketName(), true);
        cout << "--------------------" << endl;
        cout << "--------------------" << endl;
        launchRocket->changeStage();
        cout << "--------------------" << endl;
        cout << "Attempting to deploy spacecraft..." << endl;
        RocketAdapter *ra = new RocketAdapter(launchRocket->getSpacecraft());
        cout << "\t";
        ra->attach();
        cout << "\t";
        ra->attach();
        cout << "\t";
        ra->ignite();
        cout << "\t";
        ra->accelerate();
        cout << "\t";
        ra->decelerate();
        cout << "\t";
        ra->dock();
        cout << endl;
        ra->dock();

        cout << "--------------------" << endl;

        spacestation->addSpacecraft(launchRocket->getSpacecraft());
        ra->dock();

        launchRocket->printInformation();
    }
    else{
        cout << "not able to launch" << endl;
    }
       
    //

    return 0;
}

