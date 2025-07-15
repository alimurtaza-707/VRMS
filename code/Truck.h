#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
using namespace std;

class Truck: public Vehicle
{
    protected:
    float capacity;
    int axles;

    public:
    Truck();
    Truck(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t, float cp, int a);
    virtual void printRegistration() override;
    virtual void printOwners() override;
    virtual void printInfo() override;
    virtual void detailedinfo() override;

};

#endif