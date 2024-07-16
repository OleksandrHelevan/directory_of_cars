#include "Vehicle.h"
using namespace std;
#include <iomanip>

Vehicle::Vehicle() :engine{Engine()},weight{0}, fuel_consumption{0},
        mileage{0}, color{"none"}, brand{"none"},model{"none"},
        year{0},location{"none"},price{0}{}

Vehicle::Vehicle(Engine& new_engine, int weigh, double consumption, int new_mileage, string &col,
                 string &bran, string &mod, int new_year, string &loc, int new_price) :engine{new_engine},
                 weight{weigh}, fuel_consumption{consumption}, mileage{new_mileage}, color{col},
                 brand {bran}, model{mod}, year{new_year}, location{loc}, price{new_price} {}

ostream &operator<<(ostream &os, const Vehicle &obj){
    os<<obj.brand<<"\t"<<obj.model<<"\t"<<obj.color<<"\t"<<obj.year<<"\t"<<obj.price<<"\t"<<obj.mileage<<
    "\t"<<obj.fuel_consumption<<"\t"<<obj.weight<<"\t"<<obj.location<<"\t"<<obj.engine;
    return os;
}

istream &operator>>(istream &is, Vehicle &obj){
    is>>obj.brand>>obj.model>>obj.color>>obj.year>>obj.price>>obj.mileage>>
    obj.fuel_consumption>>obj.weight>>obj.location>>obj.engine;
    return is;
}

bool Vehicle::sort_fuel(std::string &fuel1) {
    return engine.sort_fuel(fuel1);
}

bool Vehicle::sort_capacity_h(double cap) {
    return engine.sort_capacity_h(cap);
}

bool Vehicle::sort_capacity_l(double cap) {
    return engine.sort_capacity_l(cap);
}

bool Vehicle::sort_power_h(double pow) {
    return engine.sort_power_h(pow);
}

bool Vehicle::sort_power_l(double pow) {
    return engine.sort_power_l(pow);
}

bool Vehicle::sort_weight_h(int weigh) const {
    return this->weight >= weigh;
}

bool Vehicle::sort_weight_l(int weigh) const {
    return this->weight <= weigh;
}

bool Vehicle::sort_consumption_l(double cons) const {
    return this->fuel_consumption <= weight;
}

bool Vehicle::sort_consumption_h(double cons) const {
    return this->fuel_consumption >= weight;
}

bool Vehicle::sort_mileage_l(int mil) const {
    return this->mileage <= mil;
}

bool Vehicle::sort_mileage_h(int mil) const {
    return this->mileage >= mil;
}

bool Vehicle::sort_model(std::string &mod) {
    return this->model==mod;
}

bool Vehicle::sort_color(std::string &col) {
    return this->color == col;
}

bool Vehicle::sort_brand(std::string &bra) {
    return this->brand == bra;
}

bool Vehicle::sort_year_l(int yea) const {
    return this->year <= yea;
}

bool Vehicle::sort_year_h(int yea) const {
    return this->year >= yea;
}

bool Vehicle::sort_location(std::string &loc) {
    return this->location == loc;
}

bool Vehicle::sort_price_h(int pric) const {
    return this->price >= pric;
}

bool Vehicle::sort_price_l(int pric) const {
    return this->price <= pric;
}

void Vehicle::getVehicle() const{
    cout<<brand<<" "<<model<<" "<<color<<" "<<year<<endl<<
    "Price: "<<price<<" $\nMileage: "<<mileage<<" thousands of km"<<"\nFuel consumption: "
    <<fuel_consumption<<" liters/100km"<<"\nWeight: "<<weight<<" kg"<<"\nLocation: "<<location<<endl;
    engine.getEngine();
}

