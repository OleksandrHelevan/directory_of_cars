#include "Truck.h"
#include <fstream>
#include <list>
#include <algorithm>

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

Truck::Truck(int year, std::string &brand, std::string &model, std::string &color)
    :Vehicle(year, brand, model, color){}

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

void Truck::get_vehicle() const {
    Vehicle::get_vehicle();
    cout<<"Cargo capacity: "<<cargo_capacity<<" kg"<<endl;
}

void Truck::set_cargo_capacity(int new_cargo) {
    this->cargo_capacity=new_cargo;
}

int Truck::get_cargo_capacity() const {
    return cargo_capacity;
}

bool Truck::sort_cargo_capacity_h(int new_cap) const {
    return this->cargo_capacity >= new_cap;
}
bool Truck::sort_cargo_capacity_l(int new_cap) const {
    return this->cargo_capacity <= new_cap;
}

Truck::~Truck() noexcept {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)",ios_base::app);
    fout << "truck"<< " destructor"<<endl;
    fout.close();
}

bool Truck::if_exists(const list<Truck>& trucks) {
    return std::any_of(trucks.begin(), trucks.end(), [this](const Truck &t) {
        return this->get_year() == t.get_year() &&
               this->get_model() == t.get_model() &&
               this->get_brand() == t.get_brand() &&
               this->get_color() == t.get_color();
    });

}