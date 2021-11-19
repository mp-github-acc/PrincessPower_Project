#include "StarLink.h"

StarLink::StarLink() {
    // cout << "StarLink constructor" << endl;
}
StarLink::~StarLink() {
    // cout << "StarLink destructor" << endl;
}
void StarLink::setParent(StarLink *p)
{
    this->parent = p;
}
StarLink *StarLink::getParent()
{
    return this->parent;
}
void StarLink::setNumber(int i)
{
    number = i;
}
int StarLink::getNumber()
{
    return this->number;
}
int StarLink::getTotal()
{
    return total;
}
void StarLink::add(StarLink *satellite) {}
void StarLink::remove() {}
