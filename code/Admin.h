#ifndef ADMIN_H
#define ADMIN_H
#include "util.h"
#include <vector>
using namespace std;

class Vehicle;
class Car;
class Bike;
class Truck;
class Owner;
class registration;
class Market;


class Admin
{
    protected:
    int accessID;
    string name;
    string email;
    static vector<Admin*> allAdmins; //to store all admins and use in VRMS

    public:
    Admin(){};
    Admin(int id, string n, string e);
    void detailedView();
    void searchOwner();
    void searchVehicle();
    void addOwnerinSystem();
    void addVehicleinSystem(Market* market);
    int getAccessID();
    void displayAdmin();
    static vector <Admin*> getAllAdmins();
    void displayOwnerVehicle(); //search for registration in admin so no object of registration has to be used in VRMS

};

#endif