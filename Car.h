
#ifndef DIRECTORY_OF_CARS_CAR_H
#define DIRECTORY_OF_CARS_CAR_H

#include <iostream>
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle {
string wheel_drive;
string transmission;
public:
    Car();
    Car(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
        string& bran, string& mod, int new_year, string& loc, int new_price, string& wh_dr, string& tran);
    friend ostream &operator<<(ostream &os, const Car &obj);
    friend istream &operator>>(istream &is, Car &obj);
    void getVehicle() const override;
    ~Car(){cout<<"car ";};
    Car(const Car& other);
    Car(Car&& other) noexcept;
    Car& operator=(const Car& other);
    Car& operator=(Car&& other) noexcept;

};


#endif //DIRECTORY_OF_CARS_CAR_H
