#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle() :engine{Engine()},weight{0}, fuel_consumption{0},
        mileage{0}, color{"none"}, brand{"none"},model{"none"},
        year{0},location{"none"},price{0}{}

Vehicle::Vehicle(Engine& new_engine, int weigh, double consumption, int new_mileage, string &col,
                 string &bran, string &mod, int new_year, string &loc, int new_price) :engine{new_engine},
                 weight{weigh}, fuel_consumption{consumption}, mileage{new_mileage}, color{col},
                 brand {bran}, model{mod}, year{new_year}, location{loc}, price{new_price} {}

ostream &operator<<(ostream &os, const Vehicle &obj){
    os<<obj.brand<<"\t"<<obj.model<<"\t"<<obj.color<<"\t"<<obj.year<<"\t"<<obj.price<<"\t"<<obj.mileage<<"\t"
    <<obj.fuel_consumption<<"\t"<<obj.weight<<"\t"<<obj.location<<"\t"<<obj.engine;
    return os;
}

istream &operator>>(istream &is, Vehicle &obj){
    is>>obj.brand>>obj.model>>obj.color>>obj.year>>obj.price>>obj.mileage>>
    obj.fuel_consumption>>obj.weight>>obj.location>>obj.engine;
    return is;
}
