#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle
{
    protected:
    int noOfDoors;
    string typeFuel; 

    public:
    Car();
    Car(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t, int i, string f);
    virtual void printRegistration() override;
    virtual void printOwners() override;
    virtual void printInfo() override;
    virtual void detailedinfo() override;

};

#endif