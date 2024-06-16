#ifndef DIRECTORY_OF_CARS_VEHICLE_H
#define DIRECTORY_OF_CARS_VEHICLE_H

#include <iostream>
#include "Engine.h"
using namespace std;

class Vehicle {
Engine engine;
int weight;
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
    Vehicle(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
            string& bran, string& mod, int new_year, string& loc, int new_price);
    friend ostream &operator<<(ostream &os, const Vehicle &obj);
    friend istream &operator>>(istream &is, Vehicle &obj);
    ~Vehicle(){cout<<"was deleted"<<endl;};
};


#endif //DIRECTORY_OF_CARS_VEHICLE_H
