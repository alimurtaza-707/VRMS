#include "Car.h"
using namespace std;

Car::Car()
{
    noOfDoors=0;
    typeFuel="";
}

Car::Car(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t, int i, string f): Vehicle(m,c,state,num,dd,mm,yy,s,t)
{
    noOfDoors=i;
    typeFuel=f;
}

void Car:: printInfo()
{
    Vehicle:: displayInfo();
   
    cout<<"number of doors of the car: "<<noOfDoors<<endl;
    cout<<"the fuel type: "<<typeFuel<<endl;
    cout<<"<---------------------------------------------->\n";

}

void Car::printRegistration()
{
    //cout<<"hello\n";
    registration.back()->displayRegistration();
}

void Car::printOwners()
{
    if (this->getStatus()==false)
    cout<<"The vehicle is not owned by anyone\n";
    else
    owner.back()->displayOwner();
}

void Car:: detailedinfo()
{
    Vehicle:: displayInfo();
   
    cout<<"number of doors of the car: "<<noOfDoors<<endl;
    cout<<"the fuel type: "<<typeFuel<<endl;
    cout<<"<---------------------------------------------->\n";
    printOwners();
    if (registration.empty()!=1)
    printRegistration();
    else
    cout<<"->>>Vehicle is not Registered<<<-\n";
}