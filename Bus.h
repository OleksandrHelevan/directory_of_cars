
#ifndef DIRECTORY_OF_CARS_BUS_H
#define DIRECTORY_OF_CARS_BUS_H

#include <iostream>
#include "Vehicle.h"
#include <list>
using namespace std;

class Bus :public Vehicle {
    int passenger_capacity;
public:
    Bus();
    Bus(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
    string& bran, string& mod, int new_year, string& loc, int new_price, int cap);
    Bus(int year, string &brand, string &model, string &color);
    friend ostream &operator<<(ostream &os, const Bus &obj);
    friend istream &operator>>(istream  &is, Bus &obj);
    ~Bus() override;
    Bus(const Bus& other);
    Bus(Bus&& other) noexcept;
    Bus& operator=(const Bus& other);
    Bus& operator=(Bus&& other) noexcept;
    bool if_exists(list<Bus> buses);


    [[nodiscard]] bool sort_passenger_capacity_h(int newcap) const;
    [[nodiscard]] bool sort_passenger_capacity_l(int newcap) const;
    [[maybe_unused]][[nodiscard]] int get_passenger_capacity() const;
    [[maybe_unused]]void set_passenger_capacity(int newcap);

    void get_vehicle() const override;
};


#endif //DIRECTORY_OF_CARS_BUS_H
