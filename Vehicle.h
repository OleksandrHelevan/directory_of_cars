#ifndef DIRECTORY_OF_CARS_VEHICLE_H
#define DIRECTORY_OF_CARS_VEHICLE_H

#include <iostream>
#include "Engine.h"
using namespace std;

class Vehicle {
Engine engine;
double weight;
double fuel_consumption;
int mileage;
string color;
string brand;
string model;
int year;
string location;
int price;

public:
    Vehicle();
    ~Vehicle();
};


#endif //DIRECTORY_OF_CARS_VEHICLE_H
