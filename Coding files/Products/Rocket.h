#include <iostream>
#include "Satellites.cpp"
#include "SpacecraftFactory.cpp"
#include "Engines.cpp"
#include <list>
using namespace std;


class Rocket
{
protected:
    Spacecraft* spacecraft_;
    string rocketName;
    StarLink* cluster_;
    // list<Engine*> engines;
public:
    Rocket();
    virtual ~Rocket();
    void setRocketName(string s);
    string getRocketName();
    void addSpacecraft();
    void addSatellites();
    virtual void addEngines();
    bool buildComplete();
};
class Falcon9Core : public Rocket
{
private:
public:
    Falcon9Core();
    ~Falcon9Core();
    void addEngines();
};

class FalconHeavy : public Rocket
{
public:
    FalconHeavy();
    ~FalconHeavy();
    void addEngines();
};