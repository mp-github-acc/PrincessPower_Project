#include <iostream>
using namespace std;

// products
class Spacecraft{
    protected:
        string name;
    public:
        Spacecraft(){};
        virtual ~Spacecraft(){};
        virtual string getName(){return this->name;};
        virtual void sendCargo() = 0;
        void setName(string n);
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
        string getName(){
            return this->name;
        }
        void setName(string n){
            this->name = n;
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
        string getName(){
            return this->name;
        }
        void setName(string n){
            this->name = n;
        }
};