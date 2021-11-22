#include "Rocket.h"

Rocket::Rocket()
{
    // cout << "Constructing rocket" << endl;
    // spacecraft_ = nullptr;
    satelliteCluster = NULL;
    // state
    currentStage = new Stage_Grounded();
    // engineFactory = new EngineFactory *[2];
    // engineFactory[0] = new MerlinFactory();
    // engineFactory[1] = new MerlinVacuumFactory();

    pm = new PrototypeManager();
    // Falcon9Engines = {"Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","MerlinVacuum"};
    // Falcon9Engines = {"Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","Merlin","MerlinVacuum"};
}
Rocket::~Rocket()
{
    // Clean up
    delete spacecraft_;
    delete satelliteCluster;
    engines.erase(engines.begin(), engines.end());
    delete currentStage;
    delete succesor;
    delete pm;

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

StarLink *Rocket::getSatellite()
{
    return this->satelliteCluster;
}

// template method
bool Rocket::staticFire()
{
    // Get name of rocket
    // Check if satellite depending on name
    cout << "Inspecting rocket: " << this->getRocketName() << "..." << endl;
    if (this->getRocketName() == "Falcon 9")
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
        if (hasSatellite == 1 && this->getSatellite() != NULL)
        { // yes and cluster exists
            cout << "\tLooking if satellites are present: " << endl;
            cout << "\t\tNumber of satellites: " << this->getSatellite()->getTotal() << "/60" << endl;
        }
        else if (hasSatellite == 1 && this->getSatellite() == NULL)
        { // yes but no satellites
            cout << "\t\tRocket missing satellites!" << endl;
            return false; // build incomplete
        }
        else if (hasSatellite == 0 && this->getSatellite() != NULL)
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
    list<Engine*>::iterator it = engines.begin();
    int num = 0;
     cout << "\t" <<  this->getRocketName() << " awaiting checklist" << endl;
     cout << "\t";
    if(this->getRocketName() == "Falcon 9"){
        // iterate through the list of engines and compare to the array
        for( ; it != engines.end(); ++it){
            if((*it)->getName() != Falcon9Engines[num]){
                cout << endl;
                cout << "Incorrect Engine: expected " << Falcon9Engines[num] << " but got " << Falcon9Engines[num] << endl;

                return false;
            }
            cout << num + 1 << " ";
            num++;
            // cout << (*it)->getName();
        }
        cout << endl;
    }
    else{
        // iterate throught the list and the other array
        for( ; it != engines.end(); ++it){
            if((*it)->getName() != FalconHeavyEngines[num]){
                cout << endl;
                cout << "Incorrect Engine: expected " << FalconHeavyEngines[num] << " but got " << FalconHeavyEngines[num] << endl;
                return false;
            }
            cout << num + 1 << " ";
            num++;
            // cout << engines.size();
            // cout << (*it)->getName();
        }
        cout << endl;
    }
    cout << "\t" <<  this->getRocketName() << " has the right number and type of engines." << endl;
    return true;
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

Spacecraft *Rocket::getSpacecraft()
{
    return spacecraft_;
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

SimulationState *Rocket::createMemento()
{
    bool b = (satelliteCluster == nullptr) ? false : true;

    SimulationState *m = new SimulationState(rocketName, spacecraft_->getName(), b, currentStage->getCurrentState());
    // SimulationState *m = new SimulationState(rocketName, spacecraft_->getName(), b, "grounded");

    return m;
}
void Rocket::deploySatellites(){
    if(satelliteCluster != NULL){
        satelliteCluster->deploy();
    }
}
void Rocket::makeMemento(SimulationState *m)
{
    StateRocket *sr = m->getRState();
    bool b = sr->getBool();
    string n = sr->getName();
    string sc = sr->getSpacecraft();
    string st = sr->getStage();
    //engines

    // cout<<"!!!!!!!!\t\t\t\t\t\t"<<st<<endl;
    //

    delete spacecraft_;
    if (sc == "Crew Dragon")
        spacecraft_ = new CrewDragon();
    else
        spacecraft_ = new Dragon();

    //

    delete currentStage;
    if (st == "Grounded"){
        // cout<<"!!!!!!!!\t\t\t\t\t\t GROUNDEDDDDDDDDD"<<endl;
        currentStage = new Stage_Grounded();
    }
        
    else if (st == "Lift Off"){
        // cout<<"!!!!!!!!\t\t\t\t\t\t LOWWWWWWWWW ORBIT"<<endl;
        currentStage = new Stage_One();
    }
        
    else if (st == "High Orbit"){
        // cout<<"!!!!!!!!\t\t\t\t\t\t HIGHHHHHHH ORBIT"<<endl;
        currentStage = new Stage_Two();
    }
        
    else{
        // cout<<"!!!!!!!!\t\t\t\t\t\tSTAGEE ORBIT"<<endl;
        currentStage = new Stage_Orbit();
    }
        

    // list<Engine *>::iterator it = engines.begin();
    cout << "Deleting " << engines.size() << " engines " << endl;
    engines.erase(engines.begin(), engines.end());
    cout << endl;
    // }

    if (n == "Falcon 9")
    {
        cout << "Core 1: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(pm->createMerlinEngine());
        }

        cout << "Adding 1 merlin vacuum engines" << endl;
        this->engines.push_back(pm->createMerlinVacuumEngine());
    }
    else
    {
        cout << "Core 1: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(pm->createMerlinEngine());
        }

        cout << "Core 2: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(pm->createMerlinEngine());
        }

        cout << "Core 3: Adding 9 merlin engines" << endl;
        for (int i = 0; i < 9; i++)
        {
            this->engines.push_back(pm->createMerlinEngine());
        }

        cout << "Adding 1 merlin vacuum engines" << endl;
        this->engines.push_back(pm->createMerlinVacuumEngine());
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

    cout << "\n--- ROCKET INFORMATION ---" << endl;
    cout << "Rocket name: \t\t" << rocketName << endl;

    cout << "Engines: \t\t" << engines.size() << endl;

    if (satelliteCluster == nullptr)
        cout << "Satellites: \t\t0" << endl;
    else
        cout << "Satellites: \t\t" << satelliteCluster->getNumber() << endl;


    cout << "Spacecraft type: \t" << spacecraft_->getName() << endl;

    cout << "Current stage: \t\t" << currentStage->getCurrentState() << endl;

    cout << "--------------------------" << endl;
    cout << endl;
}