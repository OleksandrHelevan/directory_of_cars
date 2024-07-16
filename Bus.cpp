#include "Bus.h"
using namespace std;

Bus::Bus():Vehicle(),passenger_capacity{0} {}

Bus::Bus(Engine &new_engine, int weigh, double consumption, int new_mileage, string &col, string &bran,
        string &mod, int new_year, string &loc, int new_price, int cap):passenger_capacity{cap},
        Vehicle(new_engine,weigh,consumption,new_mileage,col,bran,mod,new_year, loc, new_price){}

ostream &operator<<(ostream &os, const Bus &obj){
    os<<static_cast <const Vehicle&>(obj);
    os<<obj.passenger_capacity<<endl;
    return os;
}
istream &operator>>(istream  &is, Bus &obj){
    is>>static_cast <Vehicle&>(obj);
    is>>obj.passenger_capacity;
    return is;
}

Bus::Bus(const Bus& other) : Vehicle(other), passenger_capacity{other.passenger_capacity} {}

Bus::Bus(Bus&& other) noexcept : Vehicle(std::move(other)), passenger_capacity{other.passenger_capacity} {}

Bus& Bus::operator=(const Bus& other) {
    if (this == &other) {
        return *this;
    }
    Vehicle::operator=(other);
    passenger_capacity = other.passenger_capacity;
    return *this;
}

Bus& Bus::operator=(Bus&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    Vehicle::operator=(std::move(other));
    passenger_capacity = other.passenger_capacity;
    return *this;
}

void Bus::getVehicle() const {
    Vehicle::getVehicle();
    cout<<"Passenger capacity: "<<passenger_capacity<<" persons";
}