
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
    ~Car() override;
    Car(const Car& other);
    Car(Car&& other) noexcept;
    Car& operator=(const Car& other);
    Car& operator=(Car&& other) noexcept;

    [[maybe_unused]] [[nodiscard]] string getwheel_drive() const;
    [[maybe_unused]][[nodiscard]] string gettransmission() const;

    [[maybe_unused]]void setwheel_drive(string& newwheel_drive);
    [[maybe_unused]] void settransmission(string& newtransmission);

    bool sort_transmission(string& newtransmission);
    bool sort_wheel_drive(string& newwheel_drive);

};


#endif //DIRECTORY_OF_CARS_CAR_H
