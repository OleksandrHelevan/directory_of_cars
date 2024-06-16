#ifndef DIRECTORY_OF_CARS_TRUCK_H
#define DIRECTORY_OF_CARS_TRUCK_H

#include <iostream>
#include "Vehicle.h"
using namespace std;

class Truck :public Vehicle{
int cargo_capacity;

public:
    Truck();
    Truck(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
          string& bran, string& mod, int new_year, string& loc, int new_price, int cargo);
    friend ostream &operator<<(ostream &os, const Truck &obj);
    friend istream &operator>>(istream &is, Truck &obj);
    ~Truck(){cout<<"truck was deleted";};
};


#endif //DIRECTORY_OF_CARS_TRUCK_H
