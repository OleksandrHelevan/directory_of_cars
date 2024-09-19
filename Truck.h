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
    ~Truck() override;
    Truck(const Truck& other);
    Truck(Truck&& other) noexcept;
    Truck& operator=(const Truck& other);
    Truck& operator=(Truck&& other) noexcept;
    void getVehicle() const override;

    [[nodiscard]] bool sortcargo_capacity_h(int newcap) const;
    [[nodiscard]] bool sortcargo_capacity_l(int newcap) const;
    [[maybe_unused]] [[nodiscard]] int getcargo_capacity() const;
    [[maybe_unused]] void setcargo_capacity(int newcargo);
};


#endif //DIRECTORY_OF_CARS_TRUCK_H
