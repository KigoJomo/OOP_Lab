#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle
{
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string make, string model, int year)
        : make(make), model(model), year(year) {}

    virtual void displayInfo()
    {
        cout << "Make: " << make << "\nModel: " << model << "\nYear: " << year << endl;
    }

    virtual ~Vehicle() {}
};

// Derived class
class Car : public Vehicle
{
private:
    int numDoors;
    string fuelType;

public:
    Car(string make, string model, int year, int numDoors, string fuelType)
        : Vehicle(make, model, year), numDoors(numDoors), fuelType(fuelType) {}

    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Number of Doors: " << numDoors << "\nFuel Type: " << fuelType << endl;
    }

    void startEngine()
    {
        cout << "Starting engine of " << make << " " << model << endl;
    }

    ~Car() {}
};

int main()
{
    Car myCar("Toyota", "Corolla", 2021, 4, "Gasoline");
    myCar.displayInfo();
    myCar.startEngine();

    return 0;
}
