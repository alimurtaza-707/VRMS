#include "Admin.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "Owner.h"
#include "Owner.h"
#include "Market.h"
using namespace std;

vector<Admin *> Admin::allAdmins;

Admin::Admin(int id, string n, string e)
{
    accessID = id;
    name = n;
    email = e;
    allAdmins.push_back(this);
}

void Admin::detailedView()
{
    vector<Vehicle *> tv = Vehicle::getTotalVehicles();
    vector<Owner *> to = Owner::getRecordOwners();
    vector<Registration *> reg = Registration::getTrackRegistration();
    vector<Vehicle *> ih = Market::getInventoryHistory();
    int i = 0;
    int j = 0;
    cout << "\n->>>ANALYIS<<<-\n";
    cout << "Total Vehicles: " << tv.size() << endl;
    cout << "Total Vehicles owned: ";
    for (j; j < tv.size(); j++)
    {
        if (tv[j]->getStatus() == true)
            i++;
        // cout<<i;
    }
    cout << i << endl;
    // cout<<"Total Vehicles ever been to Market: "<<ih.size()<<endl;
    cout << "Vehicles available in Market: " << tv.size() - i << endl;
    cout << "Total Registrations: " << reg.size() << endl;
    ;
    i = 0;
    j = 0;
    for (j; j < reg.size(); j++)
    {
        if (reg[i]->getRegStatus() == true)
            i++;
    }
    cout << "Valid Registrations: " << i << endl;
    cout << "Expired Registrations: " << reg.size() - i << endl;
    cout << "<-------------------------------------------------->\n";
}

void Admin::searchOwner()
{
    vector<Owner *> to = Owner::getRecordOwners();
    int id;
    cout << "Enter the ID of the owner you want to search for: \n";
    cin >> id;
    cout << endl;
    int option;
    cout << "Do you want detailed information or brief\n";
    cout << "1: Brief\n2: Detailed\n";
    cout << "Enter choice: ";
    cin >> option;
    bool flg = false;
    if (option > 0 && option < 3)
    {
        for (int i = 0; i < to.size(); i++)
        {
            if (to[i]->getOwnerID() == id)
            {
                flg = true;
                if (option == 1)
                    to[i]->displayOwner();
                if (option == 2)
                {
                    to[i]->displayOwnerDetail();
                }
            }
        }
        if (flg = false)
            cout << "There is no user with this ID\n";
    }
    else
    {
        cout << "Wrong option!\nTry again from the menu\n";
        return;
    }
}

void Admin::searchVehicle()
{
    vector<Vehicle *> veh = Vehicle::getTotalVehicles();
    cout << "enter the number plate of the vehicle you would like to search:\n";
    string s;
    cout << "enter state: ";
    cin >> s;
    int n;
    cout << "\nenter number: ";
    cin >> n;
    cout << endl;

    NumberPlate temp(s, n);

    int option;
    cout << "Do you want detailed information or brief\n";
    cout << "1: Brief\n2: Detailed\n";
    cout << "Enter choice: ";
    cin >> option;
    bool flg = false;
    if (option > 0 && option < 3)
    {
        for (int i = 0; i < veh.size(); i++)
        {
            if (veh[i]->getNumberPLate() == temp)
            {

                if (option == 1)
                    veh[i]->printInfo();
                if (option == 2)
                {
                    veh[i]->detailedinfo();
                }
            }
        }
        if (flg = false)
            cout << "There is no Vehicle with this Number Plate\n";
    }
    else
    {
        cout << "Wrong option!\nTry again from the menu\n";
        return;
    }
}

void Admin::addOwnerinSystem()
{
    string n;
    int id;
    string p;
    cout << "enter name of the owner you want to add: ";
    cin >> n;
    cout << endl;
    cout << "enter user ID: ";
    cin >> id;
    cout << endl;
    vector<Owner *> check = Owner::getRecordOwners();
    for (int i = 0; i < check.size(); i++)
    {
        if (check[i]->getOwnerID() == id)
        {
            cout << "Owner with this ID already exists\n";
            cout << "Try again by selecting from the menu again\n";
            return;
        }
    }
    cout << "enter profession: ";
    cin >> p;
    cout << endl;

    Owner *newO = new Owner(n, id, p, {});

    cout << "\n->>>Owner has been Added<<<-\n";
}

