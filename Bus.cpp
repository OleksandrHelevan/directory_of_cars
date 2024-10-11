#include "Bus.h"
#include "fstream"
#include <algorithm>
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

Bus::Bus(int year, std::string &brand, std::string &model, std::string &color)
:Vehicle(year, brand, model, color){}

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

void Bus::get_vehicle() const {
    Vehicle::get_vehicle();
    cout<<"Passenger capacity: "<<passenger_capacity<<" persons"<<endl;
}

Bus::~Bus() noexcept {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)",ios_base::app);
    fout << "bus"<< " destructor"<<endl;
    fout.close();
}

int Bus::get_passenger_capacity() const{
    return passenger_capacity;
}

void Bus::set_passenger_capacity(int new_cap) {
    this->passenger_capacity = new_cap;
}

bool Bus::sort_passenger_capacity_h(int new_cap) const{
    return passenger_capacity >= new_cap;
}

bool Bus::sort_passenger_capacity_l(int new_cap) const{
    return passenger_capacity <= new_cap;
}

bool Bus::if_exists(const list<Bus> buses) {
    return std::any_of(buses.begin(), buses.end(), [this](const Bus &b) {
        return this->get_year() == b.get_year() &&
               this->get_model() == b.get_model() &&
               this->get_brand() == b.get_brand() &&
               this->get_color() == b.get_color();
    });
}

