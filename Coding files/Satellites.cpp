#include <iostream>
#include <list> // store the Component
using namespace std;


class StarLink{
    protected:
        StarLink* parent;
        int total; 
        int number;
    public:
        StarLink(){}
        virtual ~StarLink(){}
        void setParent(StarLink* p){this->parent = p;}
        StarLink* getParent(){return this->parent;}
        void setNumber(int i){ number = i; } 
        int getNumber(){return this->number;}
        int getTotal(){return total;}
        virtual void Add(StarLink* satellite){};
        virtual void remove(){};
        virtual void Print() = 0;
};

class Satellite : public StarLink{
    public:
        Satellite(){};
        void Print(){
            cout << "Leaf" << endl;
        }
        
};

class Cluster : public StarLink{
    protected:
        list<StarLink*> cluster_;
    public:
        Cluster(){};
        ~Cluster(){};
        void Add(StarLink* satellite){
            total = ++number;
            satellite->setNumber(number);
            this->cluster_.push_back(satellite);
            satellite->setParent(this);
            // cout << "Total : " << total << " - S.Number : " << satellite->getNumber() << endl;
        }
        void remove(){
            list<StarLink*>::iterator it = cluster_.begin();
            cout << "Deploying satellites..." << endl;
            for( ; it != cluster_.end(); ++it){
                cout << "# " <<(*it)->getNumber() << endl;
            }
        }
        void Print(){
            cout << "Composite" << endl;

        }
};

class Client{
    private:
        StarLink* newCluster;
    public:
        Client(){ newCluster = new Cluster(); }
        ~Client(){ delete newCluster; }
        void createCluster(){
            cout << "Creating new cluster..." << endl;
            while(newCluster->getTotal() < 10){
                newCluster->Add(new Satellite());
            }
            cout << "Cluster successfully created!" << endl;
        }
        void deployCluster(){
            newCluster->remove();
        }
        void printCluster(){
            newCluster->Print();
        }
};

int main(){
    Client* StarLink = new Client();
    StarLink->createCluster();
    StarLink->deployCluster();
}