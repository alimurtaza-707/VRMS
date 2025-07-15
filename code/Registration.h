#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <ctime>
#include "util.h"
#include <string>
#include <vector>
using namespace std;

class Vehicle;
class Owner;

class Registration
{
    protected:
    Vehicle* rvehicle;
    Owner* rowner;
    date* regDate;
    bool regStatus;
    int regID;
    static vector <Registration*> trackRegistration;

    public:
    Registration(){};
    Registration(Vehicle *v, Owner *o, bool r, int i);
    void setRegStatus(bool a);
    bool getRegStatus();
    static vector <Registration*> getTrackRegistration(); ////to store all Registrations and use in VRMS
    void displayRegistration();
    void displayDetailedReg();
   


};

#endif