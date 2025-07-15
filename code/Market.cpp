#include "Market.h"
#include "Vehicle.h"
#include "Owner.h"
using namespace std;

vector <Vehicle*> Market:: inventoryHistory;

void Market::addVehicle(Vehicle *v)
{
    inventory.push_back(v);
    inventoryHistory.push_back(v);
}

void Market::addOwner(Owner *o)
{
    //cout<<"Seller CHeck\n";
    sellers.push_back(o);
    //cout<<"Seller CHeck\n";
}


void Market::removeVehicle(Vehicle *v)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i] == v)
        {
            inventory.erase(inventory.begin() + i);
            return;
        }
    }
}

void Market::displayInventory()
{
    cout<<"\n->>>INVENTORY<<<-\n";
    for (int i = 0; i < inventory.size(); i++)
    {
        inventory[i]->printInfo();
    }

    cout<<"\n<----INVENTORY ENDS---->\n";
}

void Market::displaySVehicle()
{
    cout << "enter the number plate of the vehicle you would like to see:\n";
    string s;
    cout << "enter state: ";
    cin >> s;
    int n;
    cout << "\nenter number: ";
    cin >> n;
    cout << endl;

    NumberPlate temp(s, n);

    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i]->getNumberPLate() == temp)
        {
            inventory[i]->printInfo();
        }
    }
}

vector<Vehicle *> Market::getInventory()
{
    return inventory;
}

vector<Vehicle*> Market::getInventoryHistory()
{
    return inventoryHistory;
}
