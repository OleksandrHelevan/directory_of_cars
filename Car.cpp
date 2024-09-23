#include "Car.h"
#include <fstream>
#include <algorithm>

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

void Car::get_vehicle() const  {
    Vehicle::get_vehicle();
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

Car::~Car() noexcept {
    ofstream fout(R"(C:\Users\Admin\Desktop\directory_of_cars\database\information.txt)",ios_base::app);
    fout << "car destructor"<<endl;
    fout.close();
}

string Car::get_transmission() const {
    return transmission;
}

string Car::get_wheel_drive() const {
    return wheel_drive;
}

[[maybe_unused]] void Car::set_transmission(string &newtransmission) {
    this->transmission = newtransmission;
}

void Car::set_wheel_drive(string &newwheel_drive) {
    this->wheel_drive = newwheel_drive;
}

bool Car::sort_transmission(std::string &newtransmission) {
    return transmission == newtransmission;
}

bool Car::sort_wheel_drive(std::string &newwheel_drive) {
    return wheel_drive == newwheel_drive;
}
Car::Car(int year, std::string &brand, std::string &model, std::string &color)
    :Vehicle(year, brand,model,color){}

bool Car::if_exists(const list<Car>& cars) {
    return std::any_of(cars.begin(), cars.end(), [this](const Car &c) {
        return this->get_year() == c.get_year() &&
               this->get_model() == c.get_model() &&
               this->get_brand() == c.get_brand() &&
               this->get_color() == c.get_color();
    });

}