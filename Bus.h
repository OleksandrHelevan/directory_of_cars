
#ifndef DIRECTORY_OF_CARS_BUS_H
#define DIRECTORY_OF_CARS_BUS_H

#include <iostream>
#include "Vehicle.h"
using namespace std;

class Bus :public Vehicle {
    int passenger_capacity;
public:
    Bus();
    Bus(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
    string& bran, string& mod, int new_year, string& loc, int new_price, int cap);
    friend ostream &operator<<(ostream &os, const Bus &obj);
    friend istream &operator>>(istream  &is, Bus &obj);
    ~Bus(){cout<<"bus was deleted";};
    Bus(const Bus& other);
    Bus(Bus&& other) noexcept;
    Bus& operator=(const Bus& other);
    Bus& operator=(Bus&& other) noexcept;

    void getVehicle() const override;
};


#endif //DIRECTORY_OF_CARS_BUS_H