void Admin::addVehicleinSystem(Market *market)
{
    cout << "Which type of Vehicle would you like to add in the system?\n";
    int choice;
    cout << "1: Car\n2: Bike\n3: Truck\nchoice: ";
    cin >> choice;
    cout << endl;
    if (choice < 4 && choice > 0)
    {
        string manu;
        string color;
        string state;
        int num;
        int dd, mm, yy;
        string type;

        cout << "Enter Manufacturer of the car: ";
        cin >> manu;
        cout << endl;
        cout << "Enter Color of the car: ";
        cin >> color;
        cout << endl;
        cout << "enter the number plate of the vehicle \n";
        cout << "enter state: ";
        cin >> state;
        cout << "\nenter number: ";
        cin >> num;
        cout << endl;
        cout << "Enter the Manufacturing Date:\n";
        cout << "day: ";
        cin >> dd;
        cout << endl;
        cout << "month: ";
        cin >> mm;
        cout << endl;
        cout << "year: ";
        cin >> yy;
        cout << endl;
        if (choice == 1)
        {
            type = "Car";
            int nod;
            string tf;
            cout << "Enter number of doors: ";
            cin >> nod;
            cout << endl;
            cout << "Enter the fuel type: ";
            cin >> tf;
            cout << endl;
            Car *temp = new Car(manu, color, state, num, dd, mm, yy, false, type, nod, tf);
            cout << "\n->>>CAR HAS BEEN ADDED<<<-\n";
            market->addVehicle(temp);
            return;
        }

        if (choice == 2)
        {
            type = "Bike";
            string bt;
            float ed;
            cout << "Enter Bike type: ";
            cin >> bt;
            cout << endl;
            cout << "Enter Engine Displacement: ";
            cin >> ed;
            cout << endl;

            Bike *temp = new Bike(manu, color, state, num, dd, mm, yy, false, type, bt, ed);
            cout << "\n->>>BIKE HAS BEEN ADDED<<<-\n";
            market->addVehicle(temp);
            return;
        }

        if (choice == 3)
        {
            type = "Truck";
            float cap;
            int ax;
            cout << "Enter Capacity of Truck: ";
            cin >> cap;
            cout << endl;
            cout << "Enter number of axels: ";
            cin >> ax;
            cout << endl;

            Truck *temp = new Truck(manu, color, state, num, dd, mm, yy, false, type, cap, ax);
            cout << "\n->>>TRUCK HAS BEEN ADDED<<<-\n";
            market->addVehicle(temp);
            return;
        }
    }
    else
    {
        cout << "\nWRONG INPUT!\nchoose again from the main menu\n";
        return;
    }
}

int Admin::getAccessID()
{
    return accessID;
}

void Admin::displayAdmin()
{
    cout << "\n->>>ADMIN DETAILS<<<-\n";
    cout << "Admin Access ID: " << accessID << endl;
    cout << "Admin name: " << name << endl;
    cout << "Admin Email: " << email << endl;
}

vector<Admin *> Admin::getAllAdmins()
{
    return allAdmins;
}

void Admin::displayOwnerVehicle()
{
    cout << "enter the number plate of the vehicle you would like to search registration of:\n";
    string s;
    cout << "enter state: ";
    cin >> s;
    int m;
    cout << "\nenter number: ";
    cin >> m;
    cout << endl;
    NumberPlate tempn(s, m);
    int id;
    cout << "enter the userID of the user you want to find with this corresponding Vehicle:";
    cin >> id;
    cout << endl;

    int j = 0;
    vector<Vehicle *> totalV = Vehicle::getTotalVehicles();
    bool flg=false;
    for (j; j < totalV.size(); j++)
    {
        if (totalV[j]->getNumberPLate() == tempn)
        {
            flg=true;
            vector<Owner *> tempowners = totalV[j]->getOwners();
            vector<Registration *> temp = totalV[j]->getRegs();
            bool flgtwo=false;
            for (int k = 0; k < tempowners.size(); k++)
            {
                if (tempowners[k]->getOwnerID() == id)
                {
                    flgtwo=true;
                    temp[k]->displayRegistration();
                    return;
                }
            }
            if (flgtwo==false)
            {
                cout<<"No user with this ID\n";
                return;
            }
        }
    }
    if (flg==true)
    {
        cout<<"No vehicle with this NumberPlate\n";
        return;
    }


}