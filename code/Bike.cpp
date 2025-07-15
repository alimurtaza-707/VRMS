#include "Bike.h"
using namespace std;

Bike:: Bike()
{
    bikeType="";
    engineDisplacement=0.0;

}

Bike::Bike(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t, string bt, float d): Vehicle(m,c,state,num,dd,mm,yy,s,t)
{    
    bikeType=bt;
    engineDisplacement=d;
}

void Bike:: printInfo()
{
    Vehicle:: displayInfo();
    cout<<"The type of bike: "<<bikeType<<endl;
    cout<<"the Engine Displacement: "<<engineDisplacement<<endl;
    cout<<"<---------------------------------------------->\n";
}

void Bike::printRegistration()
{
    registration.back()->displayRegistration();

}
void Bike::printOwners()
{
    if (this->getStatus()==false)
    {
    cout<<"The vehicle is not owned by anyone\n";
    }
    else
    owner.back()->displayOwner();
}

void Bike:: detailedinfo()
{
    Vehicle:: displayInfo();
    cout<<"The type of bike: "<<bikeType<<endl;
    cout<<"the Engine Displacement: "<<engineDisplacement<<endl;
    cout<<"<---------------------------------------------->\n";
    printOwners();
    if (registration.empty()!=1)
    printRegistration();
    else
    cout<<"->>>Vehicle is not Registered<<<-\n";
}