#include "Cluster.h"
Cluster::Cluster()
{
    cout << "Adding satellite: ";
    while (getTotal() < 10)
    {
        add(new Satellite());
    }
    cout << endl;
    cout << "Total: " << total << endl;
}
Cluster::~Cluster() {}
void Cluster::add(StarLink *satellite)
{
    total = ++number;                    // increase the total and the number
    satellite->setNumber(number);        // give the satellite a number
    this->cluster_.push_back(satellite); // add satellite to the list
    satellite->setParent(this);          // not sure why this here yet
    // cout << "Total : " << total << " - S.Number : " << satellite->getNumber() << endl;
    cout << "[" << number << "] ";
}
void Cluster::remove() // deploy instead of remove
{                      // satellites deploy off rocket
    list<StarLink *>::iterator it = cluster_.begin();
    cout << "Deploying satellites..." << endl;
    for (; it != cluster_.end(); ++it)
    {
        cout << "# " << (*it)->getNumber() << endl;
    }
}
void Cluster::print()
{
    cout << "Composite" << endl;
}