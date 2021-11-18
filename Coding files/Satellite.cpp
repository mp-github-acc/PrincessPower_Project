#include <iostream>
#include <list> // store the Component
using namespace std;
//USE STATIC VAR INSTEAD OF NUMBER??

class StarLink{ //Component  ------> Abstract Satellite (not supposed to be)
    protected:
        StarLink *parent;
        int total;
        int number;

    public:
        StarLink() {}
        virtual ~StarLink() {}
        void setParent(StarLink *p)
        {
            this->parent = p;
        }
        StarLink *getParent()
        {
            return this->parent;
        }
        void setNumber(int i)
        {
            number = i;
        }
        int getNumber()
        {
            return this->number;
        }
        int getTotal()
        {
            return total;
        }
        virtual void add(StarLink *satellite){};
        virtual void remove(){};
        virtual void print() = 0;
};

class Satellite : public StarLink{ //Leaf   ------->
    public:
        Satellite(){};
        void print()
        {
            cout << "Leaf" << endl;
        }
};

class Cluster : public StarLink{ //Leaf
    protected:
        list<StarLink *> cluster_;

    public:
        Cluster(){
            cout << "Adding satellite: ";
            while(getTotal() < 10){
                add(new Satellite());
            }
            cout << endl;
            cout << "Total: " << total << endl;
        };
        ~Cluster(){};
        void add(StarLink *satellite)
        {
            total = ++number;                       // increase the total and the number
            satellite->setNumber(number);           // give the satellite a number
            this->cluster_.push_back(satellite);    // add satellite to the list
            satellite->setParent(this);             // not sure why this here yet
            // cout << "Total : " << total << " - S.Number : " << satellite->getNumber() << endl;
            cout << "[" << number << "] ";
        }
        void remove()   // deploy instead of remove 
        {   // satellites deploy off rocket
            list<StarLink *>::iterator it = cluster_.begin();
            cout << "Deploying satellites..." << endl;
            for (; it != cluster_.end(); ++it)
            {
                cout << "# " << (*it)->getNumber() << endl;
            }
        }
        void print()
        {
            cout << "Composite" << endl;
        }
};

// class Client{ //what happens here --- merge
//     private:
//         StarLink *newCluster;               // keep cluster reference

//     public:
//         Client() { 
//             newCluster = new Cluster();     // make a new composite class 
//         }
//         ~Client() { 
//             delete newCluster;              // delete cluster
//         }
//         void createCluster()
//         {
//             cout << "Creating new cluster..." << endl;
//             while (newCluster->getTotal() < 10)     // change 10 to 60
//             {
//                 newCluster->add(new Satellite());   // add a new satellite in the cluster list
//             }
//             cout << "Cluster successfully created!" << endl;
//         }
//         void deployCluster()
//         {
//             newCluster->remove();               // prints out the satellites
//         }
//         void printCluster()
//         {
//             newCluster->print();
//         }
// };


// int main()
// {
//     cout << "----------Main in Satellites.cpp----------------" << endl;
//     Client *StarLink = new Client();        // create the client which handles the cluster
//     StarLink->createCluster();              // add the satellites to the cluster
//     StarLink->deployCluster();              // deploy -> remove() in cluster    
// }
