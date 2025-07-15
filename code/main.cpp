#include "Market.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "Owner.h"
#include "Admin.h"
#include "VRMS.h"

int main()
{

    Market *market = new Market();
    // Create some vehicles
    Car car("Toyota", "Blue", "NY", 1234, 1, 1, 2022, false, "Car", 4, "Gasoline");
    Bike bike("Honda", "Red", "CA", 5678, 2, 2, 2023, false, "Bike", "Sports Bike", 500);
    Truck truck("Ford", "White", "TX", 9876, 3, 3, 2024, false, "Truck", 2000.0, 2);
    Car car1("Ford", "Black", "LA", 2468, 4, 15, 2022, false,"Car", 5, "Electric");
    Car car2("Chevrolet", "Silver", "FL", 1357, 6, 20, 2023, false, "Car", 3, "Diesel");
    Bike bike1("Kawasaki", "Green", "TX", 9876, 8, 10, 2022, false, "Bike", "Touring", 1000);
    Bike bike2("Yamaha", "Yellow", "AZ", 6543, 9, 5, 2023, false, "Bike", "Dirt Bike", 250);
    Truck truck1("GMC", "Gray", "NV", 5432, 11, 25, 2022, false, "Truck", 5000.0, 3);
    Truck truck2("RAM", "Red", "OH", 8765, 12, 30, 2023, false, "Truck", 8000.0, 2);
    // Add vehicles to market
    market->addVehicle(&car1);
    market->addVehicle(&bike1);
    market->addVehicle(&truck1);
    market->addVehicle(&car2);
    market->addVehicle(&bike2);
    market->addVehicle(&truck2);

    // Create an owner
    Owner owner("John Doe", 1, "Engineer", {&car});
    Owner owner1("Saim Shah", 2, "Accountant", {&bike});
    Owner owner2("OZ", 3, "Developer", {&truck});
    Owner owner3("Ahmad", 4, "Assistant Comissioner", {});


    Admin a(10,"Aamil","Aamil@CS200");
    Admin b(20,"Aaqib","Aaqib@CS200");

    VRMS system(market);
    system.menu();

    

    return 0;
}
