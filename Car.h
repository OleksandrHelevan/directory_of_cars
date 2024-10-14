
#ifndef DIRECTORY_OF_CARS_CAR_H
#define DIRECTORY_OF_CARS_CAR_H

#include <iostream>
#include <list>
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle {
string wheel_drive;
string transmission;
public:
    Car();
    Car(int year, string &brand, string &model, string &color);
    Car(Engine& new_engine, int weigh, double consumption, int new_mileage, string& col,
        string& bran, string& mod, int new_year, string& loc, int new_price, string& wh_dr, string& tran);
    friend ostream &operator<<(ostream &os, const Car &obj);
    friend istream &operator>>(istream &is, Car &obj);
    ~Car() override;
    Car(const Car& other);
    Car(Car&& other) noexcept;
    Car& operator=(const Car& other);
    Car& operator=(Car&& other) noexcept;

    bool if_exists(const list<Car>& cars);
    void get_vehicle() const override;

    [[maybe_unused]] [[nodiscard]] string get_wheel_drive() const;
    [[maybe_unused]] [[nodiscard]] string get_transmission() const;

    void set_wheel_drive(string &new_wheel_drive);
    void set_transmission(string &new_transmission);

    bool sort_transmission(string& new_transmission);
    bool sort_wheel_drive(string& new_wheel_drive);
};


#endif //DIRECTORY_OF_CARS_CAR_H
