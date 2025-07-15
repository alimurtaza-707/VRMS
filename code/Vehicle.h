#ifndef VEHICLE_H
#define VEHICLE_H
#include "util.h"
#include "Owner.h"
#include "Registration.h"
#include "Market.h"
#include <vector>
using namespace std;


class Vehicle
{
    protected:
    string manufacturer;
    string color;
    date* manufactureDate;
    NumberPlate* NPV;
    bool ownedStatus;
    string type; 
    vector <Owner*> owner;
    vector <Registration*> registration;
    static vector <Vehicle*> totalVehicles; ////to store all Vehicles and use in VRMS


    public:
    Vehicle();
    Vehicle(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t);
    string getColor();
    string getManufacturer();
    NumberPlate getNumberPLate();
    string getType();
    bool getStatus();
    void setStatus(bool s);
    void addOwner(Owner* n);
    void addRegistration(Registration* r);
    vector<Owner*> getOwners();
    vector<Registration*> getRegs();
    static vector <Vehicle*> getTotalVehicles();
    virtual void printRegistration() =0;
    virtual void printOwners() = 0;
    virtual void printInfo() = 0;
    void displayInfo();
    virtual void detailedinfo()=0;

    //virtual ~Vehicle();

};

#endif