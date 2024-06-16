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