#ifndef OWNER_H
#define OWNER_H
#include "util.h"
#include "Market.h"
#include <vector>
using namespace std;

class Vehicle;

class Owner
{
    protected:
    string name;
    int userID;
    string profession;
    vector<Vehicle*> vehicleO; //to keep vehicles connected to the user even after he sells them
    vector <Vehicle*> inusevehicle; 
    static vector <Owner*> recordOwners; //to store all owners and use in VRMS

    public:
    Owner();
    Owner(string n, int id, string p, vector<Vehicle*> v);
    void displayOwner();
    void displayOwnerDetail();
    void sell(Market* market);
    void buyVehicle(Market* market);
    int getOwnerID();
    vector <Vehicle*> getInUseVehicle();
    static vector <Owner*> getRecordOwners(); 
    void searchOwner();
    void searchVehicle();
};

#endif