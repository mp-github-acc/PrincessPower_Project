#include <iostream>
using namespace std;

// products
class Spacecraft{
    protected:
        string name;
    public:
        Spacecraft(){};
        virtual ~Spacecraft(){};
        virtual string getName(){
            return this->name;
        }
        virtual void sendCargo() = 0;
        void setName(string n){
            this->name = n;
        }
};

class CrewDragon : public Spacecraft{
    public:
        CrewDragon() : Spacecraft(){
            setName("Crew Dragon");
        }
        ~CrewDragon(){}
        void sendCargo(){ // go there and back
            cout << "Mense as well" << endl;
        }
};


class Dragon : public Spacecraft{
    public:
        Dragon() : Spacecraft(){
            setName("Dragon");
        }
        ~Dragon(){};
        void sendCargo(){
            // stays at ISS
        }
};

// int main(){
//     Spacecraft* newS = new CrewDragon();
//     Spacecraft* newSA = new Dragon();
//     cout << newS->getName() << endl;    // Crew Dragon
//     cout << newSA->getName() << endl;   // Dragon
//     // You do not need to delete newS and newSA - C++ can handle the clean up by itself
//     return 0;
// }