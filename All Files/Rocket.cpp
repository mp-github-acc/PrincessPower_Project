#include "Rocket.h"

Rocket::Rocket()
{
    cout << "Constructing rocket" << endl;
    // spacecraft_ = nullptr;
    satelliteCluster = NULL;
    // state
    currentStage = new Stage_Grounded();
    engineFactory = new EngineFactory *[2];
    engineFactory[0] = new MerlinFactory();
    engineFactory[1] = new MerlinVacuumFactory();
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
        satelliteCluster = NULL;
    }
}
// template method
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
    if (this->satelliteCluster != NULL)
    {
        observer = new ConcreteMissionControl(satelliteCluster);
        cout << "\tSatellites are being observed" << endl;
    }
    else
    {
        cout << "\tFalcon 9 has no satellites to observe" << endl;
    }

    // handleRequest();
}

void Rocket::setCondition(bool b)
{
    satelliteCluster->setState(b);
    observer->update();
    observer->print();
}
// bool Rocket::setCondition(bool b)
// {
//     satelliteCluster->setState(b);
//     observer->update();
//     observer->print();
// }

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

SimulationState *Rocket::createMemento()
{
    bool b = (satelliteCluster == nullptr) ? false : true;

    SimulationState *m = new SimulationState(rocketName, spacecraft_->getName(), b, currentStage->getCurrentState());
    // SimulationState *m = new SimulationState(rocketName, spacecraft_->getName(), b, "grounded");

    return m;
}

void Rocket::makeMemento(SimulationState *m)
{
    StateRocket *sr = m->getRState();
    bool b = sr->getBool();
    string n = sr->getName();
    string sc = sr->getSpacecraft();
    string st = sr->getStage();
    //engines

    //

    delete spacecraft_;
    if (sc == "Crew Dragon")
        spacecraft_ = new CrewDragon();
    else
        spacecraft_ = new Dragon();

    //

    delete currentStage;
    if (currentStage->getCurrentState() == "Grounded")
        currentStage = new Stage_Grounded();
    else if (currentStage->getCurrentState() == "Lift Off")
        currentStage = new Stage_One();
    else if (currentStage->getCurrentState() == "High Orbit")
        currentStage = new Stage_Two();
    else
        currentStage = new Stage_Orbit();

    //
    list<Engine *>::iterator it = engines.begin();
    cout << "Deleting "  << engines.size() << " engines " << endl;
    engines.erase(engines.begin(), engines.end());
    cout << endl;
    // }

    if (n == "Falcon 9")
    {
        cout << "Core 1: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(engineFactory[0]->createEngine());
        }

        cout << "Adding 1 merlin vacuum engines" << endl;
        this->engines.push_back(engineFactory[1]->createEngine());
    }
    else
    {
        cout << "Core 1: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(engineFactory[0]->createEngine());
        }

        cout << "Core 2: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(engineFactory[0]->createEngine());
        }

        cout << "Core 3: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(engineFactory[0]->createEngine());
        }

        cout << "Adding 1 merlin vacuum engines" << endl;
        this->engines.push_back(engineFactory[1]->createEngine());
    }

    //

    if (b == false)
    {
        cout << "Not building satellites" << endl;
        satelliteCluster = nullptr;
    }
    else
    {
        cout << "Rebuilding satellites" << endl;
        satelliteCluster = new Cluster();
    }

    //=====================================================================
}

void Rocket::printInformation()
{

    cout << "\n---ROCKET INFORMATION---" << endl;
    cout << "Rocket name: \t" << rocketName << endl;

    if (satelliteCluster == nullptr)
        cout << "Satellites: no satellites" << endl;
    else
        cout << "Satellites: " << satelliteCluster->getNumber() << endl;

    cout << "Engines: " << engines.size() << endl;
    // list<Engine *>::iterator it = engines.begin();
    // for (;)
    // {
    //     cout << "Deleting engine " << (*it)->getName() << endl;

    // }
    cout << endl;
    // }
    // cout << "" << endl;
    // cout << "" << endl;
    // cout << "" << endl;
    // cout << "" << endl;
    cout << "------------------------" << endl;
}