#include <iostream>
#include "Spacecraft.cpp"
using namespace std;

class SpacecraftFactory{
    private:

    public:
        SpacecraftFactory(){};
        ~SpacecraftFactory(){};
        virtual Spacecraft* createSpacecraft() = 0;
};

class CrewDragonFactory : public SpacecraftFactory{
    private: 

    public:
        CrewDragonFactory(){};
        ~CrewDragonFactory(){};
        Spacecraft* createSpacecraft(){
            return new CrewDragon();
        }
};

class DragonFactory : public SpacecraftFactory{
    private:

    public:
        DragonFactory(){};
        ~DragonFactory(){};
        Spacecraft* createSpacecraft(){
            return new Dragon();
        }
};

class Client{
    private:
        Spacecraft* spacecraft[2];
    public:
        Client(){
            spacecraft[0] = new CrewDragon();  
            spacecraft[1] = new Dragon();
        }
        ~Client(){
            delete spacecraft[0];
            delete spacecraft[1];
        }
};

int main(){
    SpacecraftFactory** spacecraft = new SpacecraftFactory*[2]; // array of factories
    spacecraft[0] = new CrewDragonFactory();
    spacecraft[1] = new DragonFactory();

    cout << "--------Main in Spacecraft Factory--------" << endl;
    Spacecraft* newS = spacecraft[0]->createSpacecraft();
    cout << newS->getName() << endl;
    newS = spacecraft[1]->createSpacecraft();
    cout << newS->getName() << endl;
    // delete spacecraft;

    return 0;
}