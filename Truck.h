#ifndef DIRECTORY_OF_CARS_TRUCK_H
#define DIRECTORY_OF_CARS_TRUCK_H

#include <iostream>
#include "Vehicle.h"
#include <list>
using namespace std;

class Truck :public Vehicle{
int cargo_capacity;

public:
    Truck();
    Truck(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
          string& bran, string& mod, int new_year, string& loc, int new_price, int cargo);
    Truck(int year, string &brand, string &model, string &color);
    friend ostream &operator<<(ostream &os, const Truck &obj);
    friend istream &operator>>(istream &is, Truck &obj);
    ~Truck() override;
    Truck(const Truck& other);
    Truck(Truck&& other) noexcept;
    Truck& operator=(const Truck& other);
    Truck& operator=(Truck&& other) noexcept;
    void get_vehicle() const override;

    bool if_exists(const list<Truck> &trucks);

    [[nodiscard]] bool sort_cargo_capacity_h(int new_cap) const;
    [[nodiscard]] bool sort_cargo_capacity_l(int new_cap) const;
    [[maybe_unused]] [[nodiscard]] int get_cargo_capacity() const;
    [[maybe_unused]] void set_cargo_capacity(int new_cargo);
};


#endif //DIRECTORY_OF_CARS_TRUCK_H
