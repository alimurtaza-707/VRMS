#ifndef VRMS_H
#define VRMS_H
#include "util.h"
#include <vector>
using namespace std;

class Vehicle;
class Car;
class Bike;
class Truck;
class Owner;
class Registration;
class Market;
class Admin;

class VRMS
{
    protected:
    vector <Vehicle*> vehiclesInSystem;
    vector <Owner*>ownersInSytem;
    vector <Registration*> registrationsInSystem;
    Market* market;
    vector<Admin*> adminsInSystem;

    public:
    VRMS(Market* m);
    void menu();



};

#endif