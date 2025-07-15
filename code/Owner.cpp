#include "Owner.h"
#include "Vehicle.h"
#include "Market.h"
using namespace std;

vector<Owner *> Owner::recordOwners;

Owner::Owner()
{
    name = "";
    userID = 0;
    profession = "";
    recordOwners.push_back(this);
}

Owner::Owner(string n, int id, string p, vector<Vehicle *> v)
{
    name = n;
    userID = id;
    profession = p;
    vehicleO = v;
    inusevehicle = v;

    for (int i = 0; i < v.size(); i++)
    {
        vehicleO[i]->addOwner(this);
        vehicleO[i]->setStatus(true);

        Registration *temp = new Registration(vehicleO[i], this, true, rand());
        vehicleO[i]->addRegistration(temp);
    }
    recordOwners.push_back(this);
}

void Owner::displayOwner()
{
    cout << "\n->>>Owner Details<<<- \n";
    cout << "owner ID: " << userID << endl;
    cout << "owner name: " << name << endl;
    cout << "Owner Profession: " << profession << endl;
    cout << "<---------------------------------------------->\n";
}

void Owner::displayOwnerDetail()
{
    cout << "\n->>>Owner Details<<<- \n";
    cout << "owner name is: " << name << endl;
    cout << "Owner Profession is: " << profession << endl;
    cout << "<---------------------------------------------->\n";
    if (inusevehicle.empty() == true)
    {
        cout << "\nOwner does not own any vehicles\n";
    }
    else
    {
        cout << "\n->>>OWNER VEHICLES<<<-\n";
        for (int i = 0; i < inusevehicle.size(); i++)
        {
            inusevehicle[i]->displayInfo();
        }
    }
}

void Owner::sell(Market *market)
{
    cout << "enter the number plate of the vehicle you would like to sell:\n";
    string s;
    cout << "enter state: ";
    cin >> s;
    int n;
    cout << "\nenter number: ";
    cin >> n;
    cout << endl;
    int option;
    NumberPlate temp(s, n);
    for (int i = 0; i < vehicleO.size(); i++)
    {
        if (inusevehicle[i]->getNumberPLate() == temp)
        {
            cout << "Do you want to sell to user or market?\n";
            cout << "1: user\n2: Market\n";
            cout << "Enter choice: ";
            cin >> option;
            cout << endl;
            if (option == 2)
            {
                inusevehicle[i]->setStatus(false);
                inusevehicle[i]->getRegs().back()->setRegStatus(false);
                market->addVehicle(inusevehicle[i]);
                market->addOwner(this);
                inusevehicle.erase(inusevehicle.begin() + i);
                cout << "\n->>vehicle has been sold<<-\n";
                return;
            }
            if (option == 1)
            {
                int id;
                cout << "Enter user id: ";
                cin >> id;
                cout << endl;
                bool flg = false;
                for (int k = 0; k < recordOwners.size(); k++)
                {
                    if (recordOwners[k]->getOwnerID() == id)
                    {
                        flg = true;
                        recordOwners[k]->vehicleO.push_back(this->vehicleO[i]);
                        recordOwners[k]->inusevehicle.push_back(this->vehicleO[i]);
                        vehicleO[i]->addOwner(recordOwners[k]);
                        Registration *tempR = new Registration(vehicleO[i], recordOwners[k], true, rand());
                        vehicleO[i]->addRegistration(tempR);
                        inusevehicle.erase(inusevehicle.begin() + i);
                        cout << "\n->>vehicle has been sold<<-\n";
                        return;
                    }
                }
                if (flg = false)
                {
                    cout << "User with this id does not exist\n";
                    return;
                }
            }
        }
    }

    cout << "there is no vehicle with this numberplate\n";
}

int Owner::getOwnerID()
{
    return userID;
}

void Owner::buyVehicle(Market *market)
{
    int choice;
    cout << "from whom would you like to buy the vehicle from?\n";
    cout << "1: User\n";
    cout << "2: Market\n";
    cout << "\n please enter your choice: ";
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {
        vector<Owner *> to = Owner::getRecordOwners();
        int id;
        cout << "Enter the user ID of the Owner you would like to buy from: ";
        cin >> id;
        cout << endl;
        bool flg = false;
        for (int i = 0; i < to.size(); i++)
        {
            if (to[i]->getOwnerID() == id)
            {
                flg = true;
                vector<Vehicle *> tempV = to[i]->getInUseVehicle();
                if (tempV.empty() != true)
                {
                    cout << "\nThis Owner has the following Vehicles: \n";
                    for (int j = 0; j < tempV.size(); j++)
                    {
                        tempV[j]->printInfo();
                    }
                    cout << "enter the number plate of the vehicle you would like to buy:\n";
                    string s;
                    cout << "enter state: ";
                    cin >> s;
                    int n;
                    cout << "\nenter number: ";
                    cin >> n;
                    cout << endl;
                    NumberPlate tempN(s, n);
                    bool flgtwo = false;
                    for (int k = 0; k < tempV.size(); k++)
                    {
                        if (tempV[k]->getNumberPLate() == tempN)
                        {
                            flg = true;
                            tempV[k]->addOwner(this);
                            this->vehicleO.push_back(tempV[k]);
                            this->inusevehicle.push_back(tempV[k]);
                            Registration *tempR = new Registration(tempV[i], this, true, rand());
                            tempV[i]->addRegistration(tempR);
                            tempV.erase(tempV.begin() + k);
                            cout << "\n->vehicle has been bought<-\n";
                            return;
                        }
                    }
                    if (flgtwo = false)
                    {
                        cout << "\nOwner does not have this Vehicle\n";
                        return;
                    }
                }
                else
                {
                    cout << "Owner Does not own any Vehicle\n";
                    return;
                }
            }
        }
        if (flg == false)
        {
            cout << "There is no owner with this ID\n";
            return;
        }
    }

    if (choice == 2)
    {
        cout << "These are the vehicles available: \n";
        market->displayInventory();
        cout << endl;
        cout << "enter the number plate of the vehicle you would like to buy:\n";
        string s;
        cout << "enter state: ";
        cin >> s;
        int n;
        cout << "\nenter number: ";
        cin >> n;
        cout << endl;

        NumberPlate temp(s, n);

        vector<Vehicle *> tempINV = market->getInventory();
        for (int i = 0; i < tempINV.size(); i++)
        {
            if (tempINV[i]->getNumberPLate() == temp)
            {
                tempINV[i]->setStatus(true);
                Registration *tempR = new Registration(tempINV[i], this, true, rand());
                tempINV[i]->addRegistration(tempR);
                tempINV[i]->addOwner(this);
                market->removeVehicle(tempINV[i]);
                inusevehicle.push_back(tempINV[i]);
                vehicleO.push_back(tempINV[i]);
                cout << "\n->vehicle has been bought<-\n";
                return;
            }
        }
        cout << "\n->>There is no vehicle available with this numberplate<<-\n";
    }

    if (choice < 1 || choice > 2)
    {
        cout << "\nWrong Choice!\n";
        return;
    }
}

vector<Owner *> Owner::getRecordOwners()
{
    return recordOwners;
}

vector<Vehicle *> Owner::getInUseVehicle()
{
    return inusevehicle;
}

void Owner::searchOwner()
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

void Owner::searchVehicle()
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