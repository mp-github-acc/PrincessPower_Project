#include "Rocket.h"

Rocket::Rocket()
{
    cout << "Constructing rocket" << endl;
    // spacecraft_ = nullptr;
    satelliteCluster = nullptr;
    currentStage = new Stage_Grounded();
}
Rocket::~Rocket()
{
    // Clean up
    delete spacecraft_;
    delete satelliteCluster;
}
void Rocket::setRocketName(string n)
{
    this->rocketName = n;
}
string Rocket::getRocketName()
{
    return this->rocketName;
}
void Rocket::addSpacecraft(Spacecraft *s)
{
    cout << "Added spacecraft: " << s->getName() << endl;
    this->spacecraft_ = s;
}

void Rocket::addSatellites(int c)
{

    if (c == 1)
    {
        // add satellites
        cout << this->getRocketName() << " has satellites" << endl;
        satelliteCluster = new Cluster();
    }
    else
    {
        //  no satellites
        cout << this->getRocketName() << " has no satellites" << endl;
        satelliteCluster = nullptr;
    }
}
// // // could be a template method
bool Rocket::staticFire()
{
    // Get name of rocket
    // Check if satellite depending on name
    cout << "Inspecting rocket: " << this->rocketName << "..." << endl;
    if (this->rocketName == "Falcon 9")
    {
        cout << "\tShould rocket have satellites? 1 for Yes or 0 for No : ";
        int hasSatellite;
        cin >> hasSatellite;
        while (hasSatellite < 0 && hasSatellite > 1)
        {
            while (true)
            {
                if (hasSatellite == 1)
                {
                    cout << "\tShould rocket have satellites? 1 for Yes or 0 for No : ";
                    cin >> hasSatellite;
                }
                if (hasSatellite == 0)
                {
                    cout << "\tShould rocket have satellites? 1 for Yes or 0 for No : ";
                    cin >> hasSatellite;
                }
            }
        }
        if (hasSatellite == 1 && this->satelliteCluster != nullptr)
        { // yes and cluster exists
            cout << "\tLooking if satellites are present: " << endl;
            cout << "\t\tNumber of satellites: " << this->satelliteCluster->getTotal() << "/60" << endl;
        }
        else if (hasSatellite == 1 && this->satelliteCluster == nullptr)
        { // yes but no satellites
            cout << "\t\tRocket missing satellites!" << endl;
            return false; // build incomplete
        }
        else if (hasSatellite == 0 && this->satelliteCluster != nullptr)
        { // no but there are
            cout << "\t\tRocket has unwanted satellites.\n Cannot continue build as satellites need to be removed!\n";
            return false;
        }
        else
        {
            cout << "\t\tRocket is not required satellites and does not have." << endl;
        }
    }
    cout << "\tIdentifying spacecraft on rocket..." << endl;
    if (this->spacecraft_)
    {
        cout << "\t\tRocket has spacecraft: " << this->spacecraft_->getName() << endl;
    }
    else
    {
        cout << "\tBuild incomplete. Rocket has no spacecraft.";
    }
    cout << "\tExamining the engines..." << endl;
    // check if the F9 has 9 Merlin engines and the Heavy has the other amount
    return true;
}
// Command
void Rocket::accelerate()
{
    cout << getRocketName() << " is now accelerating. Increasing fuel consumption." << endl;
}

void Rocket::decelerate()
{
    cout << getRocketName() << " is now decelerating. Decreasing fuel consumption." << endl;
}

void Rocket::ignite()
{
    cout << getRocketName() << " is now igniting. " << endl;
}

Spacecraft *Rocket::getSpacecraft()
{
    return this->spacecraft_;
}

void Rocket::attach()
{
    cout << getRocketName() << " is now attaching the spacecraft. " << endl;
}

void Rocket::dock()
{
    cout << getRocketName() << "'s spacecraft is docking at the spacestation. " << endl;
}

// Observer
void Rocket::implementObsever()
{
    observer = new ConcreteMissionControl(satelliteCluster);
}

void Rocket::setCondition(bool b)
{
    satelliteCluster->setState(b);
    observer->update();
    observer->print();
}

// State
void Rocket::addState(State *s)
{
    this->currentStage = s;
}

void Rocket::changeStage()
{
    this->currentStage->handle();
    if (this->currentStage->getCurrentState() == "Grounded")
    {
        this->currentStage = this->currentStage->changeState();
    }
    else if (this->currentStage->getCurrentState() == "Lift Off")
    {
        this->currentStage = this->currentStage->changeState();
    }
    else if (this->currentStage->getCurrentState() == "Low Orbit")
    {
        this->currentStage = this->currentStage->changeState();
    }
    else if (this->currentStage->getCurrentState() == "High Orbit")
    {
        this->currentStage = this->currentStage->changeState();
    }
}

// SimulationState *Rocket::createMemento()
// {
//     // SimulationState *m = new SimulationState();
//     // m->setState(currentState);
//     // return m;
//     return nullptr;
// }

// void Rocket::setMemento(SimulationState *memento)
// {
//     // this->currentState = memento->getState();
// }
void Rocket::addEngine()
{
    // int choice;
    // cout << "What engine would you like to add? 1 for blah blah 2 for blah" << endl;
    // cin >> choice;
    // if (choice == 1){
    //     //this->engines.push_back();//how many and what
    // }else if (choice == 2){
    //     //this->engines.push_back();
    // }else{
    //     cout<< "That is not a valid choice" << endl;
    // }
}
