#include "Registration.h"
#include "Owner.h"
#include "Vehicle.h"
using namespace std;


vector <Registration*> Registration:: trackRegistration;

Registration:: Registration(Vehicle *v, Owner *o, bool r, int i)
{
    rvehicle=v;
    rowner=o;
    regStatus=r;
    regID=i;
    time_t tmnow;
    tmnow=time(NULL);
    struct tm t=*localtime(&tmnow);
    regDate=new date(t.tm_mday,t.tm_mon+1,t.tm_year+1900); //using ctime to store current date for registration
    rvehicle->addRegistration(this);
    trackRegistration.push_back(this);

}


void Registration:: setRegStatus(bool a)
{
    regStatus=a;

}

bool Registration:: getRegStatus()
{
    return regStatus;
}


void Registration:: displayRegistration()
{
    cout<<"\n->>>Registration details<<<- \n";
    cout<<"Registration date: "<<*regDate<<endl;
    cout<<"Registration Status: ";
    if (regStatus==true)
    cout<<"Registration is valid\n";
    else
    cout<<"Registration has expired\n";
    cout<<"Registration ID: "<<regID<<endl;
    cout<<"<---------------------------------------------->\n";

}

void Registration::displayDetailedReg()
{
    this->displayRegistration();
    this->rowner->displayOwner();
    this->rvehicle->displayInfo();
}



vector <Registration*> Registration::getTrackRegistration()
{
    return trackRegistration;
}
