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

    bool sort_capacity_l(double cap);
    bool sort_power_l(double pow);
    bool sort_capacity_h(double cap);
    bool sort_power_h(double pow);
    bool sort_fuel(string &fuel1);
    [[nodiscard]] bool sort_weight_l(int weigh) const;
    [[nodiscard]] bool sort_weight_h(int weigh) const;
    [[nodiscard]] bool sort_consumption_l(double cons) const;
    [[nodiscard]] bool sort_consumption_h(double cons) const;
    [[nodiscard]] bool sort_milage_l(int mil) const;
    [[nodiscard]] bool sort_milage_h(int mil) const;
    bool sort_color(string &col);
    bool sort_brand(string &bra);
    bool sort_model(string &mod);
    [[nodiscard]] bool sort_year_l(int yea) const;
    [[nodiscard]] bool sort_year_h(int yea) const;
    bool sort_location(string &loc);
    [[nodiscard]] bool sort_price_l(int pric) const;
    [[nodiscard]] bool sort_price_h(int pric) const;
};


#endif //DIRECTORY_OF_CARS_VEHICLE_H
