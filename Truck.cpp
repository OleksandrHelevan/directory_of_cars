#include "Truck.h"

Truck::Truck():Vehicle(),cargo_capacity{0}{}

Truck::Truck(Engine &new_engine, int weigh, double consumption, int new_mileage, std::string &col, std::string &bran,
       std::string &mod, int new_year, std::string &loc, int new_price, int cargo) :cargo_capacity{cargo},
       Vehicle(new_engine,weigh,consumption,new_mileage,col,bran,mod,new_year, loc, new_price){}

ostream &operator<<(ostream &os, const Truck &obj){
    os<<static_cast<const Vehicle&>(obj);
    os<<obj.cargo_capacity<<endl;
    return os;
}

istream &operator>>(istream &is, Truck &obj){
    is>>static_cast<Vehicle&>(obj);
    is>>obj.cargo_capacity;
    return is;
}
Truck::Truck(const Truck& other) : Vehicle(other), cargo_capacity{other.cargo_capacity} {}

Truck::Truck(Truck&& other) noexcept : Vehicle(std::move(other)), cargo_capacity{other.cargo_capacity} {}

Truck& Truck::operator=(const Truck& other) {
    if (this == &other) {
        return *this;
    }
    Vehicle::operator=(other);
    cargo_capacity = other.cargo_capacity;
    return *this;
}

Truck& Truck::operator=(Truck&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    Vehicle::operator=(std::move(other));
    cargo_capacity = other.cargo_capacity;
    return *this;
}

void Truck::getVehicle() const {
    Vehicle::getVehicle();
    cout<<"Cargo capacity: "<<cargo_capacity<<" kg"<<endl;
}