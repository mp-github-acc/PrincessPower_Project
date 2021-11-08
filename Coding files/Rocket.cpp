#include <iostream>
#include "Satellites.cpp"
#include "SpacecraftFactory.cpp"
#include "Engines.cpp"
#include <list>
using namespace std;

class Rocket{ 
    protected:
        Spacecraft* spacecraft_;
        string rocketName;
        list<Engine*> engines;
    public:
        Rocket();
        ~Rocket();
        void setRocketName(string s){
            this->rocketName = s;
        };
        virtual void addEngines(){};
};

class Falcon9Core : public Rocket{
    private:
        StarLink* sat; //ask is this optional at the rocket or only here?
    public:
        Falcon9Core(){
            setRocketName("Falcon 9");
            // do you want satellites?
            //------------------------------------
            // string choice;
            // cout << "Do you want satellites? Yes or No";
            // cin >> choice;
            // if(choice == "Yes" || choice == "yes"){
            //     sat = new Cluster(); // make the satellites
            //     // sat->remove();
            // }else{
            //     sat = nullptr;
            // }
            //------------------------------------
            // int chooseSpacecraft;
            // cout << "Choose a spacecraft: Crew Dragon[0] or Dragon[1]";
            // cin >> chooseSpacecraft;
            // if(chooseSpacecraft == 0){
            //     spacecraft_ = new CrewDragon();
            // }else{
            //     spacecraft_ = new Dragon();
            // }
            //------------------------------------
        };
        ~Falcon9Core(){
            delete sat;
        };
        void addSatellite(int n){
            string choice;
            cout << "Do you want satellites? Yes or No";
            cin >> choice;
            if(choice == "Yes" || choice == "yes"){
                sat = new Cluster(); // make the satellites
                // sat->remove();
            }else{
                sat = nullptr;
            }
        };
        void addEngines(){
            for (int i = 0 ; i < 9; i++){ //basically just to add certain amount
                //engines.push_back();
            }
            //engines.push_back(); ---add 1 vacuum merlin engine
        }
        void addSpaceCraft(){
            int chooseSpacecraft;
            cout << "Choose a spacecraft: Crew Dragon[0] or Dragon[1]";
            cin >> chooseSpacecraft;
            if(chooseSpacecraft == 0){
                spacecraft_ = new CrewDragon();
            }else{
                spacecraft_ = new Dragon();
            }
        }
};

class FalconHeavy : public Rocket{
    private:

    public:
        FalconHeavy(){
            setRocketName("Falcon Heavy");
            int chooseSpacecraft;
            cout << "Choose a spacecraft: Crew Dragon[0] or Dragon[1]";
            cin >> chooseSpacecraft;
            if(chooseSpacecraft == 0){
                spacecraft_ = new CrewDragon();
            }else{
                spacecraft_ = new Dragon();
            }
        };
        ~FalconHeavy();
        void addEngines(){
            for (int i = 0 ; i < 27; i++){ //basically just to add certain amount
                //engines.push_back();
            }
            //engines.push_back(); ---add 1 vacuum merlin engine
        }
};