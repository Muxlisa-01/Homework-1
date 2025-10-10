#ifndef Vehicle_h
#define Vehicle_h
#include <iostream>
using namespace std;

class Vehicle {
private:
    string brand;
    int year;
    static int totalVehicles;
public:
    Vehicle(string brand, int year){
        this->brand=brand;
        this->year=year;
        totalVehicles++;
        cout<<"Vehicle constructor is called\n";
    }
    void displayVehicle(){
        cout<<"Brand:"<<brand<<endl;
        cout<<"Year:"<<year<<endl;
    }
    static int getTotal(){
        return totalVehicles;
    }

    ~Vehicle(){
        cout<<"Vehicle is destoyed\n"<<endl;
    }
};

int Vehicle::totalVehicles = 0;

#endif /* Vehicle_h */



#ifndef Car_h
#define Car_h
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Car : public Vehicle{
private:
    int doors;
public:
    Car(string brand, int year, int doors):Vehicle(brand, year), doors(doors){
        this->doors=doors;
        cout<<"Car constructor is called\n";
    }
    void displayCar() {
        displayVehicle();
        cout<<"Doors:"<<doors<<endl;
    }
    
    ~Car(){
        cout<<"Car is destroyed\n"<<endl;
    }

};

#endif /* Car_h */



#ifndef ElectricCar_h
#define ElectricCar_h
#include "Car.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;

class ElectricCar: public Car {
private:
    int batteryRange;
public:
    ElectricCar(string brand, int year, int doors, int battery):Car(brand, year, doors), batteryRange(battery){
        cout<<"ElectricCar cunstructor is called\n";
    }

    void dispayElectricCar() {
        displayVehicle();
        displayCar();
        cout<<"Battery Range"<<batteryRange<<"km"<<endl;
    }
    
    ~ElectricCar() {
        cout<<"Electric car is destroyed\n"<<endl;
    }


};

#endif /* ElectricCar_h */

