#ifndef BIKE_H
#define BIKE_H
#include "Vehicle.h"
using namespace std;

class Bike : public Vehicle
{
protected:
    string bikeType;
    float engineDisplacement;
    public:
    Bike();
    Bike(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t, string bt, float d);
    virtual void printRegistration() override;
    virtual void printOwners() override;
    virtual void printInfo() override;
    virtual void detailedinfo() override;

};

#endif