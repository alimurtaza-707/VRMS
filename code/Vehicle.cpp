#include "Vehicle.h"
using namespace std;

vector <Vehicle*> Vehicle::totalVehicles;

Vehicle::Vehicle()
{
    manufacturer="";
    color="";
    manufactureDate= new date();
    NPV=new NumberPlate();
    ownedStatus=false;
    type=""; 
    totalVehicles.push_back(this);
}

Vehicle:: Vehicle(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t)
{
    manufacturer=m;
    color=c;
    manufactureDate= new date(dd,mm,yy);
    NPV=new NumberPlate(state,num);
    ownedStatus=s;
    type=t;
    totalVehicles.push_back(this);

}

//Vehicle::~Vehicle(){}

void Vehicle:: addOwner(Owner* n)
{
    owner.push_back(n);
}

void Vehicle:: addRegistration(Registration* r)
{
    registration.push_back(r);
}

vector<Registration*> Vehicle::getRegs()
{
    return registration;
}

vector<Owner*> Vehicle::getOwners()
{
    return owner;
}


string Vehicle::getColor()
{
    return color;
}
string Vehicle::getManufacturer()
{
    return manufacturer;
}
NumberPlate Vehicle::getNumberPLate()
{
    return *NPV;
}
string Vehicle::getType()
{
    return type;
}

bool Vehicle:: getStatus()
{
    return ownedStatus;
}

vector <Vehicle*> Vehicle::getTotalVehicles()
{
    return totalVehicles;
}

void Vehicle:: setStatus(bool n)
{
    ownedStatus=n;
}

void Vehicle::displayInfo()
{
    cout<<"\n->>>information of the Vehicle<<<-\n";
    cout<<"Manufacturer: "<<getManufacturer()<<endl;
    cout<<"Manufacturing date: "<<*manufactureDate<<endl;
    cout<<"Color: "<<getColor()<<endl;
    cout<<"NumberPlate: "<<getNumberPLate()<<endl;
    if (getStatus())
    cout<<"Vehicle is owned\n";
    else
    cout<<"Vehicle is available in Market\n";
    cout<<"Vehicle type "<<endl;
    cout<<"->>>"<<getType()<<"<<<-\n";  
}
