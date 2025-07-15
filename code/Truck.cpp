#include "Truck.h"
using namespace std;

Truck:: Truck()
{
    capacity=0.0;
    axles=0;
}

Truck:: Truck(string m, string c, string state, int num, int dd, int mm, int yy, bool s, string t, float cp, int a):Vehicle(m,c,state,num,dd,mm,yy,s,t)
{
    capacity=cp;
    axles=a;
}

void Truck:: printInfo()
{
    Vehicle:: displayInfo();
    cout<<"The Capacity of Truck: "<<capacity<<endl;
    cout<<"Number of axels: "<<axles<<endl;
    cout<<"<---------------------------------------------->\n";
}

void Truck::printRegistration()
{
    registration.back()->displayRegistration();

}
void Truck::printOwners()
{
    if (this->getStatus()==0)
    cout<<"The vehicle is not owned by anyone\n";
    else
    owner.back()->displayOwner();
}

void Truck:: detailedinfo()
{
     Vehicle:: displayInfo();
    cout<<"The Capacity of Truck: "<<capacity<<endl;
    cout<<"Number of axels: "<<axles<<endl;
    cout<<"<---------------------------------------------->\n";
    printOwners();
    if (registration.empty()!=1)
    printRegistration();
    else
    cout<<"->>>Vehicle is not Registered<<<-\n";
}
