#include <iostream>
using namespace std;

class Vehicle {
public:
    string brand;
    string model;
    int year;

    Vehicle(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    virtual string GetInfo() {
        return to_string(year) + " " + brand + " " + model;
    }
};

class Car : public Vehicle {
public:
    int numDoors;

    Car(string b, string m, int y, int doors) : Vehicle(b, m, y) {
        numDoors = doors;
    }

    string GetInfo() {
        return Vehicle::GetInfo() + " (Doors: " + to_string(numDoors) + ")";
    }
};

class Motorcycle : public Vehicle {
public:
    bool hasSidecar;

    Motorcycle(string b, string m, int y, bool sidecar) : Vehicle(b, m, y) {
        hasSidecar = sidecar;
    }

    string GetInfo() {
        string sidecarStatus;
        if (hasSidecar)
            sidecarStatus = "Yes";
        else
            sidecarStatus = "No";

        return Vehicle::GetInfo() + " (Has Sidecar: " + sidecarStatus + ")";
    }
};

int main() {
    Car myCar("Toyota", "Camry", 2022, 4);
    Motorcycle myBike("Harley-Davidson", "Iron 883", 2021, false);

    cout << "Car Info: " << myCar.GetInfo() << endl;
    cout << "Motorcycle Info: " << myBike.GetInfo() << endl;

    return 0;
}