#include "Bus.h"
#include "fstream"
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

Bus::~Bus() noexcept {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)",ios_base::app);
    fout << "bus"<< " destructor"<<endl;
    fout.close();
}

int Bus::getpassenger_capacity() const {
    return passenger_capacity;
}

void Bus::setpassenger_capacity(int newcap) {
    this->passenger_capacity = newcap;
}

bool Bus::sortpassenger_capacity_h(int newcap) const {
    return passenger_capacity >= newcap;
}

bool Bus::sortpassenger_capacity_l(int newcap) const {
    return passenger_capacity <= newcap;
}