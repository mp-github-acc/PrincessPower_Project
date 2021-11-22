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

void userInputToContinue(string s);

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
    

    bool gotoLaunch=false;
    do
    {
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

            cout <<endl<< "Adding engines to " << newRocket->getRocketName() << endl;
            newRocket->addEngine();

            userInputToContinue("Starting static fire");
            

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
                userInputToContinue("Restarting construction");
            }
            cout << endl;

            
        }
        if (!canContinue)
        {
            cout << "Rocket did not pass the static fire test. Cannot proceed to simulation." << endl;
            userInputToContinue("");
        }
        else
        {
            userInputToContinue("Proceeding to simulation");

            cout << " ---------------------- Simulation ------------------------------- " << endl;
            cout << "Simulation will start shortly." << endl;
            

            SimulationState *memento = newRocket->createMemento();
            StateCaretaker care;

            userInputToContinue("Storing rocket state");
            care.store(memento);

            newRocket->printInformation();
            userInputToContinue("Rocket's current information");

            CommandControlCenter *controls = new CommandControlCenter(newRocket, newRocket->getSpacecraft());
            cout << "--------------------" << endl;
            newRocket->changeStage();
            cout << "--------------------" << endl;
            controls->liftOff();
            cout << "--------------------" << endl;
            cout << "--------------------" << endl;
            newRocket->changeStage();
            cout << "--------------------" << endl;
            userInputToContinue("");

            // Memento
            newRocket->printInformation();
            userInputToContinue("Rocket's current information");

            

            SpaceStation *spacestation = new SpaceStation();

            cout << "--------------------" << endl;
            newRocket->changeStage();
            // Attach observers
            newRocket->deploySatellites();
            newRocket->handleRequest(newRocket->getRocketName(), true);
            userInputToContinue("");
            
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
            
            newRocket->printInformation();
            userInputToContinue("Rocket's current information");

            cout << "--------------------" << endl;

            spacestation->addSpacecraft(newRocket->getSpacecraft());
            adp->dock();

            // Memento
            userInputToContinue("Retrieving stored rocket state");
            SimulationState *temp = care.retrieveState();
            newRocket->makeMemento(temp);
            // newRocket->printInformation();

            newRocket->printInformation();

            batch.push_back(newRocket);

        }
        int answer;     

        while (true)
        {
            cout<<"Do you want to go to launch? 1 = Yes, 0 = No - ";
            cin >> answer;
            if (answer == 1)
            {
                gotoLaunch=true;
                break;
            }
            if (answer == 0)
            {
                canContinue=false;
                break;
            }
        }
        
        
    }
    while(!gotoLaunch);

    if (!batch.empty() && gotoLaunch)
    {
        cout << "\n\n\n\n----------------------LAUNCH SEQUENCE----------------------------" << endl;
        int count=1;
        while(!batch.empty())
        {
            //can launch
            cout << "\n\n====Rocket #"<<count<<"====" << endl;

            Rocket *launchRocket;
            SpaceStation *sp = new SpaceStation();

            launchRocket = batch.front();
            batch.pop_front();
            launchRocket->printInformation();
            userInputToContinue("Rocket's current information");
            
            userInputToContinue("Preparing to launch rocket");
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
            userInputToContinue("");
            launchRocket->printInformation();
            userInputToContinue("Rocket's current information");


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
            cout << "\t";ra->attach();
            cout << "\t";ra->attach();
            cout << "\t";ra->ignite();
            cout << "\t";ra->accelerate();
            cout << "\t";ra->decelerate();
            cout << "\t";ra->dock();

            launchRocket->printInformation();
            userInputToContinue("Rocket's current information");

            cout << endl;
            sp->addSpacecraft(launchRocket->getSpacecraft());
            ra->dock();

            cout << "--------------------" << endl;
            userInputToContinue("");

            count++;
            userInputToContinue("Rocket completed launch");
            cout<<"===========================" << endl;
            
        }
    }
    else{
        cout << "Not running launch, exiting program" << endl;
    }
       
    //
    cout << "End of program, now exiting. Thank you for running the simulation with Princess Power!\n\n" << endl;
    return 0;
}

void userInputToContinue(string s){
    string anyUserInput;
    cout<<endl;
    if(s==""){        
        cout<<"Enter any value to continue -";
        cin>>anyUserInput;
    }
    else{
        cout<<s<<", enter any value to continue -";
        cin>>anyUserInput;
    }
    cout<<endl;
}
//userInputToContinue("");