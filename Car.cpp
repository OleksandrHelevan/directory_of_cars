#include "Car.h"
#include <fstream>

using namespace std;

Car::Car():Vehicle(), wheel_drive{"none"}, transmission{"none"} {}

Car::Car(Engine &new_engine, int weigh, double consumption, int new_mileage, string &col, string &bran,
         string &mod, int new_year, string &loc, int new_price, string &wh_dr, string &tran):
         Vehicle(new_engine,weigh,consumption,new_mileage,col,bran,mod,new_year, loc, new_price),
         wheel_drive{wh_dr},transmission{tran}{}

ostream &operator<<(ostream &os, const Car &obj){
    os<<static_cast <const Vehicle&>(obj);
    os<<obj.wheel_drive<<"\t"<<obj.transmission<<endl;
    return os;
}

istream &operator>>(istream &is, Car &obj){
    is>>static_cast <Vehicle&>(obj);
    is>>obj.wheel_drive>>obj.transmission;
    return is;
}

void Car::getVehicle() const  {
    Vehicle::getVehicle();
    cout<<"Wheel drive: "<<wheel_drive<<"\nTransmission: "<<transmission<<endl;
}
Car::Car(const Car& other) : Vehicle(other), wheel_drive{other.wheel_drive}, transmission{other.transmission} {}

Car::Car(Car&& other) noexcept : Vehicle(std::move(other)), wheel_drive{std::move(other.wheel_drive)}, transmission{std::move(other.transmission)} {}

Car& Car::operator=(const Car& other) {
    if (this == &other) {
        return *this;
    }
    Vehicle::operator=(other);
    wheel_drive = other.wheel_drive;
    transmission = other.transmission;
    return *this;
}

Car& Car::operator=(Car&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    Vehicle::operator=(std::move(other));
    wheel_drive = std::move(other.wheel_drive);
    transmission = std::move(other.transmission);
    return *this;
}

