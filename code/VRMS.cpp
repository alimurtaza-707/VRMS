#include "VRMS.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "Owner.h"
#include "Registration.h"
#include "Market.h"
#include "Admin.h"
using namespace std;

VRMS::VRMS(Market *m)
{
    vehiclesInSystem = Vehicle::getTotalVehicles();
    ownersInSytem = Owner::getRecordOwners();
    registrationsInSystem = Registration::getTrackRegistration();
    market = m;
    adminsInSystem = Admin::getAllAdmins();
}

void VRMS::menu()
{
    int login;
    do
    {
        cout << "\n->>>WELCOME TO VRMS<<<-\n";
        cout << "LOGIN AS:\n";
        cout << "0: Exit Program\n1: Admin\n2: User\n";
        cout << "Enter choice: ";
        cin >> login;
        cout << "\n\n";
        if (login == 0)
        {
            cout << "\n->>>EXITING PROGRAM...<<<-\n";
            return;
        }

        if (login == 1)
        {
            int authID;
            cout << "\nEnter your accessID: ";
            cin >> authID;
            cout << endl;
            bool flg = false;
            Admin *admin;
            for (int j = 0; j < adminsInSystem.size(); j++)
            {
                if (authID == adminsInSystem[j]->getAccessID())
                {
                    flg = true;
                    admin = adminsInSystem[j];
                    break;
                }
            }
            if (flg == true)
            {
                int log;
                do
                {
                    cout << "\n->>>WELCOME ADMIN<<<-\nPlease choose from the following options: \n";
                    cout << "1: Get the Analysis of the system\n"
                         << "2: Search for an Owner\n"
                         << "3: Search for a Vehicle\n"
                         << "4: Add an Owner\n"
                         << "5: Add a Vehicle\n"
                         << "6: View Market Inventory\n"
                         << "7: Show all Vehicles\n"
                         << "8: Show all Owners\n"
                         << "9: Show all Registrations\n"
                         << "10: Show Admins\n"
                         <<"11: Search for Registration\n"
                         << "0: Go Back\n";
                    cout << "Enter your choice: ";
                    cin >> log;
                    cout << endl;
                    switch (log)
                    {
                    case 1:
                        vehiclesInSystem = Vehicle::getTotalVehicles();             // to update in system objects during run time
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        admin->detailedView();

                        break;
                    case 2:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        admin->searchOwner();

                        break;
                    case 3:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        admin->searchVehicle();

                        break;
                    case 4:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        admin->addOwnerinSystem();

                        break;
                    case 5:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        admin->addVehicleinSystem(market);

                        break;
                    case 6:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        market->displayInventory();

                        break;
                    case 7:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        for (int i = 0; i < vehiclesInSystem.size(); i++)
                        {
                            vehiclesInSystem[i]->printInfo();
                        }

                        break;
                    case 8:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        for (int i = 0; i < ownersInSytem.size(); i++)
                        {
                            ownersInSytem[i]->displayOwner();
                        }

                        break;
                    case 9:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        for (int i = 0; i < registrationsInSystem.size(); i++)
                        {
                            registrationsInSystem[i]->displayRegistration();
                        }

                        break;
                    case 10:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        for (int i = 0; i < adminsInSystem.size(); i++)
                        {
                            adminsInSystem[i]->displayAdmin();
                        }

                        break;
                    case 11:
                        admin->displayOwnerVehicle();
                    break;
                    case 0:
                        log = 0;
                        flg = false;
                        cout << "\n<<<-GOING BACK...\n";
                        break;

                    default:
                        cout << "WRONG INPUT!\n Please try again\n";
                        break;
                    }
                } while (log != 0);
            }
            else
            {
                cout << "\n->>>WRONG ID<<<-\n";
                login = -1;
            }
        }

        if (login == 2)
        {
            int userID;
            cout << "\nEnter your ownerID: ";
            cin >> userID;
            cout << endl;
            bool flg = false;
            Owner *owner;
            for (int j = 0; j < ownersInSytem.size(); j++)
            {
                if (userID == ownersInSytem[j]->getOwnerID())
                {
                    flg = true;
                    owner = ownersInSytem[j];
                    break;
                }
            }
            if (flg == true)
            {
                int log;
                do
                {
                    cout << "\n->>>WELCOME OWNER<<<-\nPlease choose from the following options: \n";
                    cout << "1: Get your own Information\n"
                         << "2: Search for an Owner\n"
                         << "3: Search for a Vehicle\n"
                         << "4: View Market Inventory\n"
                         << "5: Buy a Vehicle\n"
                         << "6: Sell a Vehicle\n"
                         << "0: Go Back\n";
                    cout << "Enter your choice: ";
                    cin >> log;
                    cout << endl;
                    switch (log)
                    {
                    case 1:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        owner->displayOwnerDetail();

                        break;
                    case 2:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        owner->searchOwner();

                        break;
                    case 3:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        owner->searchVehicle();

                        break;
                    case 4:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        market->displayInventory();

                        break;
                    case 5:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        owner->buyVehicle(market);

                        break;
                    case 6:
                        vehiclesInSystem = Vehicle::getTotalVehicles();
                        ownersInSytem = Owner::getRecordOwners();
                        registrationsInSystem = Registration::getTrackRegistration();
                        owner->sell(market);

                        break;
                    case 0:
                        log = 0;
                        flg = false;
                        cout << "\n<<<-GOING BACK...\n";
                        break;

                    default:
                        cout << "WRONG INPUT!\n Please try again\n";
                        break;
                    }
                } while (log != 0);
            }
            else
            {
                cout << "\n->>>WRONG ID<<<-\n";
                login = -1;
            }
        }

    } while (login != 0);
}