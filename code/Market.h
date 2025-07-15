#ifndef MARKET_H
#define MARKET_H
#include "util.h"
#include <vector>
using namespace std;

class Vehicle;
class Owner;

class Market
{
    protected:
    static vector <Vehicle*> inventoryHistory;
    vector <Vehicle*> inventory;
    vector <Owner*> sellers;

    public:
    Market(){};
    void displayInventory();
    void displaySVehicle(); //to display specific vehicle
    void addVehicle(Vehicle* v);
    void addOwner(Owner* o);
    void removeVehicle(Vehicle* v);
    vector <Vehicle*> getInventory();
    static vector <Vehicle*> getInventoryHistory();
};

#endif